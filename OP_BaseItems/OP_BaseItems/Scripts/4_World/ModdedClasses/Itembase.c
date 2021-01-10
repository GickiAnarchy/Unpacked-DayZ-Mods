modded class ItemBase
{
    bool CanMakeDirtmound()
    {
        return false;
    }
    bool CanBuildFrame()
    {
        return false;
    }
}

modded class FieldShovel
{
    override bool CanMakeDirtmound()
    {
        return true;
    }
    override bool CanMakeGardenplot()
    {
        return false;
    }
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionDigDirtmound);
        RemoveAction(ActionDigGardenPlot);
        RemoveAction(ActionDigGardenPlot);
    }
}
modded class Pliers
{
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionDestroyGbaseOnLocker);
    }
}

modded class Hacksaw
{
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionDestroyOPLockOnLocker);
    }
}
