class Msp_Fridge_Base : Msp_Item 
{
	ref array<string> m_AllowedCargo = {"SodaCan_ColorBase", "Bottle_Base", "Edible_Base"};
	ref array<string> m_SpecialNotAllowedCargo = {"Weapon_Base"};

	//sound
	const string SOUND_HUMMING 		= "MSP_RefrigeratorHumming_SoundSet";
	const string SOUND_TURN_ON		= "spotlight_turn_on_SoundSet";
	const string SOUND_TURN_OFF		= "spotlight_turn_off_SoundSet";
	
	protected EffectSound m_SoundHummingLoop;
	protected EffectSound m_SoundTurnOn;
	protected EffectSound m_SoundTurnOff;
	
	//--- POWER EVENTS
	override void OnSwitchOn()
	{
		super.OnSwitchOn();
		
		//sound (client only)
		SoundTurnOn();
	}

	override void OnSwitchOff()
	{
		super.OnSwitchOff();
		
		//sound (client only)
		SoundTurnOff();
	}
	
	override void OnWorkStart()
	{	
		//sound (client only)
		SoundHummingStart();
	}

	override void OnWorkStop()
	{		
		//sound (client only)
		SoundHummingStop();
	}
	
	//================================================================
	// SOUNDS
	//================================================================
	protected void SoundHummingStart()
	{
		PlaySoundSetLoop( m_SoundHummingLoop, SOUND_HUMMING, 0.1, 0.3 );
	}
	
	protected void SoundHummingStop()
	{
		StopSoundSet( m_SoundHummingLoop );
	}	

	protected void SoundTurnOn()
	{
		PlaySoundSet( m_SoundTurnOn, SOUND_TURN_ON, 0, 0);
	}
	
	protected void SoundTurnOff()
	{
		PlaySoundSet( m_SoundTurnOff, SOUND_TURN_OFF, 0, 0);
	}

	override bool CanReceiveItemIntoCargo (EntityAI item)
	{
		foreach( string notAllowedCargo : m_SpecialNotAllowedCargo )
		{		
			if(item.IsKindOf(notAllowedCargo))
				return false;
		}

		foreach( string allowedCargo : m_AllowedCargo )
		{		
			if(item.IsKindOf(allowedCargo))
				return true;
		}
		
		return false;
	}
	
	override bool CanSwapItemInCargo (EntityAI child_entity, EntityAI new_entity)
	{
		foreach( string notAllowedCargo : m_SpecialNotAllowedCargo )
		{		
			if(child_entity.IsKindOf(notAllowedCargo) || new_entity.IsKindOf(notAllowedCargo))
				return false;
		}
		foreach( string allowedCargo : m_AllowedCargo )
		{		
			if(child_entity.IsKindOf(allowedCargo) && new_entity.IsKindOf(allowedCargo))
				return true;
		}		
		return false;		
	}

	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionPlugIn);
		AddAction(ActionPlugTargetIntoThis);
		AddAction(ActionUnplugThisByCord);
		AddAction(ActionTurnOnWhileOnGround);
		AddAction(ActionTurnOffWhileOnGround);
	}
};