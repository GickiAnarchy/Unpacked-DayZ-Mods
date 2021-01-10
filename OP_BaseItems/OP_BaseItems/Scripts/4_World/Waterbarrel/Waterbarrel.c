class Waterbarrelcomplete extends Bottle_Base
{
    void Waterbarrelcomplete() 
    {
    }

    override bool IsHeavyBehaviour() 
    {
        return true;
    }
    
    override bool IsTwoHandedBehaviour() 
    {
        return true;
    }
    
	override bool IsOpen()
	{
		return true;
	}

	override bool IsDeployable() 
    {
        return true;
    }   
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
			
		SetLifetime(3888000);
	}
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceWB);
        AddAction(ActionPlaceObject);
        AddAction(ActionDrinkWaterbarrelcomplete);
        AddAction(ActionDaetatchWaterbarrel);
		RemoveAction(ActionWashHandsItem);
        RemoveAction(ActionDrink);
    }
} 	
class BarrelFrame extends Inventory_Base
{

}
class Waterbarrel extends Bottle_Base 
{
    void Waterbarrel()
    {}
    
    override bool IsTwoHandedBehaviour() 
    {
        return true;
    }
    override void SetActions()
    {
        super.SetActions();
        RemoveAction(ActionDrink);
//		AddAction(ActionAttachWaterbarrel);
    }
}
class ActionDaetatchWaterbarrel: ActionInteractBase
{
	void ActionDaetatchWaterbarrel()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.OpenHood;
	}

	override string GetText()
	{
		return "Remove Waterbarrel";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		if ( target_object.IsItemBase() )
		{
			Waterbarrelcomplete ntarget = Waterbarrelcomplete.Cast( target_object );
			if( ntarget /*&& ntarget.GetQuantity() <= 500 */ )	
			{
				return true;
			}
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		Waterbarrelcomplete ntarget = Waterbarrelcomplete.Cast( target_object );
		if( ntarget )
		{
			vector pos = action_data.m_Player.GetPosition();
			GetGame().ObjectDelete(ntarget);
			ItemBase frame = ItemBase.Cast( GetGame().CreateObject("BarrelFrame", pos) );
			ItemBase box = ItemBase.Cast( GetGame().CreateObject("WaterBarrel", pos) );
		}
	}
}

class ActionDrinkWaterbarrelcomplete extends ActionInteractBase
{
	void ActionDrinkWaterbarrelcomplete()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DRINKSIP;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
	}

	override bool IsDrink()
	{
		return true;
	}
	
	override string GetText()
	{
		return "#drink";
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		if ( target_object.IsItemBase() )
		{
			Waterbarrelcomplete ntarget = Waterbarrelcomplete.Cast( target_object );
			if( ntarget && ntarget.GetQuantity() > 0 && ntarget.GetLiquidType() == LIQUID_WATER )	
			{
				return true;
			}
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();

		action_data.m_Player.Consume(NULL, UAQuantityConsumed.DRINK, EConsumeType.ENVIRO_WELL);

		Waterbarrelcomplete ntarget = Waterbarrelcomplete.Cast( target_object );
		if( ntarget )
		{
			ntarget.AddQuantity(-100);
		}
	}
}

class ActionTogglePlaceWB: ActionSingleUseBase
{

	void ActionTogglePlaceWB()
	{
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

	override bool HasTarget()
	{
		return false;
	}
	
	override bool IsLocal()
	{
		return true;
	}
	
	override bool IsInstant()
	{
		return true;
	}
	
	override bool RemoveForceTargetAfterUse()
	{
		return false;
	}

	override string GetText()
	{
		return "#toggle_placing";
	}
	
	override void Start( ActionData action_data ) //Setup on start of action
	{
		super.Start( action_data );
		action_data.m_Player.TogglePlacingLocal();
	}
};
/*
modded class PlayerBase 
{

    override void Init()
    {
        if ( !GetGame().IsServer() || !GetGame().IsMultiplayer() ) 
        {
			DayzPlayerItemBehaviorCfg 	heavyItemBehaviour = new DayzPlayerItemBehaviorCfg;
			heavyItemBehaviour.SetHeavyItems();
			GetDayZPlayerType().AddItemInHandsProfileIK("Waterbarrelcomplete", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,				"dz/anims/anm/player/ik/heavy/55galDrum.anm");
        }
        super.Init();	
    }
};