modded class WrittenNoteData
{
    protected int m_Color = 0;
    protected PluginNotesLog m_NotesLog;

    void WrittenNoteData(ItemBase parent)
    {
        if (GetGame() && GetGame().IsServer())
		{
			m_NotesLog = PluginNotesLog.Cast(GetPlugin(PluginNotesLog));
		}
    }

    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        ItemBase pen;
        ItemBase paper;

        auto param = new Param2<string, int>("", 0);

        switch (rpc_type)
        {
            case ERPCs.RPC_WRITE_NOTE:
            {
                GetGame().GetMission().SetNoteMenu(GetGame().GetUIManager().EnterScriptedMenu(MENU_NOTE, GetGame().GetUIManager().GetMenu()));

                if (GetNoteInfo(pen, paper))
                    GetGame().GetMission().GetNoteMenu().InitNoteWrite(paper, pen, string.Empty);

                break;
            }

            case ERPCs.RPC_WRITE_NOTE_CLIENT:
            {
                if (ctx.Read(param))
                {
                    if (IsOnlyWhitespace(param.param1))
                        break;

                    SetNoteText(param.param1);
                    SetNoteColor(param.param2);

                    if (GetNoteInfo(pen, paper))
                    {
                        PaperToNoteLambda lambda = new PaperToNoteLambda(paper, "WrittenNote", this);
                        PlayerBase player = GetPlayerByIdentity(sender);

                        if (player.GetItemInHands() == paper)
                            player.ServerReplaceItemInHandsWithNew(lambda);
                        else
                            player.ServerReplaceItemWithNew(lambda);
                    }

                    m_NotesLog.OnWriteNote(sender, param.param1);
                }

                break;
            }

            case ERPCs.RPC_READ_NOTE:
            {
                if (ctx.Read(param))
                {
                    SetNoteText(param.param1);
                    SetNoteColor(param.param2);

                    GetGame().GetMission().SetNoteMenu(GetGame().GetUIManager().EnterScriptedMenu(MENU_NOTE, GetGame().GetUIManager().GetMenu()));

                    string prefixed = string.Format("%1^%2", m_Color, m_SimpleText); // hack to set text color
                    GetGame().GetMission().GetNoteMenu().InitNoteRead(prefixed);
                }

                break;
            }
        }
    }

    int GetNoteColor()
	{
		return m_Color;
	}

	void SetNoteColor(int argbColor)
	{
		m_Color = argbColor;
	}

    protected PlayerBase GetPlayerByIdentity(PlayerIdentity identity)
    {
        int highBits, lowBits;

        if (!GetGame().IsMultiplayer())
            return GetGame().GetPlayer();

        if (identity == null)
            return null;

        GetGame().GetPlayerNetworkIDByIdentityID(identity.GetPlayerId(), lowBits, highBits);
        return PlayerBase.Cast(GetGame().GetObjectByNetworkId(lowBits, highBits));
    }

    protected bool IsOnlyWhitespace(string text)
    {
        bool isWhite = true; // https://media.giphy.com/media/4WHkXdDx8wjS0/giphy.gif
        TStringArray lines = new TStringArray();
        text.Split("\n", lines);

        foreach (string line : lines)
        {
            line = line.Trim();
            if (line != string.Empty)
            {
                isWhite = false;
                break;
            }
        }

        delete lines;
        return isWhite;
    }
}