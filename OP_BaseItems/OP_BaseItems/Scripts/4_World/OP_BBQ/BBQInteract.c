class ActionExtinguishBBQ : ActionTurnOffWhileOnGround
{
	override string GetText()
	{
		return "#extinguish";
	}
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		OP_Charc_BBQ target_entity = OP_Charc_BBQ.Cast( target.GetObject() );
		
		if ( player.IsAlive() && target_entity.HasEnergyManager()  &&  target_entity.GetCompEM().CanSwitchOff() && target_entity.IsOpen() )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

class ActionOpenCharBBQ: ActionInteractBase
{
    void ActionOpenBBQ()
    {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
        m_HUDCursorIcon = CursorIcons.OpenHood;
    }

    override string GetText()
    {
        return "#open";
    }

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
        Object target_object = target.GetObject();
        if ( target_object.IsItemBase() )
        {
            OP_Charc_BBQ ntarget = OP_Charc_BBQ.Cast( target_object );
            if( ntarget )
            {
                if( !ntarget.IsOpen() )
                {
                    return true;
                }
            }
        }
        return false;
    }

    override void OnExecuteServer( ActionData action_data )
    {
        OP_Charc_BBQ ntarget = OP_Charc_BBQ.Cast( action_data.m_Target.GetObject() );
        if ( ntarget )
        {
            ntarget.Open();
        }
    }
   
    override void OnEndServer( ActionData action_data )
    {
        Object target_object = action_data.m_Target.GetObject();
        OP_Charc_BBQ ntarget = OP_Charc_BBQ.Cast( target_object );
        if( ntarget )
        {
            ntarget.SoundSynchRemoteReset();
        }
    }
}

class ActionCloseCharBBQ: ActionInteractBase
{
	void ActionCloseBBQ()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}

	override string GetText()
	{
		return "#close";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		if ( target_object.IsItemBase() )
		{
			OP_Charc_BBQ ntarget = OP_Charc_BBQ.Cast( target_object );
			if ( ntarget )
			{
				if (ntarget.IsOpen() )
				{
					return true;
				}
			}
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		OP_Charc_BBQ ntarget = OP_Charc_BBQ.Cast( target_object );
		
		if( ntarget )
		{
			ntarget.Close();
		}
	}
	
	override void OnEndServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		OP_Charc_BBQ ntarget = OP_Charc_BBQ.Cast( target_object );
		if( ntarget )
		{
			ntarget.SoundSynchRemoteReset();
		}
	}
}
class LightBBQ extends RecipeBase	
{	
	override void Init()
	{
		m_Name = "#ignite";
		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 1;//animation length in relative time units
		m_Specialty = -0.01;// value > 0 for roughness, value < 0 for precision
		
		
		//conditions
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = -1;//-1 = disable check
		
		m_MinQuantityIngredient[0] = -1;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check
		
		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = -1;//-1 = disable check
		
		m_MinQuantityIngredient[1] = -1;//-1 = disable check
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check
		//----------------------------------------------------------------------------------------------------------------------
		
		//INGREDIENTS
		//ingredient 1
		InsertIngredient(0,"Torch");//you can insert multiple ingredients this way
		InsertIngredient(0,"Matchbox");
		InsertIngredient(0,"Roadflare");
		InsertIngredient(0,"HandDrillKit");
		InsertIngredient(0,"PetrolLighter");

		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = 0;// 0 = do nothing
		m_IngredientDestroy[0] = false;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		
		//ingredient 2
		InsertIngredient(1,"OP_Charc_BBQ");//you can insert multiple ingredients this way
		
		m_IngredientAddHealth[1] = 0;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = -1;// 0 = do nothing
		m_IngredientDestroy[1] = false;// false = do nothing
		m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		//----------------------------------------------------------------------------------------------------------------------
		
		//result1
		//AddResult("");//add results here

		m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
		m_ResultSetQuantity[0] = -1;//-1 = do nothing
		m_ResultSetHealth[0] = -1;//-1 = do nothing
		m_ResultInheritsHealth[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[0] = -2;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
		m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		OP_Charc_BBQ bbq = OP_Charc_BBQ.Cast(ingredients[1]);
		if ( !bbq.IsIgnited() && bbq.GetAttachmentByType( OP_Charcoal ) )
		{
			return true;
		}
		return false;
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		ItemBase item_source, item_target;
		
		OP_Charc_BBQ bbq = OP_Charc_BBQ.Cast(ingredients[1]);
		
		bbq.GetCompEM().SwitchOn();
	}
};
