class ActionInjectWTF69CureSelf: ActionInjectSelf
{

	override void ApplyModifiers( ActionData action_data )
	{
		PlayerBase player = action_data.m_Player;
		
		player.InsertAgent(WTF69Agents.WTF69VIRUS,-player.GetSingleAgentCount(WTF69Agents.WTF69VIRUS));
		player.m_ModifiersManager.DeactivateModifier(WTF69Modifiers.MDF_WTF69VIRUS);
		player.AddHealth("GlobalHealth","Health", -20);
		player.SetHealth("GlobalHealth","Shock", 0);
		player.RemoveAgent(WTF69Agents.WTF69VIRUS);
	}

};