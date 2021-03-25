class ActionInjectWTF69CureT: ActionInjectTarget
{
	void ActionInjectWTF69CureT()
	{
	
	}

	override void ApplyModifiers( ActionData action_data )
	{
		PlayerBase ntarget = PlayerBase.Cast( action_data.m_Target.GetObject() );
		ntarget.InsertAgent(WTF69Agents.WTF69VIRUS,-ntarget.GetSingleAgentCount(WTF69Agents.WTF69VIRUS));
		ntarget.m_ModifiersManager.DeactivateModifier(WTF69Modifiers.MDF_WTF69VIRUS);
		ntarget.AddHealth("GlobalHealth","Health", -20);
		ntarget.SetHealth("GlobalHealth","Shock", 0);
		ntarget.RemoveAgent(WTF69Agents.WTF69VIRUS);
	}
};