class OP_Charc_BBQ extends Inventory_Base //todo add attach ua to edible base
{
	protected Particle m_ParticleFireStart2;
	protected Particle 	m_ParticleCooking;
	protected Particle m_ParticleSmallSmoke;

	protected int PARTICLE_BAKING_START 	= ParticleList.COOKING_BAKING_START;
	protected int PARTICLE_OVEN_FIRE_START 		= ParticleList.CAMP_STOVE_FIRE;
	protected int PARTICLE_SMALL_SMOKE 			= ParticleList.CAMP_SMALL_SMOKE;
	protected int PARTICLE_BBQ_FIRE 			= ParticleList.OP_BBQ;

	protected ref Timer m_HeatingTimer;
	protected ref Timer m_CoolingTimer;
	
	const string SOUND_TURN_ON		= "MatchStrike_SoundSet";
	const string SOUND_BURNING 		= "NoFuelFire_SoundSet";

	protected EffectSound m_SoundBurningLoop;
	protected EffectSound m_SoundTurnOn;
	
	ref Cooking m_CookingProcess;
    protected ref OpenableBehaviour m_OPOpenable;

    void OP_Charc_BBQ()
    {   
        m_OPOpenable = new OpenableBehaviour(false);
        RegisterNetSyncVariableBool("m_OPOpenable.m_IsOpened");
        RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
        RegisterNetSyncVariableBool("m_IsPlaceSound");
    }
    override void EEInit()
    {
        super.EEInit();
        GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
    }

    override void Open()
    {
        m_OPOpenable.Open();
    
        GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
        SoundSynchRemote();
        UpdateVisualState();
    } 

    override void Close()
    {
        m_OPOpenable.Close();
        
        UpdateVisualState();
        GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
        SoundSynchRemote();
    }

    override bool IsOpen()
    {
        return m_OPOpenable.IsOpened();
    }

    void UpdateVisualState()
    {
        if ( IsOpen() )
        {
        	SetAnimationPhase("lid2",0);
            SetAnimationPhase("lid1",1);
        }
        else
        {
            SetAnimationPhase("lid2",1);
            SetAnimationPhase("lid1",0);
        }

    }

