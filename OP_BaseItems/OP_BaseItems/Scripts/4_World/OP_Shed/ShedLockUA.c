class ActionNextOPLockDialOnShed: ActionInteractBase
{
    void ActionNextOPLockDialOnShed()
    {
    }

    override void CreateConditionComponents()  
    {
        m_ConditionItem = new CCINone;
        m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
    }
/*
    override int GetType()
    {
        return AT_NEXT_COMBINATION_LOCK_DIAL_ON_TARGET;
    }*/

    override string GetText()
    {
        return "#next_combination_lock_dial";
    }

    override bool IsInstant()
    {
        return true;
    }

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {   
        Object targetObject = target.GetObject();
        if ( targetObject )
        {
            OP_Shed shed = OP_Shed.Cast( targetObject );
            
            if ( shed && shed.IsLocked() && !player.GetItemInHands() && shed.GetAttachmentByType(OPLock) )
            {
                string selection = shed.GetActionComponentName( target.GetComponentIndex() );
                
                if ( selection == "wall_interact" || selection == "doors1"|| selection == "doors2" )
                {
                    ConstructionActionData construction_action_data = player.GetConstructionActionData();
                    construction_action_data.SetOPLock( shed.GetOPLock() );
                    
                    return true;
                }
            }
        }
        
        return false;
    }
    
    override void Start( ActionData action_data )
    {
        super.Start( action_data );
        
        //set next dial
        ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
        OPLock op_lock = construction_action_data.GetOPLock();
        if ( op_lock )
        {
            op_lock.SetNextDial();
        }
    }
}
class ActionDialOPLockOnShedCB : ActionContinuousBaseCB
{
    private const float REPEAT_AFTER_SEC = 0.5;
    
    override void CreateActionComponent()
    {
        m_ActionData.m_ActionComponent = new CAContinuousRepeat(REPEAT_AFTER_SEC);
    }
}
class ActionDialOPLockOnShed: ActionContinuousBase
{
    void ActionDialOPLockOnShed()
    {
        m_CallbackClass = ActionDialOPLockOnShedCB;
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
        m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;     
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
            OP_Shed shed = OP_Shed.Cast( targetObject );
            
            if ( shed && shed.IsLocked() && shed.GetAttachmentByType(OPLock) )
            {
                string selection = shed.GetActionComponentName( target.GetComponentIndex() );
                
                if ( selection == "wall_interact" || selection == "doors1"|| selection == "doors2" ) 
                {
                    ConstructionActionData construction_action_data = player.GetConstructionActionData();
                    construction_action_data.SetOPLock( shed.GetOPLock() );
                    
                    return true;
                }
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
        if ( !op_lock.IsLockedOnShed() )
        {
            EntityAI target_entity = EntityAI.Cast( action_data.m_Target.GetObject() );
            op_lock.UnlockServer( action_data.m_Player, target_entity );
        }
    }
}