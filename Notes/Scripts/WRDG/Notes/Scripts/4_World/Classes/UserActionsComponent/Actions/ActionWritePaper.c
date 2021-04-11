modded class ActionWritePaperCB
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
			ItemBase paper_item;
			if (m_ActionData.m_MainItem.ConfigIsExisting("rgbColor"))
			{
				paper_item = ItemBase.Cast(m_ActionData.m_Target.GetObject());
			}
			else
			{
				paper_item = ItemBase.Cast(m_ActionData.m_MainItem);
			}
			auto data = new Param2<string, int>("", 0);
			paper_item.RPCSingleParam(ERPCs.RPC_WRITE_NOTE, data, true, m_ActionData.m_Player.GetIdentity());
		}
	}
}

modded class ActionWritePaper
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if ((item && item.ConfigIsExisting("writingColor") && target.GetObject() && Paper.Cast(target.GetObject())) && !target.GetObject().IsInherited(WrittenNote) || (target.GetObject() && target.GetObject().ConfigIsExisting("writingColor") && item && Paper.Cast(item) && !item.IsInherited(WrittenNote)))
			return true;

		return false;
	}

    override void OnStartClient(ActionData action_data)
	{
		if (action_data.m_Target.GetObject().ConfigIsExisting("rgbColor"))
			action_data.m_MainItem.GetWrittenNoteData().InitNoteInfo(ItemBase.Cast(action_data.m_Target.GetObject()), action_data.m_MainItem);

		else
			ItemBase.Cast(action_data.m_Target.GetObject()).GetWrittenNoteData().InitNoteInfo(action_data.m_MainItem, ItemBase.Cast(action_data.m_Target.GetObject()));
	}

	override void OnStartServer(ActionData action_data)
	{
		if (action_data.m_Target.GetObject().ConfigIsExisting("rgbColor"))
			action_data.m_MainItem.GetWrittenNoteData().InitNoteInfo(ItemBase.Cast(action_data.m_Target.GetObject()), action_data.m_MainItem);

		else
			ItemBase.Cast(action_data.m_Target.GetObject()).GetWrittenNoteData().InitNoteInfo(action_data.m_MainItem, ItemBase.Cast(action_data.m_Target.GetObject()));
	}
}