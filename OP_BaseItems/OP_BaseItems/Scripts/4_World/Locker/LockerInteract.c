class ActionOpenLocker: ActionInteractBase
{
    void ActionOpenLocker()
    {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
        m_HUDCursorIcon = CursorIcons.OpenHood;
    }

    override string GetText()
    {
        return "#open";
    }

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
        Object target_object = target.GetObject();
        if ( target_object.IsItemBase() )
        {
            Locker locker = Locker.Cast( target_object );
            if( locker )
            {
                if( !locker.IsLocked() && !locker.IsOpen() )
                {
                    return true;
                }
            }
        }
        return false;
    }

    override void OnExecuteServer( ActionData action_data )
    {
        Locker locker = Locker.Cast( action_data.m_Target.GetObject() );
        if ( locker )
        {
            locker.Open();
        }
        if( locker && locker.FindAttachmentBySlotName( "tripWireAttachment" ) )
        {
            locker.Open();
            Grenade_Base gbase = locker.GetGbase();
            gbase.PopLockandDropit(action_data.m_Player, locker); 
             //ActivateImmediate() for quick boom
        }
    }
  	override void OnStartClient( ActionData action_data )
	{
        Locker locker = Locker.Cast( action_data.m_Target.GetObject() );

        if( locker && locker.FindAttachmentBySlotName( "tripWireAttachment" ) )
        {
			if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
				SEffectManager.PlaySound("Grenade_unpin_SoundSet", locker.GetPosition() );
		}
	}
   
    override void OnEndServer( ActionData action_data )
    {
        Object target_object = action_data.m_Target.GetObject();
        Locker ntarget = Locker.Cast( target_object );
        if( ntarget )
        {
            ntarget.SoundSynchRemoteReset();
        }
    }
}
class ActionCloseLocker: ActionInteractBase
{
	void ActionCloseLocker()
	{
//		m_MessageSuccess = "I have closed it.";
		//m_Animation = "close";
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}

	override string GetText()
	{
		return "#close";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		if ( target_object.IsItemBase() )
		{
			Locker ntarget = Locker.Cast( target_object );
			if( ntarget )
			{
				if (/* !ntarget.IsLocked() &&*/ ntarget.IsOpen() )
				{
					return true;
				}
			}
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		Locker ntarget = Locker.Cast( target_object );
		
		if( ntarget )
		{
			ntarget.Close();
		}
	}
	
	override void OnEndServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		Locker ntarget = Locker.Cast( target_object );
		if( ntarget )
		{
			ntarget.SoundSynchRemoteReset();
		}
	}
}