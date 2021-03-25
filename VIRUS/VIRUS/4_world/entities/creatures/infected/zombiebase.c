modded class ZombieBase extends DayZInfected
{

	 ref BloodVomitZombie m_BloodVomitEffect;
	 ref BloodVomitSplash m_Bloodsplash;
   	 Particle m_BloodVomit;
   	 Particle m_BloodVomitsplash;
	 ref Timer BloodVomitTimer;
	 float ZombieVomitTime = Math.RandomInt(60,120);
	
	void ZombieBase()
	{
		
		StartVomit();
	}
		
			
			
override bool CanBeSkinned()
	{
		return true;
	}
	
	 
void StartVomit()
	
	{
	
	BloodVomitTimer = new Timer();
	BloodVomitTimer.Run(ZombieVomitTime,this,"BloodVomit", NULL, true);
	
	}
	
	
void BloodVomit()
	{
	 	
		if( !IsAlive() )
		{
		BloodVomitTimer.Stop();
		}else{
		if (!GetGame().IsServer())
		{
		//int boneIdx = GetBoneIndexByName("pin_lookat");
		
		
		int mouth = GetBoneIndex("rMouth");
		m_BloodVomitEffect = new BloodVomitZombie();
		SEffectManager.PlayInWorld( m_BloodVomitEffect, "0 1.5 0.3" );
		m_BloodVomit = m_BloodVomitEffect.GetParticle();
		AddChild(m_BloodVomit, mouth);
		
		
		m_Bloodsplash = new BloodVomitSplash();
		SEffectManager.PlayInWorld( m_Bloodsplash, GetPosition() );
		m_BloodVomitsplash = m_Bloodsplash.GetParticle();
		m_BloodVomitsplash.ScaleParticleParam(EmitorParam.LIFETIME, 0.1);
		
	
		///////////////////SOUND/////////////////////
		VomitSound();
		}
		}
		
	}
	
	
	
  
	
   
    
    
	
    //Sound Part
    ref SoundObject soundObjVomit; //Sound for Vomit
    ref SoundObjectBuilder soundBuilderVomit;
    AbstractWave BloodVomitSounds;
    
    private bool m_playStatus = true; //will always play sound, make a setter/getter if you wish to control this via conditions via other classes
  
    AbstractWave MSaySoundSet(string name)
    {
        SoundParams soundParams = new SoundParams(name);
        soundBuilderVomit            = new SoundObjectBuilder(soundParams);
        soundObjVomit                = soundBuilderVomit.BuildSoundObject();
        soundObjVomit.SetPosition(GetPosition());
        return GetGame().GetSoundScene().Play3D(soundObjVomit, soundBuilderVomit);
    }

    void VomitSound()
	
    {
        if (!GetGame().IsServer() && m_playStatus) //Check if its a client entity running this class and sounds is set to trigger
        {
            BloodVomitSounds = MSaySoundSet("BloodVomit_SoundSet"); //Hook sound to body
            BloodVomitSounds.Loop(false);
            soundObjVomit.SetPosition(GetPosition());
        }
    }
	
	

		
}
