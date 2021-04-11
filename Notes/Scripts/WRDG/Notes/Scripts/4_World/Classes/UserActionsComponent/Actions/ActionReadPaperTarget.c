class ActionReadPaperTarget : ActionInteractBase
{
    override string GetText()
	{
		return "#read";
	}

	override bool IsInstant()
	{
		return true;
	}

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
		if (target && target.GetObject().IsInherited(WrittenNote))
			return true;

        return false;
    }

	override void OnStartClient(ActionData action_data)
	{
		if (GetGame().GetUIManager() && GetGame().GetUIManager().IsMenuOpen(MENU_NOTE))
            GetGame().GetUIManager().FindMenu(MENU_NOTE).Close();
	}

    override void OnStartServer(ActionData action_data)
	{
        ItemBase note = ItemBase.Cast(action_data.m_Target.GetObject());

        auto data = new Param2<string, int>(note.GetWrittenNoteData().GetNoteText(), note.GetWrittenNoteData().GetNoteColor());
        note.RPCSingleParam(ERPCs.RPC_READ_NOTE, data, true, action_data.m_Player.GetIdentity());
	}
}