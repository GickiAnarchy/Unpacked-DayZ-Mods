class ActionConsumeDrugs: ActionSingleUseBase
{

    PlayerBase player;

	void ActionConsumeDrugs()
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

	override string GetText()
	{
		return "#Consume";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		PsilocybeMushroom mushroom = PsilocybeMushroom.Cast(item);
		DP_CocaBag baggie = DP_CocaBag.Cast(item);
		
		if (mushroom || baggie) {
			return true;
		}else {
		 	return false;
		}	
	}

	override void OnExecuteServer( ActionData action_data )
	{
		DP_CocaBag baggie = DP_CocaBag.Cast(action_data.m_MainItem);
		if (baggie) {
		 	baggie.MakeHigh(action_data.m_Player);
		}
		
	}

	override void OnEndServer( ActionData action_data )
	{
		PlayerBase player = action_data.m_Player;
		ItemBase item = ItemBase.Cast(action_data.m_MainItem);
		string ItemName  = item.GetType();
		int i = ItemName.ToLower();
		
		if (action_data.m_WasExecuted && item )
		{
           		if (item.HasQuantity())
			{
				item.AddQuantity(-1,true);
			} else
			{
				item.Delete();
			}
			
			if (ItemName.IndexOf("mushroom") >= 0)
			{
				item.Delete();
			}
		}
	}

	/*override void OnEndClient( ActionData action_data )
	{
		PlayerBase player = action_data.m_Player;
		DP_CocaBag baggie = DP_CocaBag.Cast(action_data.m_MainItem);
		
		if (action_data.m_WasExecuted && baggie )
		{
           		if (baggie.HasQuantity())
			{
				baggie.AddQuantity(-1,true);
			}
			else
			{
				baggie.Delete();
			}
		}
	}*/

	override void OnExecuteClient(ActionData action_data)
    {	
    		PlayerBase player = action_data.m_Player;
		DP_CocaBag baggie = DP_CocaBag.Cast(action_data.m_MainItem);
		PsilocybeMushroom mushroom = PsilocybeMushroom.Cast(action_data.m_MainItem);
		
		if(baggie)
		{
            	player.CocaineEffectsTriggered();
        	}
		
		if(mushroom)
        	{
			player.MagicMushroomEffectsTriggered();
		}	
    	}
};
