class ActionDialOPLockOnLockerCB : ActionContinuousBaseCB
{
	private const float REPEAT_AFTER_SEC = 0.5;
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(REPEAT_AFTER_SEC);
	}
}

class ActionDialOPLockOnLocker: ActionContinuousBase
{
	void ActionDialOPLockOnLocker()
	{
		m_CallbackClass = ActionDialOPLockOnLockerCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;		
	/*	m_MessageStartFail = "I have failed the tunning.";
		m_MessageStart = "I have started the tunning.";
		m_MessageFail = "I have failed the tunning.";
		m_MessageCancel = "I have stopped the tunning.";*/
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINotPresent;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
	}
	
	override bool HasProneException()
	{
		return true;
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

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}

	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		if ( targetObject )
		{
			Locker locker = Locker.Cast( targetObject );
			
			if ( locker && locker.IsLocked() && locker.GetAttachmentByType(OPLock) )
			{
				ConstructionActionData construction_action_data = player.GetConstructionActionData();
				construction_action_data.SetOPLock( locker.GetOPLock() );
					
				return true;		
			}
		}
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		//set dialed number
		ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
		OPLock op_lock =  construction_action_data.GetOPLock();
		op_lock.DialNextNumber();		

		//check for unlock state
		if ( !op_lock.IsLockedOnLocker() )
		{
			EntityAI target_entity = EntityAI.Cast( action_data.m_Target.GetObject() );
			op_lock.UnlockServer( action_data.m_Player, target_entity );
		}
	}
}