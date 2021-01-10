class ActionDestroyOPLockOnLockerCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT_DESTROY);
	}
};

class ActionDestroyOPLockOnLocker: ActionContinuousBase
{	
	void ActionDestroyOPLockOnLocker()
	{
		m_CallbackClass = ActionDestroyOPLockOnLockerCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_MEDIUM;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINonRuined;
	}
/*
	override int GetType()
	{
		return 2324243;
	}
*/
	override string GetText()
	{
		return "#destroy_combination_lock";
	}
/*	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}*/
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		string selection = target_object.GetActionComponentName( target.GetComponentIndex() );
		Locker locker = Locker.Cast( target_object );
		
		if ( locker && locker.IsLocked()/* && selection == "wall_interact"*/ )
		{
			return true;
		}
		OP_Shed shed = OP_Shed.Cast( target_object );
		
		if ( shed && shed.IsLocked()/* && selection == "wall_interact"*/ )
		{
			return true;
		}
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		Locker locker = Locker.Cast( action_data.m_Target.GetObject() );
		if ( locker )
		{
			OPLock op_lock = locker.GetOPLock();
			if ( op_lock )
			{
				op_lock.UnlockServer( action_data.m_Player, locker );
				op_lock.DecreaseHealth( op_lock.GetMaxHealth() );
			}
		}
		
		OP_Shed shed = OP_Shed.Cast( action_data.m_Target.GetObject() );
		if ( shed )
		{
			OPLock op_lockshed = shed.GetOPLock();
			if ( op_lockshed )
			{
				op_lockshed.UnlockServer( action_data.m_Player, shed );
				op_lockshed.DecreaseHealth( op_lockshed.GetMaxHealth() );
			}
		}
		action_data.m_MainItem.DecreaseHealth( UADamageApplied.SAW_LOCK, false );
		
		//soft skills
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
};
