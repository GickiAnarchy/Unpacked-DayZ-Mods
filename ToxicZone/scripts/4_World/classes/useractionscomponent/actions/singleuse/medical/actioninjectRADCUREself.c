class ActionInjectRadCureSelf: ActionInjectSelf
{
	//override int GetType()
	//{
	//	return AT_INJECT_RADCURE_S;
	//}
		
	override void ApplyModifiers( ActionData action_data )
	{
		Print("ApplyModifiers");
		action_data.m_Player.m_ModifiersManager.DeactivateModifier(RadModifiers.MDF_RADIATIONSICKNESS);
		action_data.m_Player.SetHealth("","Shock",200);
		action_data.m_Player.AddHealth( "", "", -40);
		action_data.m_Player.RemoveAgent(RadAgents.RADIATIONSICKNESS);
		action_data.m_Player.IsIrradied=false;
		if(!action_data.m_Player.IsInside.TZStatut)return;
		action_data.m_Player.NBCSuitsLite();
	}
};