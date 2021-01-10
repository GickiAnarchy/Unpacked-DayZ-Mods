class ActionEmptyGardenpot: ActionInteractBase
{
	void ActionEmptyGardenpot()
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
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );	

		if ( target_entity && target_entity.GetInventory().AttachmentCount() == 0 )	
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
		return "Empty Box";
	}
	
	override void OnStartServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		ItemBase box;
		if ( targetObject && targetObject.IsKindOf( "Gardenpot" ) )
		{
		   	box = ItemBase.Cast( GetGame().CreateObject("GardenpotEmpty", targetObject.GetPosition() - Vector(0, 1, 0) ) ); // needed offset 
		   	box.SetOrientation(targetObject.GetOrientation() );
			GetGame().ObjectDelete( action_data.m_Target.GetObject() );
			
		}
		if ( targetObject && targetObject.IsKindOf( "Gardenbox" ) )
		{
			box = ItemBase.Cast( GetGame().CreateObject("GardenboxEmpty", targetObject.GetPosition() - Vector(0, 1, 0) ) );
			box.SetOrientation(targetObject.GetOrientation() );
			GetGame().ObjectDelete( action_data.m_Target.GetObject() );
		}
	}
}

class ActionDeployGardenpot: ActionInteractBase
{
	protected Object 			Gardenpot1;
	protected Object 			Gardenbox1;
	void ActionDeployGardenpot()
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
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );	

		if ( target_entity && target_entity.GetInventory().AttachmentCount() == 0 )	
		{
			return true;
		}
		
		return false;
	}

	override string GetText()
	{
		return "Fill With Dirt";
	}
	
	override void OnStartServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		ItemBase target_IB = ItemBase.Cast( targetObject );
		vector pos = target_IB.GetPosition();
		vector ori = target_IB.GetOrientation();
		if ( target_IB.IsKindOf( "GardenpotEmpty" ) )
		{
		
			Gardenpot1 = GetGame().CreateObject("Gardenpot", target_IB.GetPosition(), false );
			Gardenpot1.SetOrientation( ori );

			GetGame().ObjectDelete( action_data.m_Target.GetObject() );
		}
		if ( target_IB.IsKindOf( "GardenboxEmpty" ) )
		{
			Gardenpot1 = GetGame().CreateObject("GardenBox", target_IB.GetPosition(), false );
			Gardenpot1.SetOrientation( ori);

			GetGame().ObjectDelete( action_data.m_Target.GetObject() );
		}
	}
}

class CraftGardenbox extends RecipeBase
{	
	override void Init()
	{
		m_Name = "Craft Gardenbox"; //oink, create proper string
		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 2;//animation length in relative time units
		m_Specialty = -0.02;// value > 0 for roughness, value < 0 for precision
		
		
		//conditions
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = 3;//-1 = disable check
		
		m_MinQuantityIngredient[0] = 2;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check
		
		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = 3;//-1 = disable check
		
		m_MinQuantityIngredient[1] = -1;//-1 = disable check
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check
		//----------------------------------------------------------------------------------------------------------------------
		
		//INGREDIENTS
		//ingredient 1
		InsertIngredient(0,"WoodenPlank");//you can insert multiple ingredients this way
		
		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = -2;// 0 = do nothing
		m_IngredientDestroy[0] = false;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		
		//ingredient 2
		InsertIngredient(1,"Nail");//you can insert multiple ingredients this way
		
		m_IngredientAddHealth[1] = 0;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = -10;// 0 = do nothing
		m_IngredientDestroy[1] = false;// false = do nothing
		m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		//----------------------------------------------------------------------------------------------------------------------
		
		//result1
		AddResult("GardenboxEmpty");//add results here

		m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
		m_ResultSetQuantity[0] = -1;//-1 = do nothing
		m_ResultSetHealth[0] = -1;//-1 = do nothing
		m_ResultInheritsHealth[0] = 0;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[0] = -2;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
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
