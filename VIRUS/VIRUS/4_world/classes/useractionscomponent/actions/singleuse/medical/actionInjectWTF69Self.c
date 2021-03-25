class ActionInjectWTF69Self: ActionInjectSelf
{	
	override void ApplyModifiers( ActionData action_data )
	{
		action_data.m_Player.InsertAgent(WTF69Agents.WTF69VIRUS,100);
	}
};