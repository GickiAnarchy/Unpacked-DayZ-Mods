ref Timer 					RPRZ_AnalyseVirus;

class ActionAnalyseVirus: ActionInteractBase
{	
	vector position;
	
	void ActionAnalyseVirus()
	{
		
	}
	
	override string GetText()
	{
		return "Analyse virus";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		cure_microscope curemicroscope = cure_microscope.Cast( targetObject );
		if ( curemicroscope  &&  curemicroscope.HasBloodBagFull()  &&  curemicroscope.Hasbrain_Mung()  &&  curemicroscope.HasCure_Petridish()  )
		{
				return true;
		}
		return false;
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		vector targetObjectPos = targetObject.GetPosition();
		position = targetObjectPos;
		if ( targetObject )
		{
			EntityAI target_EAI = EntityAI.Cast( targetObject );
			
			if ( !RPRZ_AnalyseVirus )
			{
				RPRZ_AnalyseVirus = 			new Timer( CALL_CATEGORY_SYSTEM );
			}
			
			if ( !RPRZ_AnalyseVirus.IsRunning() ) // Makes sure the timer is NOT running already
			{
				RPRZ_AnalyseVirus.Run(0.1, targetObject, "AnalyseVirus", NULL, false);
			}
		}
			
	}
};