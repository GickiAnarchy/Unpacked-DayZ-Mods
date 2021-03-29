#define _ARMA_

class CfgPatches
{
	class DayZExpansion_Vehicles_Air_Gyro
	{
		units[] = {"ExpansionGyrocopterWreck","ExpansionGyrocopter","Vehicle_ExpansionGyrocopter"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DayZExpansion_Core"};
	};
};
class CfgVehicles
{
	class CarScript;
	class Inventory_Base;
	class ExpansionWreck;
	class CarDoor;
	class SimulationModule;
	class Axles;
	class Front;
	class Wheels;
	class Rear;
	class Left;
	class Right;
	class AnimationSources;
	class Crew;
	class Driver;
	class CoDriver;
	class ExpansionHelicopterScript;
	class ExpansionVehicleHelicopterBase;
	class GUIInventoryAttachmentsProps;
	class Body;
	class DamageSystem;
	class DamageZones;
	class GlobalHealth;
	class HatchbackDoors_Driver;
	class Suspension;
	class ExpansionGyrocopterWreck: ExpansionWreck
	{
		scope = 2;
		displayname = "$STR_EXPANSION_VEHICLE_GYROCOPTER";
		model = "DayZExpansion\Vehicles\Air\Gyro\GyrocopterWreck.p3d";
		class Cargo
		{
			itemsCargoSize[] = {5,2};
		};
	};
	class ExpansionGyrocopter: ExpansionHelicopterScript
	{
		scope = 2;
		displayname = "$STR_EXPANSION_VEHICLE_GYROCOPTER";
		model = "DayZExpansion\Vehicles\Air\Gyro\Gyrocopter.p3d";
		vehicleClass = "Expansion_Helicopter";
		fuelCapacity = 50;
		fuelConsumption = 31;
		attachments[] = {"ExpansionHelicopterBattery","Reflector_1_1","SparkPlug"};
		class GUIInventoryAttachmentsProps
		{
			class Engine
			{
				name = "$STR_attachment_Engine0";
				description = "";
				icon = "cat_vehicle_engine";
				attachmentSlots[] = {"ExpansionHelicopterBattery","SparkPlug"};
			};
			class Body
			{
				name = "$STR_attachment_Body0";
				description = "";
				icon = "cat_vehicle_body";
				attachmentSlots[] = {"Reflector_1_1"};
			};
		};
		class AnimationSources
		{
			class rotor
			{
				source = "user";
				animPeriod = 0.025;
				initPhase = 0;
			};
			class rear_rotor
			{
				source = "user";
				animPeriod = 0.025;
				initPhase = 0;
			};
			class hiderotor
			{
				source = "user";
				animPeriod = 0.0009999999;
				initPhase = 0;
			};
			class hiderotorblur
			{
				source = "user";
				animPeriod = 0.0009999999;
				initPhase = 0;
			};
			class cyclicForward
			{
				source = "user";
				animPeriod = 0.25;
				initPhase = 0;
			};
			class cyclicAside
			{
				source = "user";
				animPeriod = 0.25;
				initPhase = 0;
			};
		};
		class Sounds
		{
			thrust = 0.6;
			thrustTurbo = 1;
			thrustGentle = 0.3;
			thrustSmoothCoef = 0.1;
			camposSmoothCoef = 0.03;
			soundSetsFilter[] = {"Expansion_Gyro_Engine_Ext_SoundSet","Expansion_Gyro_Rotor_Ext_SoundSet"};
			soundSetsInt[] = {"Expansion_Gyro_Engine_Int_SoundSet","Expansion_Gyro_Rotor_Int_SoundSet"};
		};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2750;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class Crew: Crew
		{
			class Driver: Driver
			{
				actionSel = "seat_driver";
				proxyPos = "crewDriver";
				getInPos = "pos driver";
				getInDir = "pos driver dir";
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {5,2};
			allowOwnedCargoManipulation = 1;
			openable = 0;
		};
		class SimulationModule: SimulationModule
		{
			maxSpeed = 100;
			altitudeFullForce = 1000;
			altitudeNoForce = 2000;
			bodyFrictionCoef = 4.0;
			liftForceCoef = 1.6;
			bankForceCoef = 0.1;
			tailForceCoef = 8.0;
			linearFrictionCoef[] = {16.0,0.04,0.04};
			angularFrictionCoef = 1.5;
			class Rotor
			{
				minAutoRotateSpeed = 2.0;
				maxAutoRotateSpeed = 10.0;
				startUpTime = 5.0;
			};
			class AntiTorque
			{
				speed = 1.5;
				max = 0.04;
			};
			class Cyclic
			{
				forceCoefficient = 1.5;
				class Forward
				{
					speed = 10.0;
					max = 1.0;
					coefficient = 0.3;
					animation = "cyclicForward";
				};
				class Side
				{
					speed = 10.0;
					max = 1.0;
					coefficient = 0.3;
					animation = "cyclicAside";
				};
			};
		};
	};
	class Vehicle_ExpansionGyrocopter: ExpansionVehicleHelicopterBase
	{
		scope = 2;
		displayname = "[NOT READY]  GYROCOPTER";
		model = "DayZExpansion\Vehicles\Air\Gyro\Gyrocopter.p3d";
		vehicleClass = "Expansion_Helicopter";
		fuelCapacity = 50;
		fuelConsumption = 31;
		attachments[] = {"ExpansionHelicopterBattery","Reflector_1_1","SparkPlug"};
		class GUIInventoryAttachmentsProps
		{
			class Engine
			{
				name = "$STR_attachment_Engine0";
				description = "";
				icon = "cat_vehicle_engine";
				attachmentSlots[] = {"ExpansionHelicopterBattery","SparkPlug"};
			};
			class Body
			{
				name = "$STR_attachment_Body0";
				description = "";
				icon = "cat_vehicle_body";
				attachmentSlots[] = {"Reflector_1_1"};
			};
		};
		class AnimationSources
		{
			class rotor
			{
				source = "user";
				animPeriod = 0.025;
				initPhase = 0;
			};
			class rear_rotor
			{
				source = "user";
				animPeriod = 0.025;
				initPhase = 0;
			};
			class hiderotor
			{
				source = "user";
				animPeriod = 0.0009999999;
				initPhase = 0;
			};
			class hiderotorblur
			{
				source = "user";
				animPeriod = 0.0009999999;
				initPhase = 0;
			};
			class cyclicForward
			{
				source = "user";
				animPeriod = 0.25;
				initPhase = 0;
			};
			class cyclicAside
			{
				source = "user";
				animPeriod = 0.25;
				initPhase = 0;
			};
		};
		class Sounds
		{
			thrust = 0.6;
			thrustTurbo = 1;
			thrustGentle = 0.3;
			thrustSmoothCoef = 0.1;
			camposSmoothCoef = 0.03;
			soundSetsFilter[] = {"Expansion_Gyro_Engine_Ext_SoundSet","Expansion_Gyro_Rotor_Ext_SoundSet"};
			soundSetsInt[] = {"Expansion_Gyro_Engine_Int_SoundSet","Expansion_Gyro_Rotor_Int_SoundSet"};
		};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2750;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class Crew: Crew
		{
			class Driver: Driver
			{
				actionSel = "seat_driver";
				proxyPos = "crewDriver";
				getInPos = "pos driver";
				getInDir = "pos driver dir";
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {5,2};
			allowOwnedCargoManipulation = 1;
			openable = 0;
		};
		class SimulationModule: SimulationModule
		{
			maxSpeed = 100;
			altitudeFullForce = 1000;
			altitudeNoForce = 2000;
			bodyFrictionCoef = 4.0;
			liftForceCoef = 1.6;
			bankForceCoef = 0.1;
			tailForceCoef = 8.0;
			linearFrictionCoef[] = {16.0,0.04,0.04};
			angularFrictionCoef = 1.5;
			class Rotor
			{
				minAutoRotateSpeed = 2.0;
				maxAutoRotateSpeed = 10.0;
				startUpTime = 5.0;
			};
			class AntiTorque
			{
				speed = 1.5;
				max = 0.04;
			};
			class Cyclic
			{
				forceCoefficient = 1.5;
				class Forward
				{
					speed = 10.0;
					max = 1.0;
					coefficient = 0.3;
					animation = "cyclicForward";
				};
				class Side
				{
					speed = 10.0;
					max = 1.0;
					coefficient = 0.3;
					animation = "cyclicAside";
				};
			};
		};
	};
};
