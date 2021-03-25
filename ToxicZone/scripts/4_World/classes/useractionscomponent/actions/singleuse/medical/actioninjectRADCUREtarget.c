class ActionInjectRadCureTarget: ActionInjectTarget
{
	void ActionInjectRadCureTarget()
	{
		//m_Animation = "INJECTEPINENT";
		//m_MessageStart = "Player started injecting you RadCure.";
		//m_MessageSuccess = "Player finished injecting you RadCure.";
	}

	//override int GetType()
	//{
	//	return AT_INJECT_RADCURE_T;
	//}
		
	override void ApplyModifiers( ActionData action_data )
	{
		PlayerBase ntarget = PlayerBase.Cast( action_data.m_Target.GetObject() );
		ntarget.m_ModifiersManager.DeactivateModifier(RadModifiers.MDF_RADIATIONSICKNESS);
		ntarget.SetHealth("","Shock",200);
		ntarget.AddHealth( "", "", -40);
		ntarget.RemoveAgent(RadAgents.RADIATIONSICKNESS);
		ntarget.NBCSuitsLite();
		ntarget.IsIrradied=false;
	}
};