class WTF69Symptom extends SymptomBase
{
	bool CanEffectActivate = false;
	ref Timer effecttimer;
	//just for the Symptom parameters set-up and gets called even if the Symptom doesn't execute, don't put any gameplay code in here
	override void OnInit()
	{
		m_SymptomType = SymptomTypes.PRIMARY;
		m_Priority = 200;
		m_ID = WTF69SymptomIDs.SYMPTOM_WTF69;
		m_DestroyOnAnimFinish = true;
		m_SyncToClient = true;
		m_Duration = 5;
	}
	
	//!gets called every frame
	override void OnUpdateServer(PlayerBase player, float deltatime)
	{
		
	}

	override void OnUpdateClient(PlayerBase player, float deltatime)
	{
		
	
	
	}
	
	override bool CanActivate()
	{
		return ( m_Manager.GetCurrentCommandID() == DayZPlayerConstants.COMMANDID_MOVE || m_Manager.GetCurrentCommandID() == DayZPlayerConstants.COMMANDID_ACTION );
	}	
	
	//!gets called once on an Symptom which is being activated
	override void OnGetActivatedServer(PlayerBase player)
	{
		//timer.Run(10, this, "Destroy");
		
		Debug.Log("OnGetActivated VomitSymptom called", "PlayerSymptom");
		CanEffectActivate = true;
	
			
	}

	//!only gets called once on an active Symptom that is being deactivated
	override void OnGetDeactivatedServer(PlayerBase player)
	{
		Debug.Log("OnGetDeactivated VomitSymptom called", "PlayerSymptom");
		CanEffectActivate = false;
	}

	override void OnGetDeactivatedClient(PlayerBase player)
	{
		Debug.Log("OnGetDeactivated VomitSymptom called", "PlayerSymptom");
		CanEffectActivate = false;
	}
	
	override SmptAnimMetaBase SpawnAnimMetaObject()
	{
		return new SmptAnimMetaFB();
	}
	
}