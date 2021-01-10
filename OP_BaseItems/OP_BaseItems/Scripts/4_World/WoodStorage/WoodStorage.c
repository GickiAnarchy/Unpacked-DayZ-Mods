class WoodStorage extends ItemBase
{
    void WoodStorage() 
    {
    }

    override bool CanPutIntoHands(EntityAI parent) 
    {
       if( super.CanPutIntoHands( parent ) ) 
        {
            return (GetInventory().AttachmentCount() == 0);
        }
       return false;
    }
    
    override bool IsHeavyBehaviour() 
    {
        return true;
    }
    override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
    {
        super.OnPlacementComplete( player, position, orientation );
            
        SetLifetime(3888000);
    }
    override bool IsTwoHandedBehaviour() 
    {
        return true;
    }
    
    override bool IsDeployable() 
    {
        return true;
    }        
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
        AddAction(ActionPlaceObject);
    } 
} 