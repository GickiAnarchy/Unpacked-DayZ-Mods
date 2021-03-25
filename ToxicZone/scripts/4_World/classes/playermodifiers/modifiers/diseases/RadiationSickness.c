class RadiationSicknessMdfr: ModifierBase
{
	static const int RAD_AGENT_THRESHOLD_ACTIVATE = 100;
	static const int RAD_AGENT_THRESHOLD_DEACTIVATE = 0;
	float Toxic_Damage = 5;
	float chanceVomit = 0.1;
	float chanceCough = 0.2;
	bool m_IsVomiting;
	bool m_IsCoughing;

	override void Init()
	{
		m_TrackActivatedTime 	= false;
		m_ID 					= RadModifiers.MDF_RADIATIONSICKNESS;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_ACTIVE;
	}

	override protected bool ActivateCondition(PlayerBase player)
	{
		if(player.GetSingleAgentCount(RadAgents.RADIATIONSICKNESS) > RAD_AGENT_THRESHOLD_ACTIVATE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	override protected void OnActivate(PlayerBase player)
	{
		m_IsVomiting = false;
		m_IsCoughing = false;
		//if( player.m_NotifiersManager ) player.m_NotifiersManager.AttachByType(eNotifiers.NTF_SICK);
		//player.DZ_SetRadSick(true);
		player.IncreaseDiseaseCount();
		player.IsIrradied = true;
		player.IsUnprotected = false;
		Toxic_Damage = player.ToxicBloodLoss;
	}

	override protected void OnDeactivate(PlayerBase player)
	{
		//player.DZ_SetRadSick(false);
		player.DecreaseDiseaseCount();
		player.IsIrradied = false;
	}

	override protected bool DeactivateCondition(PlayerBase player)
	{
		if(player.GetSingleAgentCount(RadAgents.RADIATIONSICKNESS) < RAD_AGENT_THRESHOLD_DEACTIVATE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	override protected void OnTick(PlayerBase player, float deltaT)
	{
		float currenthealth = player.GetHealth("GlobalHealth", "Blood");
		player.SetHealth("GlobalHealth", "Blood" ,  currenthealth - Toxic_Damage );
		if(!m_IsCoughing && chanceCough > Math.RandomFloatInclusive(0,1))
		{
			SymptomBase symptom1 = player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
			m_IsCoughing = true;
		}
		if(!m_IsVomiting && chanceVomit > Math.RandomFloatInclusive(0,1))
		{
			SymptomBase symptom2 = player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
			m_IsVomiting = true;
		}
	}
};
