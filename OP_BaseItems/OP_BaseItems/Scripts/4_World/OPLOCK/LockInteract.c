class ActionDialOPLockCB : ActionContinuousBaseCB
{
	private const float REPEAT_AFTER_SEC = 0.5;
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(REPEAT_AFTER_SEC);
	}
}

class ActionDialOPLock: ActionContinuousBase
{
	void ActionDialOPLock()
	{
		m_CallbackClass = ActionDialOPLockCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNone;
		m_ConditionItem = new CCINonRuined;
	}
	
	override bool HasProneException()
	{
		return true;
	}

	override bool HasTarget()
	{
		return false;
	}

	override string GetText()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		string combination_lock_text;
		
		if ( player )
		{
			ConstructionActionData construction_action_data = player.GetConstructionActionData();
			combination_lock_text = construction_action_data.OPGetDialNumberText();
		}		
		
		return "#dial_combination_lock" + " " + combination_lock_text;
	}

	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		if ( item.IsInherited( OPLock ) )
		{
			ConstructionActionData construction_action_data = player.GetConstructionActionData();
			construction_action_data.SetOPLock( OPLock.Cast( item ) );
	
			return true;
		}
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		//set dialed number
		ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
		OPLock op_lock =  construction_action_data.GetOPLock();
		op_lock.DialNextNumber();
	}
}
class ActionNextOPLockDial: ActionSingleUseBase
{
	void ActionNextOPLockDial()
	{
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem		= new CCINonRuined;
		m_ConditionTarget 	= new CCTNone;
	}

	override bool HasTarget()
	{
		return false;
	}
	
	override bool IsInstant()
	{
		return true;
	}
	
	override bool RemoveForceTargetAfterUse()
	{
		return false;
	}
	
	override bool UseAcknowledgment()
	{
		return true;
	}	
	
	override string GetText()
	{
		return "#next_combination_lock_dial";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( item.IsInherited( OPLock ) )
		{
			ConstructionActionData construction_action_data = player.GetConstructionActionData();
			construction_action_data.SetOPLock( OPLock.Cast( item ) );

			return true;
		}
		
		return false;
	}

	override void Start( ActionData action_data )
	{
		super.Start( action_data );
		
		//set next dial
		OPLock combination_lock = OPLock.Cast( action_data.m_MainItem );
		if ( combination_lock )
		{
			combination_lock.SetNextDial();
		}
	}
}