class ActionDeployOPBI: ActionDeployObject
{   
    void ActionDeployOPBI()
    {
        m_CallbackClass     = ActiondeployObjectCB;
        m_SpecialtyWeight   = UASoftSkillsWeight.PRECISE_LOW;
        m_CommandUID        = 0;
        m_FullBody          = true;
        m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
    }
        
    override void OnEndServer(ActionData action_data)
    {
        if (action_data.m_MainItem.IsKindOf("OP_ShedKit") /*|| action_data.m_MainItem.IsKindOf("OP_RaincatcherKit") */)
        {
            GetGame().ObjectDelete(action_data.m_MainItem);   
        }
        super.OnEndServer(action_data);
    }
}
            
    
