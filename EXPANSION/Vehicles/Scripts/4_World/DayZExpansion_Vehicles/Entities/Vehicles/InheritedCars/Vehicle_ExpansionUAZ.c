/*
 * Vehicle_ExpansionUAZ.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class Vehicle_ExpansionUAZ extends ExpansionVehicleCarBase
{
	// ------------------------------------------------------------
	void Vehicle_ExpansionUAZ()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("Vehicle_ExpansionUAZ::Constructor - Start");
		#endif

		m_dmgContactCoef = 0.040;

		m_EngineStartOK = "Hatchback_02_engine_start_SoundSet";
		m_EngineStartBattery = "Hatchback_02_engine_failed_start_battery_SoundSet";
		m_EngineStartPlug = "Hatchback_02_engine_failed_start_sparkplugs_SoundSet";
		m_EngineStartFuel = "Hatchback_02_engine_failed_start_fuel_SoundSet";
		m_EngineStopFuel = "offroad_engine_stop_fuel_SoundSet";
		
		m_CarDoorOpenSound = "offroad_door_open_SoundSet";
		m_CarDoorCloseSound = "offroad_door_close_SoundSet";

		#ifdef EXPANSIONEXPRINT
		EXPrint("Vehicle_ExpansionUAZ::Constructor - End");
		#endif
	}

	// ------------------------------------------------------------
	override string ExpansionGetWheelType(int slot_id)
	{
		return "ExpansionUAZWheel";
	}

	// ------------------------------------------------------------
	override int GetAnimInstance()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("Vehicle_ExpansionUAZ::GetAnimInstance");
		#endif

		return ExpansionVehicleAnimInstances.EXPANSION_UAZ;
	}

	// ------------------------------------------------------------
	override CarRearLightBase CreateRearLight()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("Vehicle_ExpansionUAZ::CreateRearLight");
		#endif

		return CarRearLightBase.Cast( ScriptedLightBase.CreateLight(ExpansionRearCarLights) );
	}
	
	// ------------------------------------------------------------
	override CarLightBase CreateFrontLight()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("Vehicle_ExpansionUAZ::CreateFrontLight");
		#endif

		return CarLightBase.Cast( ScriptedLightBase.CreateLight(ExpansionCarFrontLight) );
	}

	// ------------------------------------------------------------
	override int GetSeatAnimationType( int posIdx )
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("Vehicle_ExpansionUAZ::GetSeatAnimationType");
		#endif
		
		switch( posIdx )
		{
		case 0:
			return DayZPlayerConstants.VEHICLESEAT_DRIVER;
		case 1:
			return DayZPlayerConstants.VEHICLESEAT_CODRIVER;
		case 2:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_L;
		case 3:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_R;
		}

		return 0;
	}

	// ------------------------------------------------------------
	override string GetDoorSelectionNameFromSeatPos(int posIdx)
	{
		switch( posIdx )
		{
		case 0:
			return "uazdriverdoor";
		break;
		case 1:
			return "uazcodriverdoor";
		break;
		case 2:
			return "uazcargo1door";
		break;
		case 3:
			return "uazcargo2door";
		break;
		}
		
		return super.GetDoorSelectionNameFromSeatPos(posIdx);
	}

	// ------------------------------------------------------------
	override string GetDoorInvSlotNameFromSeatPos(int posIdx)
	{
		switch( posIdx )
		{
		case 0:
			return "uazdriverdoor";
		break;
		case 1:
			return "uazcodriverdoor";
		break;
		case 2:
			return "uazcargo1door";
		break;
		case 3:
			return "uazcargo2door";
		break;
		}
		
		return super.GetDoorInvSlotNameFromSeatPos(posIdx);
	}
	
	// ------------------------------------------------------------
	override int GetCarDoorsState( string slotType )
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("Vehicle_ExpansionUAZ::GetCarDoorsState");
		#endif
		
		CarDoor carDoor;
		Class.CastTo( carDoor, FindAttachmentBySlotName( slotType ) );
		if ( !carDoor ) {
			return CarDoorState.DOORS_MISSING;
		}

		switch( slotType )
		{
			case "uazdriverdoor": {
				if ( GetAnimationPhase("uazdriverdoor") > 0 ) {
					return CarDoorState.DOORS_OPEN;
				} else {
					return CarDoorState.DOORS_CLOSED;
				}
				break;
			}
			case "uazcodriverdoor": {
				if ( GetAnimationPhase("uazcodriverdoor") > 0 ) {
					return CarDoorState.DOORS_OPEN;
				} else {
					return CarDoorState.DOORS_CLOSED;
				}
				break;
			}
			case "uazcargo1door": {
				if ( GetAnimationPhase("uazcargo1door") > 0 ) {
					return CarDoorState.DOORS_OPEN;
				} else {
					return CarDoorState.DOORS_CLOSED;
				}
				break;
			}
			case "uazcargo2door": {
				if ( GetAnimationPhase("uazcargo2door") > 0 ) {
					return CarDoorState.DOORS_OPEN;
				} else {
					return CarDoorState.DOORS_CLOSED;
				}
				break;
			}
			case "uaztrunkdoor": {
					return CarDoorState.DOORS_CLOSED;
				//if ( GetAnimationPhase("uaztrunkdoor") > 0.5 ) {
				//	return CarDoorState.DOORS_OPEN;
				//} else {
				//	return CarDoorState.DOORS_CLOSED;
				//}
				break;
			}
			default: {
				return CarDoorState.DOORS_MISSING;
			}
		}

		return CarDoorState.DOORS_MISSING;
	}
	
	override bool CanReleaseAttachment( EntityAI attachment )
	{
		string attType = attachment.GetType();
		
		if ( EngineIsOn() )
		{
			if ( attType == "CarRadiator" || attType == "CarBattery" || attType == "SparkPlug" )
				return false;
		}

		return true;
	}
	
	// ------------------------------------------------------------
	override float OnSound( CarSoundCtrl ctrl, float oldValue )
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("Vehicle_ExpansionUAZ::OnSound - Start");
		#endif

		switch ( ctrl )
		{
			case CarSoundCtrl.DOORS:
				float newValue = 0;

				if ( GetCarDoorsState( "uazdriverdoor" ) == CarDoorState.DOORS_CLOSED )
				{
					newValue += 0.4;
				}

				if ( GetCarDoorsState( "uazcodriverdoor" ) == CarDoorState.DOORS_CLOSED )
				{
					newValue += 0.4;
				}

				if ( GetCarDoorsState( "uazcargo1door" ) == CarDoorState.DOORS_CLOSED )
				{
					newValue += 0.4;
				}

				if ( GetCarDoorsState( "uazcargo2door" ) == CarDoorState.DOORS_CLOSED )
				{
					newValue += 0.4;
				}

				if ( newValue > 1 )
					newValue = 1;

				#ifdef EXPANSIONEXPRINT
				EXPrint("Vehicle_ExpansionUAZ::OnSound - End");
				#endif

				return newValue;
			default:
				break;
		}

		#ifdef EXPANSIONEXPRINT
		EXPrint("Vehicle_ExpansionUAZ::OnSound - End");
		#endif
		
		return oldValue;
	}

	// ------------------------------------------------------------
	override bool CanReachDoorsFromSeat( string pDoorsSelection, int pCurrentSeat )
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("Vehicle_ExpansionUAZ::CanReachDoorsFromSeat");
		#endif

		switch( pCurrentSeat )
		{
			case 0: {
				if (pDoorsSelection == "uazdriverdoor")
				{
					return true;
				}
				break;
			}
			case 1: {
				if (pDoorsSelection == "uazcodriverdoor")
				{
					return true;
				}
				break;
			}
			case 2: {
				if (pDoorsSelection == "uazcargo1door")
				{
					return true;
				}
				break;
			}
			case 3: {
				if (pDoorsSelection == "uazcargo2door")
				{
					return true;
				}
				break;
			}
		}	
		return false;	
	}

	// ------------------------------------------------------------
	override string GetAnimSourceFromSelection( string selection )
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("Vehicle_ExpansionUAZ::GetAnimSourceFromSelection");
		#endif
		switch( selection )
		{
			case "uazdriverdoor":
				return "uazdriverdoor";
			case "uazcodriverdoor":
				return "uazcodriverdoor";
			case "uazcargo1door":
				return "uazcargo1door";
			case "uazcargo2door":
				return "uazcargo2door";	
			case "uaztrunkdoor":
				return "uaztrunkdoor";	
		}

		return "";
	}

	// ------------------------------------------------------------
	override bool CrewCanGetThrough( int posIdx )
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("Vehicle_ExpansionUAZ::CrewCanGetThrough");
		#endif

		switch( posIdx )
		{
			case 0: {
				if ( GetAnimationPhase("uazdriverdoor") > 0 ) {
					return true;
				}
				if ( FindAttachmentBySlotName("uazdriverdoor") == NULL ) 
					return true;
				
				break;
			}
			case 1: {
				if ( GetAnimationPhase("uazcodriverdoor") > 0 ) {
					return true;
				}
				if ( FindAttachmentBySlotName("uazcodriverdoor") == NULL ) 
					return true;
				
				break;
			}
			case 2: {
				if ( GetAnimationPhase("uazcargo1door") > 0 ) {
					return true;
				}
				if ( FindAttachmentBySlotName("uazcargo1door") == NULL ) 
					return true;
				
				break;
			}
			case 3: {
				if ( GetAnimationPhase("uazcargo2door") > 0 ) {
					return true;
				}
				if ( FindAttachmentBySlotName("uazcargo2door") == NULL ) 
					return true;
				
				break;
			}
		}

		return false;
	}

	// ------------------------------------------------------------
	override bool IsVitalCarBattery()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("Vehicle_ExpansionUAZ::IsVitalCarBattery");
		#endif
		
		return true;
	}

	// ------------------------------------------------------------
	override bool IsVitalTruckBattery()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("Vehicle_ExpansionUAZ::IsVitalTruckBattery");
		#endif

		return false;
	}

	// ------------------------------------------------------------
	override bool IsVitalSparkPlug()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("Vehicle_ExpansionUAZ::IsVitalSparkPlug");
		#endif

		return true;
	}
	
	// ------------------------------------------------------------
	override bool IsVitalRadiator()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("Vehicle_ExpansionUAZ::IsVitalRadiator");
		#endif

		return false;
	}
	
	// ------------------------------------------------------------
	override bool IsVitalGlowPlug()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("Vehicle_ExpansionUAZ::IsVitalGlowPlug");
		#endif

		return false;
	}

	// ------------------------------------------------------------
	override bool IsVitalEngineBelt()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("Vehicle_ExpansionUAZ::IsVitalEngineBelt");
		#endif

		return false;
	}

	// ------------------------------------------------------------
	override bool CanObjectAttach( Object obj )
	{
		return false;
	}

	// ------------------------------------------------------------
	override bool LeavingSeatDoesAttachment( int posIdx )
	{
		// @CAMINOonPC#6971 Never implemented this after being told to for the past 3 months
		return false;
	}
};

class Vehicle_ExpansionUAZCargoRoofless extends Vehicle_ExpansionUAZ
{
	// ------------------------------------------------------------
	void Vehicle_ExpansionUAZCargoRoofless()
	{
		m_dmgContactCoef = 0.018;

		// GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( EOnInit, 10000, false );
	}

	// ------------------------------------------------------------
	/*override void EOnInit( IEntity other, int extra)
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionUAZCargoRoofless " + this + " EOnInit Start");
		#endif
	
		GetInventory().CreateAttachmentEx("ExpansionUAZDoorTrunk", InventorySlots.GetSlotIdFromString("uaztrunkdoor"));
	
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionUAZCargoRoofless " + this + " EOnInit Stop");
		#endif
	}*/

	// ------------------------------------------------------------
	override bool CanObjectAttach( Object obj )
	{
 		if ( vector.Distance( GetPosition(), obj.GetPosition() ) > m_BoundingRadius * 1.5 )
			return false;
		
		return true;
	}
};