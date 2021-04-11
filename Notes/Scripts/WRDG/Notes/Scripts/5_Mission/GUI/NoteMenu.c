modded class NoteMenu
{
	protected int m_Color;

    override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("WRDG/Notes/GUI/Layouts/NotesMenu.layout");
		m_edit = MultilineEditBoxWidget.Cast(layoutRoot.FindAnyWidget("NoteTextWidget"));

		return layoutRoot;
	}

    override void OnHide()
	{
        super.OnHide();

		SaveMessage();
	}

    override void InitNoteRead(string text = "")
	{
		m_IsWriting = false;

		if (m_edit)
		{
			m_edit.Enable(false);

			m_Color = text.Substring(0, text.IndexOf("^")).ToInt();
			string textNew = text.SubstringInverted(text, 0, text.IndexOf("^") + 1);

			if (m_Color == 0)
				m_Color = -16777216; // black

			m_edit.SetText(textNew);
			m_edit.SetColor(m_Color);
		}

		GetGame().GetUIManager().ShowCursor(false);
	}

	override void InitNoteWrite(EntityAI paper, EntityAI pen, string text = "")
	{
		m_IsWriting = true;

		if (m_edit)
		{
			m_edit.Enable(true);

			m_Paper = ItemBase.Cast(paper);
			m_Pen = pen;

			TIntArray temp = new TIntArray();
			m_Pen.ConfigGetIntArray("rgbColor", temp);
			m_Color = ARGB(255, temp[0], temp[1], temp[2]);

			m_edit.Show(true);
			m_edit.SetText(text);
			m_edit.SetColor(m_Color);
		}
	}

    void SaveMessage()
	{
		if (m_Paper && m_Pen && m_IsWriting)
		{
			string edit_text;
			m_edit.GetText(edit_text);

			auto data = new Param2<string, int>(edit_text, m_Color);
			m_Paper.RPCSingleParam(ERPCs.RPC_WRITE_NOTE_CLIENT, data, true);
		}
	}
}