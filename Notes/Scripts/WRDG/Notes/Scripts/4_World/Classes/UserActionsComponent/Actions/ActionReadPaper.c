modded class ActionReadPaperCB
{
    override void OnStateChange(int pOldState, int pCurrentState)
	{
		if (pCurrentState == STATE_NONE && (!GetGame().IsMultiplayer() || GetGame().IsClient()))
		{
			if (GetGame().GetUIManager() && GetGame().GetUIManager().IsMenuOpen(MENU_NOTE))
				GetGame().GetUIManager().FindMenu(MENU_NOTE).Close();
		}
		else if (pCurrentState == STATE_LOOP_LOOP && pOldState != STATE_LOOP_LOOP && (!GetGame().IsMultiplayer() || GetGame().IsServer()))
		{
			ItemBase note = ItemBase.Cast(m_ActionData.m_MainItem);

			auto data = new Param2<string, int>(note.GetWrittenNoteData().GetNoteText(), note.GetWrittenNoteData().GetNoteColor());
			note.RPCSingleParam(ERPCs.RPC_READ_NOTE, data, true, m_ActionData.m_Player.GetIdentity());
		}
	}
}

modded class ActionReadPaper
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!player.IsPlacingLocal())
			return true;

		return false;
	}
}