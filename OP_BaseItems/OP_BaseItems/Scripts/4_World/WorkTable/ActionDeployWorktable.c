/*class ActiondeployWorktableCB : ActionPlaceObjectCB 
{
    override void CreateActionComponent() {
        m_ActionData.m_ActionComponent = new CAContinuousTime(3); //Set your time here
    }   
}

class ActiondeployWorktable: ActionPlaceObject 
{        
    void ActionPlaceObject() 
    {
        m_CallbackClass        = ActiondeployWorktableCB; //Activating your callback with the custom time
    }
    override int GetType() 
    {
        return 999939;    //Make sure your is unique
    }
    override string GetText()
    {
        return "Place Worktable";
    }
}

