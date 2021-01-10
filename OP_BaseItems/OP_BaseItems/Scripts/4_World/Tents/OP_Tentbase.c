
class OP_ImpTent extends TentBase
{
	void OP_ImpTent()
	{			
		m_ShowAnimationsWhenPitched.Insert( "Body" );
		m_ShowAnimationsWhenPitched.Insert( "Pack" );

		m_ShowAnimationsWhenPacked.Insert( "Inventory");
	}
		
	override void EEInit()
	{		
		super.EEInit();
	}
	
	override void OnItemLocationChanged(EntityAI old_owner, EntityAI new_owner)
	{		
		super.OnItemLocationChanged(old_owner, new_owner);
	}
	
	override string GetSoundOpen()
	{
		return "MediumTent_Door_Open_SoundSet";
	}
	
	override string GetSoundClose()
	{
		return "MediumTent_Door_Close_SoundSet";
	}
	
	override bool HasClutterCutter()
	{
		return true;
	}
	
	override string GetClutterCutter()
	{
		return "MediumTentClutterCutter";
	}
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
		
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
			
		PlayerBase pb = PlayerBase.Cast( player );
		SetLifetime(3888000);
		if ( GetGame().IsServer() )
		{
			if ( !m_ClutterCutter )
			{
				m_ClutterCutter = GetGame().CreateObject( "MediumTentClutterCutter", pb.GetLocalProjectionPosition(), false );
				m_ClutterCutter.SetOrientation( pb.GetLocalProjectionOrientation() );	
			}
		}
	}
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionPackTentOP);
        RemoveAction(ActionPackTent);
        RemoveAction(ActionToggleTentOpen);	
    }	
		
	override string GetDeploySoundset()
	{
		return "placeMediumTent_SoundSet";
	}
	
	override string GetLoopDeploySoundset()
	{
		return "mediumtent_deploy_SoundSet";
	}	
};
class OP_BannerMount extends TentBase
{
	void OP_BannerMount()
	{			
		m_ShowAnimationsWhenPitched.Insert( "Body" );
		m_ShowAnimationsWhenPitched.Insert( "Pack" );

		m_ShowAnimationsWhenPacked.Insert( "Inventory" );
	}
		
	override void EEInit()
	{		
		super.EEInit();
	}
	
	override void OnItemLocationChanged(EntityAI old_owner, EntityAI new_owner)
	{		
		super.OnItemLocationChanged(old_owner, new_owner);
	}
	
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		
		if ( item.IsKindOf ( "Banner_ColorBase" ) ) 
		{
			SetAnimationPhase( "Banner", 0 );
			Banner_Colorbase banner_colorbase = Banner_Colorbase.Cast( item );
			banner_colorbase.ShowAttached();
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
				
		if ( item.IsKindOf ( "Banner_ColorBase" ) ) 
		{
			SetAnimationPhase( "Banner", 1 );
			Banner_Colorbase banner_colorbase = Banner_Colorbase.Cast( item );
			banner_colorbase.ShowInventory();
		}
	}
	
	override bool HasClutterCutter()
	{
		return true;
	}
	
	override string GetClutterCutter()
	{
		return "MediumTentClutterCutter";
	}
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
		
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
		
		PlayerBase pb = PlayerBase.Cast( player );
		SetLifetime(3888000);		
		if ( GetGame().IsServer() )
		{
			if ( !m_ClutterCutter )
			{
				m_ClutterCutter = GetGame().CreateObject( "MediumTentClutterCutter", pb.GetLocalProjectionPosition(), false );	
				m_ClutterCutter.SetOrientation( pb.GetLocalProjectionOrientation() );
			}
		}	
	}
		
	override string GetDeploySoundset()
	{
		return "placeMediumTent_SoundSet";
	}
	
	override string GetLoopDeploySoundset()
	{
		return "mediumtent_deploy_SoundSet";
	}	
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionPackBanner);
        RemoveAction(ActionPackTent);
        RemoveAction(ActionToggleTentOpen);	
    }
};
class ActionPackTentOP: ActionInteractBase
{
	void ActionPackTentOP()
	{
	//	m_MessageSuccess = "I've packed tent.";
	//	m_MessageFail = "I cannot pack tent.";
		//m_Animation = "open";
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTParent(10);
	}/*
	
	override int GetType()
	{
		return 1044124;
	}*/

	override string GetText()
	{
		return "#pack_tent";
	}

