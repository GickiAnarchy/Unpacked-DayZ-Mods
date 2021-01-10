
class ActionTurnOnLights: ActionInteractBase
{
	void ActionTurnOnLights()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.OpenHood;
	}

	override string GetText()
	{
		return "#switch_on";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		OP_Lightbox ntarget = OP_Lightbox.Cast( target_object );
		if( ntarget )
		{
			if( ntarget.HasEnergyManager()  &&  ntarget.GetCompEM().CanSwitchOn() )
			{
				return true;
			}
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		if (targetObject)
		{
			EntityAI target_EAI = EntityAI.Cast( targetObject );
			target_EAI.GetCompEM().SwitchOn();
		}
	}
}
class ActionTurnOffLights: ActionInteractBase
{
	void ActionTurnOffLights()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.OpenHood;
	}

	override string GetText()
	{
		return "#switch_off";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();

		OP_Lightbox ntarget = OP_Lightbox.Cast( target_object );
		if( ntarget )
		{
			if( ntarget.HasEnergyManager()  &&  ntarget.GetCompEM().CanSwitchOff()  )
			{
				return true;
			}
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		if (targetObject)
		{
			EntityAI target_EAI = EntityAI.Cast( targetObject );
			target_EAI.GetCompEM().SwitchOff();
		}
	}
}