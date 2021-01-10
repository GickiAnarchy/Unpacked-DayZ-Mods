class OP_Worktable extends ItemBase 
{
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
			
		SetLifetime(3888000);
	}
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
        AddAction(ActionPlaceObject);
    }        
} 