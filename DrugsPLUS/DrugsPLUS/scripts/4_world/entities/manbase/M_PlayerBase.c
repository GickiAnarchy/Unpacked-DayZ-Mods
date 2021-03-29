modded class PlayerBase
{

    const string SNIFF_LOUD                         = "LoudSniffing_SoundSet";
    const string SNIFF_QUIET                        = "QuietSniffing_SoundSet";

    EffectSound                                     m_TurnOff;
    EffectSound                                     m_TurnOn;
    EffectSound                                     m_Tripping;
    EffectSound                                     m_Burp;
    EffectSound                                     m_Hiccup;
    EffectSound                                     m_Sniff;	

    bool consumedCocaine = false;
    ref Timer cocaineTimer;		
	
    ref Timer alcoholTimer;
    float alcoholConsumed;
	
    ref Timer shroomTimer;

    const string SOUND_TURN_ON                      = "turnOnRadio_SoundSet";
    const string SOUND_TURN_OFF                     = "turnOffRadio_SoundSet";
    const string SOUND_TEST                         = "HeavyFire_SoundSet";
    const string EAT                                = "Eating_SoundSet";
    const string INJECT_SOUND                       = "Syringe_SoundSet";
    const string YAWNING                            = "SecondYawn_SoundSet";
    const string BURP                               = "Burp_SoundSet";
    const string HICCUP                             = "Hiccup_SoundSet";


    //ref MagicMushroomSettingsScript                 m_ActiveMagicMushroomSettings;
    ref TStringArray YawningList;
    ref TStringArray YawningList2;
    ref TStringArray TripList;

    bool open = false;
    bool unlimitedStaminaCoke =false;
    bool unlimitedStaminaHeroin =false;
    bool unlimitedStaminaMorphine =false;
    bool unlimitedStaminaMeth =false;
    bool unlimitedStaminaAlcohol =false;
    bool unlimitedStaminaShroom =false;		

	override void Init()
	{
		super.Init();
		alcoholConsumed=0;
		
		//Reset effects on player spawn.
		//CameraEffects.changeHue(60);
		//CameraEffects.changeRadBlurXEffect(0);
		//CameraEffects.changeRadBlurYEffect(0);
		//CameraEffects.setExposure(60);
		//CameraEffects.changeRotationBlurPower(0);
		//CameraEffects.changeVignette(0);
		//CameraEffects.changeChromaX(0);
		//CameraEffects.changeChromaY(0);
	}
	
	void setInjuredEffect(float value) {
		
		//bottles have 500 units typical 
		//cans have around 330
		//so use 500 as the denominator
		alcoholConsumed += value/500;
		Print("[DP] Alcohol consumed: " + value);	
		
	  	if (alcoholConsumed >= 2.0) {
			alcoholConsumed = 2.0;
		}
		
		Print("[DP] Alcohol Multiplier: " + alcoholConsumed);			
		 
	      HumanCommandAdditives HCA = GetCommandModifier_Additives();
	      HCA.SetInjured( alcoholConsumed , true );
		if (value > 0) {
			CameraEffects.changeRadBlurXEffect(GetDPConfig().vodkaRadBlurXPower*alcoholConsumed);
            	CameraEffects.changeRadBlurYEffect(GetDPConfig().vodkaRadBlurYPower*alcoholConsumed);
			//GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(AlcoholEffectsTriggeredOff, GetDPConfig().vodkaEffectTime*1000, false);	
			if (!alcoholTimer) { alcoholTimer = new Timer()};
			alcoholTimer.Stop();
			alcoholTimer.Run(GetDPConfig().vodkaEffectTime, this, "AlcoholEffectsTriggeredOff", null, false);
		}
    }
	
	void AlcoholEffectsTriggeredOff() {
		HumanCommandAdditives HCA = GetCommandModifier_Additives();
		HCA.SetInjured( 0 , true );
		CameraEffects.changeRadBlurXEffect(0);
		CameraEffects.changeRadBlurYEffect(0);
		alcoholConsumed = 0;
		PlaySoundSet(m_Burp, BURP, 0.0, 0.0);
	}

	// Cocaine Visual Effect On.
	void CocaineEffectsTriggered() {
		//Print("[DP] Turning on cocaine effect for " + GetDPConfig().cocaineEffectTime + " seconds");
		if(GetGame().IsClient())
		{
	            // Visual effects for cocaine powder.
	            CameraEffects.changeHue(GetDPConfig().cocaineHueIntensity);
	            CameraEffects.changeRadBlurXEffect(GetDPConfig().cocaineRadBlurXPower);
	            CameraEffects.changeRadBlurYEffect(GetDPConfig().cocaineRadBlurYPower);
			
			// Unlimited Stamina to the player if allowed by config file.
			if(GetDPConfig().allowunlimitedstamina)
			{
				unlimitedStaminaCoke = true;
				unlimitedStaminaHeroin = false;
				unlimitedStaminaAlcohol = false;
				unlimitedStaminaMeth = false;
				unlimitedStaminaMorphine = false;
				unlimitedStaminaShroom = false;
			}			
	  	}
		
		PlaySoundSet(m_Sniff, SNIFF_LOUD, 0.0, 0.0);
		
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(CocaineEffectsTriggeredOff, GetDPConfig().cocaineEffectTime*1000, false);  
		//if (!cocaineTimer) { cocaineTimer = new Timer()};
		//cocaineTimer.Stop();
		//cocaineTimer.Run(GetDPConfig().cocaineEffectTime, this, "CocaineEffectsTriggeredOff", null, false);	
	}

    // Cocaine Effects Triggered Off.
    void CocaineEffectsTriggeredOff()
    {
	  //Print("[DP] Turning off cocaine effect");
        if(GetGame().IsClient())
        {
            CameraEffects.changeHue(60);
            CameraEffects.changeRadBlurXEffect(0);
            CameraEffects.changeRadBlurYEffect(0);
		
		unlimitedStaminaCoke = false;
		unlimitedStaminaHeroin = false;
		unlimitedStaminaAlcohol = false;
		unlimitedStaminaMeth = false;
		unlimitedStaminaMorphine = false;
		unlimitedStaminaShroom = false;			
        }
		
	  PlaySoundSet(m_Sniff, SNIFF_QUIET, 0.0, 0.0);	
    }

	void PickRandomTripSound()
    {

        TripList = new ref TStringArray;
        // Scary sounds.
        TripList.Insert("ScaryOne_SoundSet");
        TripList.Insert("ScaryTwo_SoundSet");
        TripList.Insert("ScaryThree_SoundSet");
        TripList.Insert("ScaryFour_SoundSet");
        TripList.Insert("ScaryFive_SoundSet");
        TripList.Insert("ScarySix_SoundSet");
        TripList.Insert("ScarySeven_SoundSet");

        // Random sounds.
        TripList.Insert("RandomOne_SoundSet");
        TripList.Insert("RandomTwo_SoundSet");
        TripList.Insert("RandomThree_SoundSet");
        TripList.Insert("RandomFour_SoundSet");
        TripList.Insert("RandomFive_SoundSet");
        TripList.Insert("RandomSix_SoundSet");
        TripList.Insert("RandomSeven_SoundSet");
        TripList.Insert("RandomEight_SoundSet");

        // Ambient Sounds.
        TripList.Insert("AmbientOne_SoundSet");
        TripList.Insert("AmbientTwo_SoundSet");
        TripList.Insert("AmbientThree_SoundSet");
        TripList.Insert("AmbientFour_SoundSet");
        TripList.Insert("AmbientFive_SoundSet");
        TripList.Insert("AmbientSix_SoundSet");

        // Chance for no sound.
        //TripList.Insert("");

        string tripSelection = TripList.GetRandomElement();
        Print("[DP] The trip music selected was: " + tripSelection);
        PlaySoundSet(m_Tripping, tripSelection, 0.0, 0.0);
    }

	void MagicMushroomEffectsTriggered()
    {

        if(GetGame().IsClient())
        {
            int randomChance;
            randomChance = Math.RandomInt(0,100);

            if(randomChance >= 50)
            {
                CameraEffects.changeRadBlurXEffect(Math.RandomInt(0,5));
                CameraEffects.changeRadBlurYEffect(Math.RandomInt(0,5));
            }
            else
            {
                CameraEffects.changeChromaX(Math.RandomInt(0,5));
                CameraEffects.changeChromaY(Math.RandomInt(0,5));
            }

            // Visual effects for cocaine powder.
            CameraEffects.changeHue(Math.RandomInt(0,100));

            // Unlimited Stamina to the player if allowed by config file.
            if(GetDPConfig().allowunlimitedstamina)
            {
                	unlimitedStaminaCoke = false;
			unlimitedStaminaHeroin = false;
			unlimitedStaminaAlcohol = false;
			unlimitedStaminaMeth = false;
			unlimitedStaminaMorphine = false;
			unlimitedStaminaShroom = true;
            }

            //TRIP SOUND EFFECTS.
            //Call to end effects after config set time.
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PickRandomTripSound, GetDPConfig().magicmushroomEffectTime *1000 / 1.5, false);

            // Call to end effects after config set time.
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PickRandomTripSound, GetDPConfig().magicmushroomEffectTime *1000 / 2, false);

            // Call to end effects after config set time.
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PickRandomTripSound, GetDPConfig().magicmushroomEffectTime *1000 / 4, false);
			
		// Call to end effects after config set time.
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PickRandomTripSound, GetDPConfig().magicmushroomEffectTime *1000 / 6, false);
			
		// Call to end effects after config set time.
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PickRandomTripSound, GetDPConfig().magicmushroomEffectTime *1000 / 8, false);

		//if (!shroomTimer) { shroomTimer = new Timer()};
		//shroomTimer.Stop();
		//shroomTimer.Run(GetDPConfig().magicmushroomEffectTime*10, this, "MagicMushroomEffectsTriggeredOff", null, false);	
            // TURN OFF EFFECTS
            // Call to end effects after config set time.
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(MagicMushroomEffectsTriggeredOff, GetDPConfig().magicmushroomEffectTime *1000, false);
        }   
        PlaySoundSet(m_TurnOn, EAT, 0.0, 0.0);
    }

    // Magic Mushroom Effects Triggered Off.
    void MagicMushroomEffectsTriggeredOff()
    {

        YawningList = new ref TStringArray;
        YawningList.Insert("FirstYawn_SoundSet");
        YawningList.Insert("SecondYawn_SoundSet");
        string yawnSelection = YawningList.GetRandomElement();

        if(GetGame().IsClient())
        {
            CameraEffects.changeHue(60);
            CameraEffects.changeRadBlurXEffect(0);
            CameraEffects.changeRadBlurYEffect(0);
            CameraEffects.changeChromaX(0);
            CameraEffects.changeChromaY(0);
        }

        unlimitedStaminaCoke = false;
	  unlimitedStaminaHeroin = false;
	  unlimitedStaminaAlcohol = false;
	  unlimitedStaminaMeth = false;
	  unlimitedStaminaMorphine = false;
	  unlimitedStaminaShroom = false;

        PlaySoundSet(m_TurnOff, yawnSelection, 0.0, 0.0);
    };
};