	override bool IsHeavyBehaviour()
	{
		return true;
	}
	
	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) ) {return false;}
		if ( GetCompEM().IsSwitchedOn() )
		{
			return false;
		}
		
		return true;
	}

	override bool CanRemoveFromCargo( EntityAI parent )
	{
		return true;
	}

	override bool CanPutIntoHands( EntityAI parent )
	{
		super.CanPutIntoHands( parent );	

		if ( GetInventory().AttachmentCount() == 0 && !IsOpen() ) 
		{
			return true;
		}
		return false;

	}

	override void AfterStoreLoad()
	{	
		super.AfterStoreLoad();

		if ( !IsIgnited() && GetTemperature() > 0) // if the bbq was off on server restart with temp it wouldn't decrease
		{
			StartCooling();	
		}
	}	

    override void EEItemAttached( EntityAI item, string slot_name )
    {
    	super.EEItemAttached( item, slot_name );
        if ( item.IsKindOf( "OP_Charcoal" ) ) 
        {
            SetAnimationPhase( "charbag", 0 );  
            SetAnimationPhase( "coals", 0 ); 
                     
        }
        PlaceOnSurface(); // when food/fuel is attached it changes y position up 1ft? only had this occur with an item using energy component) 
    }

    override void EEItemDetached(EntityAI item, string slot_name)
    {
        super.EEItemDetached(item, slot_name);
                
        if ( item.IsKindOf( "OP_Charcoal" ) ) 
        {
            SetAnimationPhase( "charbag", 1 );
            SetAnimationPhase( "coals", 1 ); 
        }
        
        PlaceOnSurface();
    }

	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
			
		SetLifetime(3888000);
	}

	// Energy Components
	override bool IsIgnited()
	{
		return GetCompEM().IsWorking();
	}
	
	override bool CanIgniteItem(EntityAI ignite_target = NULL)
	{
		return GetCompEM().IsWorking();
	}	
	//--- POWER EVENTS
	override void OnSwitchOn()
	{
		super.OnSwitchOn();
		
		//sound (client only)
		SoundTurnOn();
		SoundBurningStart();
	}

	override void OnSwitchOff()
	{
		super.OnSwitchOff();
		SoundBurningStop();
	}
	
	override void OnWorkStart()
	{
		ParticleOnStart();
		SoundBurningStart();
		StartHeating();
	}

	override void OnWorkStop()
	{
	//	
		ParticleOnStop();
		StopHeating();
		StartCooling();
		SoundBurningStop();
	}
	
	override void OnWork( float consumed_energy )
	{
		//manage cooking equipment
		
		if ( GetGame() && GetGame().IsServer() )
		{	
			if ( GetTemperature() >= 100)
			{
				m_CookingProcess = new Cooking();
				for ( int i = 1; i <= 8; i++ )
				{
					Edible_Base food = Edible_Base.Cast( FindAttachmentBySlotName( "Ingredient" + i.ToString() ) );
					if ( food )
					{
						m_CookingProcess.CookOnStick( food, 0.5 );
						food.SetTemperature( 100 );
					}	
				}	
			}
		}
	}

	//================================================================
	// heating/cooling
	//================================================================
	protected void StartHeating()
	{		
		m_HeatingTimer = new Timer ( CALL_CATEGORY_GAMEPLAY );
		m_HeatingTimer.Run ( 2, this, "Heating", NULL, true );	
	}

	protected void StopHeating()
	{
		m_HeatingTimer.Stop();
		m_HeatingTimer = NULL;
	}	

	//Start cooling
	protected void StartCooling()
	{
		if ( m_HeatingTimer )
		{
			m_HeatingTimer.Stop();
			m_HeatingTimer = NULL;
		}
		
		m_CoolingTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
		m_CoolingTimer.Run( 5, this, "Cooling", NULL, true );		// true param loops
	}

	//Do heating
	protected void Heating()
	{

		float temperature = GetTemperature();
		temperature = temperature + 10;
		
		if ( GetGame() && GetGame().IsServer() )
		{	
			SetTemperature( temperature );
		}
		if ( temperature >= 30 )
		{
			
			SetObjectMaterial( 0, "OP_Baseitems\\Assets\\OP_BBQ\\data\\coalemission1.rvmat" ); 
			SetObjectMaterial( 1, "OP_Baseitems\\Assets\\OP_BBQ\\data\\ashes_emission.rvmat" );   // index 1 is ashes
		}
		if ( temperature >= 125 )
		{
			SetObjectMaterial( 0, "OP_Baseitems\\Assets\\OP_BBQ\\data\\coalemission2.rvmat" ); 
			SetObjectMaterial( 1, "OP_Baseitems\\Assets\\OP_BBQ\\data\\ashes_emission.rvmat" ); //
		
		}
		if ( temperature >= 200 )
		{
			SetObjectMaterial( 0, "OP_Baseitems\\Assets\\OP_BBQ\\data\\coalemission3.rvmat" ); 
			SetObjectMaterial( 1, "OP_Baseitems\\Assets\\OP_BBQ\\data\\ashes_emission.rvmat" ); 
		}
		
		//transfer heat to near players
		TransferHeatToNearPlayers();
		
	}
	
	void Cooling()
	{
		float temperature = GetTemperature();
		temperature = temperature - 5;

		if ( GetGame() && GetGame().IsServer() )
		{	
			SetTemperature( temperature );
		}
		if ( temperature <= 200 )
		{
			SetObjectMaterial( 0, "OP_Baseitems\\Assets\\OP_BBQ\\data\\coalemission2.rvmat" );
		}

		if ( temperature <= 125 )
		{
			SetObjectMaterial( 0, "OP_Baseitems\\Assets\\OP_BBQ\\data\\coalemission1.rvmat" );
		
		}

		if ( GetTemperature() <= 30 )
		{
			SetObjectMaterial( 0, "OP_Baseitems\\Assets\\OP_BBQ\\data\\coals.rvmat" );
			SetObjectMaterial( 1, "dz\gear\cooking\data\stonegroundnoemit.rvmat" ); // index 1 is ashes
		}
		if ( GetTemperature() == 0)
		{
			m_CoolingTimer.Stop();
			m_CoolingTimer = NULL;
			//Print("zxd");
		}
	}

	//transfer heat to all nearby players
	protected void TransferHeatToNearPlayers()
	{
		float distance;

		ref array<Object> nearest_objects = new array<Object>;
		ref array<CargoBase> proxy_cargos = new array<CargoBase>;

		GetGame().GetObjectsAtPosition ( GetPosition(), 3.0, nearest_objects, proxy_cargos ); 

		for ( int i = 0; i < nearest_objects.Count(); i++ )
		{
			Object nearest_object = nearest_objects.Get(i);
			
			//! heat transfer to player
			if ( nearest_object.IsInherited( PlayerBase ) )
			{
				PlayerBase player = PlayerBase.Cast( nearest_object );
				distance = vector.Distance( player.GetPosition(), GetPosition() );
				distance = Math.Max( distance, 0.1 );	//min distance cannot be 0 (division by zero)
				
				//! heat transfer through air to player ( anv temperature )
				float temperature = GetTemperature() * ( 0.035 / distance );
				player.AddToEnvironmentTemperature( temperature );
			}
			//! heat transfer to items (not in player possession)
			else if ( nearest_object != this && nearest_object.IsInherited( ItemBase ) && nearest_object.GetParent() == null )
			{
				ItemBase item = ItemBase.Cast( nearest_object );
				float wetness = item.GetWet();

				//! drying of items around the fireplace (based on distance)
				if ( wetness > 0 )
				{
					distance = vector.Distance( item.GetPosition(), GetPosition() );
					distance = Math.Max( distance, 0.1 );	//min distance cannot be 0 (division by zero)
					
					wetness = wetness * ( 0.035 / distance );
					wetness = Math.Clamp( wetness, item.GetWetMin(), item.GetWetMax() );
					item.AddWet( -wetness );
				}
			}
		}
	}
	//================================================================
	// Particles
	//================================================================
	protected bool PlayParticle( out Particle particle, int particle_type, vector local_pos )
	{
		if ( !particle && GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
		{
			particle = Particle.PlayOnObject( particle_type, this, local_pos );
			
			return true;
		}
		
		return false;
	}

	protected bool StopParticle( out Particle particle )
	{
		if ( particle && GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
		{
			particle.Stop();
			particle = NULL;
			
			return true;
		}
		
		return false;
	}

	protected void ParticleOnStart()
	{	
		PlayParticle( m_ParticleFireStart2, PARTICLE_BBQ_FIRE, GetMemoryPointPos("fire_pos")  );
		PlayParticle( m_ParticleSmallSmoke, PARTICLE_SMALL_SMOKE, GetMemoryPointPos("smoke_pos") );
		PlayParticle( m_ParticleCooking, PARTICLE_BAKING_START, GetMemoryPointPos("smoke_pos")  );
	}
	
	protected void ParticleOnStop()
	{
		StopParticle( m_ParticleSmallSmoke );
		StopParticle( m_ParticleCooking );
		StopParticle( m_ParticleFireStart2 );
	}
	//================================================================
	// SOUNDS
	//================================================================
	protected void SoundTurnOn()
	{
		PlaySoundSet( m_SoundTurnOn, SOUND_TURN_ON, 0.1, 0.1 );
	}
	
	protected void SoundBurningStart()
	{
		PlaySoundSetLoop( m_SoundBurningLoop, SOUND_BURNING, 0.1, 0.3 );
	}
	
	protected void SoundBurningStop()
	{
		StopSoundSet( m_SoundBurningLoop );
	}	
			
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
        AddAction(ActionPlaceObject);  
//        AddAction(ActionIgniteBBQ); recipe
        AddAction(ActionExtinguishBBQ);
		AddAction(ActionOpenCharBBQ);
		AddAction(ActionCloseCharBBQ);

	}
}
class OP_Charcoal extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionAttach);
	}
}
modded class Edible_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionAttach);
	}
}