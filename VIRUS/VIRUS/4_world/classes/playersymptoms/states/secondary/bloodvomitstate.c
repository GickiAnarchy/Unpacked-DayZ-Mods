class BloodVomitSymptom extends SymptomBase
{
	//just for the Symptom parameters set-up and gets called even if the Symptom doesn't execute, don't put any gameplay code in here
	override void OnInit()
	{
		m_SymptomType = SymptomTypes.SECONDARY;
		m_Priority = 200;
		m_ID = WTF69SymptomIDs.SYMPTOM_BLOODVOMIT;
		m_DestroyOnAnimFinish = true;
		m_SyncToClient = false;
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
	
		
		PlayAnimationFB(DayZPlayerConstants.CMD_ACTIONFB_VOMIT,DayZPlayerConstants.STANCEMASK_CROUCH, GetDuration() );
		/*
				int boneIdx = player.GetBoneIndexByName("Head");
			
				if( boneIdx != -1 )
				{
					if (!GetGame().IsServer())
					{
					BloodVomit eff = new BloodVomit();
					vector player_pos = player.GetPosition();
					eff.SetDecalOwner( player );
					SEffectManager.PlayInWorld( eff, "0 0 0" );
					Particle p = eff.GetParticle();
					p.SetOrientation("90 0 0");
					player.AddChild(p, boneIdx);
					}
				}
		
		
		*/	
	}

	//!only gets called once on an active Symptom that is being deactivated
	override void OnGetDeactivatedServer(PlayerBase player)
	{
		Debug.Log("OnGetDeactivated VomitSymptom called", "PlayerSymptom");
	}

	override void OnGetDeactivatedClient(PlayerBase player)
	{
		Debug.Log("OnGetDeactivated VomitSymptom called", "PlayerSymptom");
	}
	
	override SmptAnimMetaBase SpawnAnimMetaObject()
	{
		return new SmptAnimMetaFB();
	}
}