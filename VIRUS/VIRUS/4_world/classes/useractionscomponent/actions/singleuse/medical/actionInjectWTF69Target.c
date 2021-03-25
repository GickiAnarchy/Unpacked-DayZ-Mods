class ActionInjectWTF69Target: ActionInjectTarget
{
	void ActionInjectWTF69Target()
	{
	
	}
		
	override void ApplyModifiers( ActionData action_data )
	{
		PlayerBase ntarget = PlayerBase.Cast( action_data.m_Target.GetObject() );
		ntarget.InsertAgent(WTF69Agents.WTF69VIRUS,100);
	}
};