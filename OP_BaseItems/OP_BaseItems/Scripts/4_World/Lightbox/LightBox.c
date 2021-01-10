class OP_Lightbox : Building // spawn this via init.c (no fuel source required as the assets intent is for use at traders/events)
{
	static const string			START_SOUND = "powerGeneratorTurnOn_SoundSet";
	static const string			LOOP_SOUND = "powerGeneratorLoop_SoundSet";
	static const string			STOP_SOUND = "powerGeneratorTurnOff_SoundSet";

	CarLightBase 	m_Light;

	protected vector m_exhaustPtcPos;
	protected vector m_exhaustPtcDir;

	protected EffectSound 		m_EngineLoop;
	protected EffectSound 		m_EngineStart;
	protected EffectSound 		m_EngineStop;

	ref Timer 					m_SoundLoopStartTimer;
	ref protected Effect 		m_Smoke;


	void OP_Lightbox()
	{
		if 	( MemoryPointExists("exhaust_start") )
		{
			m_exhaustPtcPos = GetMemoryPointPos("exhaust_start");
		}
	}

	override void OnWorkStart()
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() ) // Client side
		{
			SetObjectMaterial(0, "OP_Baseitems\\Assets\\Lightbox\\data\\lightbox_glass_on.rvmat"); 

			PlaySoundSet( m_EngineStart, START_SOUND, 0, 0 );
			
			if (!m_SoundLoopStartTimer)
				m_SoundLoopStartTimer = new Timer( CALL_CATEGORY_SYSTEM );
			
			if ( !m_SoundLoopStartTimer.IsRunning() ) // Makes sure the timer is NOT running already
			{
				m_SoundLoopStartTimer.Run(1.5, this, "StartLoopSound", NULL, false);
			}
		}
	}

	override bool CanIgniteItem(EntityAI ignite_target = NULL)
	{
		return GetCompEM().IsWorking();
	}

	override void OnWorkStop()
	{	
		SetObjectMaterial(0, "OP_Baseitems\\Assets\\Lightbox\\data\\lightint_co.paa");
		
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
		{
			// Sound
			PlaySoundSet( m_EngineStop, STOP_SOUND, 0, 0 );
			StopSoundSet(m_EngineLoop);
			if ( m_Light )
			{
				GetGame().ObjectDelete(m_Light);
			}
			// particle
			if (m_Smoke)
			{
				delete m_Smoke;
			}
		}
	}

	void StartLoopSound()
	{
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
		{
			if ( GetCompEM().IsWorking() )
			{
				PlaySoundSetLoop( m_EngineLoop, LOOP_SOUND, 0, 0 );
				
				// Particles
				m_Light = CarLightBase.Cast(  ScriptedLightBase.CreateLight(Hatchback_02FrontLight, "0 0 0", 0.08)  ); // Position is zero because light is attached on parent immediately.
				m_Light.AttachOnMemoryPoint(this, "lightpoints", "lightpointend");

				vector local_ori = "90 0 0";
				m_Smoke = new EffGeneratorSmoke();
				SEffectManager.PlayOnObject(m_Smoke, this, m_exhaustPtcPos, local_ori);
			}
		}
	}
}/*
class OP_PartyLight : Building 
{
	PartyLight 	m_Light;
	void OP_PartyLight()
	{
		m_Light = PartyLight.Cast( ScriptedLightBase.CreateLight( PartyLight, "0 0 0") );
		m_Light.AttachOnMemoryPoint(this, "light");
	}

}