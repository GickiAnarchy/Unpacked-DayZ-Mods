/*
protected static const string JSON_PATH_DIRECTORY_SETTINGS = "$profile:DL28\\Settings\\";
protected static const string JSON_PATH_SETTINGS = "$profile:DL28\\Settings\\Settings.json";


class Settings28DL
{	
		
	float WTF69_Damage = 300.0; // blood damage per tick
	
	static ref Settings28DL Load()
	    {
		ref Settings28DL settings = new Settings28DL();
		
		if ( !FileExist( JSON_PATH_DIRECTORY_SETTINGS ) )
		{
			MakeDirectory( JSON_PATH_DIRECTORY_SETTINGS );
		}
		
		if ( !FileExist( JSON_PATH_SETTINGS ) )
		{
			JsonFileLoader<Settings28DL>.JsonSaveFile(JSON_PATH_SETTINGS, settings );
		}
		
		JsonFileLoader<Settings28DL>.JsonLoadFile(JSON_PATH_SETTINGS, settings );
		Print("<28DL> Config was loaded");
		
		return settings;
	}


}
*/
class WTF69VirusMdfr: ModifierBase
{

	
	
	
	
	static const int WTF69_AGENT_THRESHOLD_ACTIVATE = 100;
	static const int WTF69_AGENT_THRESHOLD_DEACTIVATE = 20;
	float WTF69_Damage = 0.2;
	float m_Time = 0;
	bool m_IsVomiting;
	override void Init()
	{
		m_TrackActivatedTime = false;
		m_ID 			= WTF69Modifiers.MDF_WTF69VIRUS;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 0.1;
	}
	
	override protected bool ActivateCondition(PlayerBase player)
	{
		if(player.GetSingleAgentCount(WTF69Agents.WTF69VIRUS) > WTF69_AGENT_THRESHOLD_ACTIVATE) 
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
		//if( player.m_NotifiersManager ) player.m_NotifiersManager.AttachByType(eNotifiers.NTF_SICK);
		player.IncreaseDiseaseCount();
		
		
		player.HasWTF69 = true;
	
		 
		
		
	}
	
	override protected void OnDeactivate(PlayerBase player)
	{
		player.DecreaseDiseaseCount();
		player.HasWTF69 = false;
		//player.PlayerWTF69Deactivate();
		 //player.GetSymptomManager().RemoveSecondarySymptom(WTF69SymptomIDs.SYMPTOM_WTF69);
		
	}

	override protected bool DeactivateCondition(PlayerBase player)
	{
		if(player.GetSingleAgentCount(WTF69Agents.WTF69VIRUS) < WTF69_AGENT_THRESHOLD_DEACTIVATE) 
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
		float agentcount = player.GetSingleAgentCount(WTF69Agents.WTF69VIRUS);
		Print(agentcount);
		
		float currenthealth = player.GetHealth("GlobalHealth", "Blood");
		player.SetHealth("GlobalHealth", "Blood" ,  currenthealth - WTF69_Damage );
		
			float vomit_treshold = 3200;
		
		if(!m_IsVomiting && currenthealth < vomit_treshold)
			{
		
		SymptomBase symptom = player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
		m_IsVomiting = true;
			}

		//////////////////////SOUND///////////////////////
		   	 	
	}	
};