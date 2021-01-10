class ActionCustomClose: ActionInteractBase
{
	void ActionCustomClose()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.CloseDoors;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override string GetText()
	{
		return "#close";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;

		if(!IsInReach(player, target, MSP_UAConstants.MSP_DISTANCE_DEFAULT)) return false;

		string leverSelection = target.GetObject().GetActionComponentName(target.GetComponentIndex());
		if(leverSelection && leverSelection == "lever")
			return false;		
		
		Msp_Greenhouse greenhouse = Msp_Greenhouse.Cast(target.GetObject());
		string selection = target.GetObject().GetActionComponentName(target.GetComponentIndex());
		if(greenhouse && selection && selection == "doors1")
			return greenhouse.IsOpen();
		
		
		ItemBase building = ItemBase.Cast(target.GetObject());
		if(building)			
			return building.IsOpen();
			
		return false;
	}

	override void OnStartServer( ActionData action_data )
	{
		ItemBase building = ItemBase.Cast(action_data.m_Target.GetObject());
		if(building)		
		{	
			building.Close();
			return;
		}
		
		Msp_Greenhouse greenhouse = Msp_Greenhouse.Cast(action_data.m_Target.GetObject());
		if(greenhouse)		
			greenhouse.Close();
	}
};