modded class ActionDrink
{

	PlayerBase playera;
	float AmountConsumed;
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINotRuinedAndEmpty;
		m_ConditionTarget = new CCTSelf;
	}
	
	override string GetText()
	{
		return "drink";
	}
		
      void setInjuryStanceOne(float amount)
      {
		if (GetGame().IsClient()) {
			playera.setInjuredEffect(amount);
		} else {
			return;
		}
      }
	
	override protected void OnExecuteClient( ActionData action_data )
	{
		ItemBase item = ItemBase.Cast(action_data.m_MainItem);
		AmountConsumed = item.GetQuantity();
		super.OnExecuteClient(action_data);
	}

    override void OnEndClient( ActionData action_data )
    {

        super.OnEndClient(action_data);
	  ItemBase item = ItemBase.Cast(action_data.m_MainItem);
	  if (item)
	  {	
		  string ItemName  = item.GetType();
		  int i = ItemName.ToLower();	
	
	        playera = action_data.m_Player;
	        //Print("[DEBUG] OnSwitchOn called for vodka..");
	
	        // Giving effects for vodka consumption
	        if (ItemName.IndexOf("vodka") >= 0 || ItemName.IndexOf("alcohol") >= 0 || ItemName.IndexOf("alc_") >= 0 || ItemName.IndexOf("beer") >= 0 || ItemName.IndexOf("gin") >= 0 || ItemName.IndexOf("rum") >= 0  || ItemName.IndexOf("whiskey") >= 0)
	        {
	            // Give player injured emote effect while drunk.
			setInjuryStanceOne(AmountConsumed - item.GetQuantity());
	        }
	  }	
    }
};