	override bool IsUsingProxies()
	{
		return true;
	}
	override bool HasProgress()
	{
		return false;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		Object targetParent = target.GetParent();
		
		if ( player && targetObject && targetParent )
		{
			float max_action_distance = 1; //m_MaximalActionDistance;
			if ( targetParent.IsInherited(OP_ImpTent) ) 
			{
				max_action_distance = 4.0;
			}
			else if ( targetParent.IsInherited(OP_SleepingBagBlue) ) 
			{
				max_action_distance = 4.0;
			}
			else if ( targetParent.IsInherited(OP_SleepingBagCamo) ) 
			{
				max_action_distance = 4.0;
			}
			else if ( targetParent.IsInherited(OP_SleepingBagGrey) ) 
			{
				max_action_distance = 4.0;
			}

			float distance = Math.AbsInt(vector.Distance(targetParent.GetPosition(),player.GetPosition()));
			if (  distance <= max_action_distance )	
			{
				TentBase tent = TentBase.Cast( targetParent );
				if ( tent.CanBePacked() )
				{
					array<string> selections = new array<string>;
					targetObject.GetActionComponentNameList(target.GetComponentIndex(), selections);
					
					for ( int s = 0; s < selections.Count(); s++ )
					{					
						if ( selections[s] == "pack" )
						{
							return true;
						}
					}
				}
			}
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		Object targetParent = action_data.m_Target.GetParent();
		vector target_object_pos = targetObject.GetPosition();
		
		if ( targetParent && targetParent.IsInherited(TentBase) ) 
		{
			array<string> selections = new array<string>;
			targetObject.GetActionComponentNameList(action_data.m_Target.GetComponentIndex(), selections);
			
			TentBase tent = TentBase.Cast( targetParent );
			tent.Pack( true );
			tent.SetPosition( targetParent.CoordToParent( target_object_pos ) );
			tent.SetOrientation( action_data.m_Player.GetOrientation() );
			tent.PlaceOnSurface();
		}
	}
};

class CraftImpTentKit extends RecipeBase
{	
	override void Init()
	{
		m_Name = "Craft Improvised Tentkit";
		m_IsInstaRecipe = true;//should this recipe be performed instantly without animation
		m_AnimationLength = 0;//animation length in relative time units
		m_Specialty = -0.02;// value > 0 for roughness, value < 0 for precision
		
		
		//conditions
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = 3;//-1 = disable check
		
		m_MinQuantityIngredient[0] = -1;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check
		
		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = 3;//-1 = disable check
		
		m_MinQuantityIngredient[1] = -1;//-1 = disable check
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check
		//----------------------------------------------------------------------------------------------------------------------
		
		//INGREDIENTS
		//ingredient 1
		InsertIngredient(0,"BurlapSack");//you can insert multiple ingredients this way
		
		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = 0;// 0 = do nothing
		m_IngredientDestroy[0] = true;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		
		//ingredient 2
		InsertIngredient(1,"LongWoodenStick");//you can insert multiple ingredients this way
		//InsertIngredient(1,"ImprovisedRope");//you can insert multiple ingredients this way
		
		m_IngredientAddHealth[1] = 0;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = 0;// 0 = do nothing
		m_IngredientDestroy[1] = true;// false = do nothing
		m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		//----------------------------------------------------------------------------------------------------------------------
		
		//result1
		AddResult("OP_ImpTent");//add results here

		m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
		m_ResultSetQuantity[0] = -1;//-1 = do nothing
		m_ResultSetHealth[0] = -1;//-1 = do nothing
		m_ResultInheritsHealth[0] = -2;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[0] = -1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
		m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		return true;
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		Debug.Log("Recipe Do method called","recipes");
	}
};

class ActionPackBanner: ActionInteractBase 
{
	void ActionPackBanner()
	{
		//m_MessageSuccess = "";
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		OP_BannerMount target_entity = OP_BannerMount.Cast( target.GetObject() );	

		if ( target_entity && target_entity.CanBePacked() )	
		{
			return true;
		}
		
		return false;
	}

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}/*
/*
	override int GetType()
	{
		return 19323234;
	}
*/
	override string GetText()
	{
		return "#pack_tent";
	}
	
	override void OnStartServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		if ( targetObject && targetObject.IsKindOf( "OP_BannerMount" ) )
		{
			GetGame().ObjectDelete( action_data.m_Target.GetObject() );
			vector pos = action_data.m_Player.GetPosition();
			ItemBase box = ItemBase.Cast( GetGame().CreateObject("OP_BannerMount", pos) );
		}
	}
}