class ActionOpenShed: ActionInteractBase
{
    void ActionOpenShed()
    {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
        m_HUDCursorIcon = CursorIcons.OpenDoors;
    }

    override void CreateConditionComponents()  
    {
        m_ConditionItem = new CCINone;
        m_ConditionTarget = new CCTNone;
    }

    override string GetText()
    {
        return "#open";
    }

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
        Object targetObject = target.GetObject();
        if ( targetObject )
        {
            OP_Shed shed = OP_Shed.Cast( targetObject );
            
            if ( shed && shed.CanOpenShed() )
            {
                return true;
            }
        }
        
        return false;
    }
    
    override void OnStartServer( ActionData action_data )
    {
        OP_Shed shed = OP_Shed.Cast( action_data.m_Target.GetObject() );
        shed.OpenFence();
    }
}
class ActionCloseShed: ActionInteractBase
{
    void ActionCloseShed()
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
        Object targetObject = target.GetObject();
        if ( targetObject  )
        {
            OP_Shed shed = OP_Shed.Cast( targetObject );
            
            if ( shed && shed.CanCloseShed() )
            {
                string selection = shed.GetActionComponentName( target.GetComponentIndex() );
                
                if ( selection == "wall_interact" || selection == "doors1"|| selection == "doors2" ) 
                {                    
                    return true;
                }
             //   return true; //
            }
        }
        
        return false;
    }

    override void OnStartServer( ActionData action_data )
    {
        OP_Shed shed = OP_Shed.Cast( action_data.m_Target.GetObject() );
        shed.CloseFence();
    }
}