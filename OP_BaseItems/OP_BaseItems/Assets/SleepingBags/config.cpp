////////////////////////////////////////////////////////////////////
//DeRap: OP_BaseItems\Assets\SleepingBags\config.bin
//Produced from mikero's Dos Tools Dll version 7.89
//https://mikero.bytex.digital/Downloads
//'now' is Tue Jan 12 10:46:18 2021 : 'file' last modified on Thu Nov 19 09:23:18 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class OP_Sleepingbags
	{
		units[] = {"OP_SleepingBagCamo","OP_SleepingBagCamoPlacing","OP_SleepingBagBlue","OP_SleepingBagBluePlacing","OP_SleepingBagGrey","OP_SleepingBagGreyPlacing"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Gear_Camping"};
	};
};
class CfgVehicles
{
	class Container_Base;
	class OP_SleepingBagCamo: Container_Base
	{
		scope = 2;
		displayName = "Sleeping bag";
		descriptionShort = "$STR_CfgVehicles_MediumTent1";
		model = "\OP_Baseitems\Assets\Sleepingbags\OP_Sleepingbagcamo.p3d";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		slopeTolerance = 0.25;
		hiddenSelectionsTextures[] = {};
		hiddenSelectionsMaterials[] = {};
		openable = 0;
		carveNavmesh = 1;
		itemSize[] = {8,4};
		itemsCargoSize[] = {10,5};
		itemBehaviour = 2;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		repairableWithKits[] = {5,2};
		attachments[] = {};
		repairCosts[] = {30,25};
		SingleUseActions[] = {527};
		InteractActions[] = {1044125,1044124};
		ContinuousActions[] = {231};
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
		class AnimationSources
		{
			class Body
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Inventory
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Pack
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
		};
	};
	class OP_SleepingBagCamoPlacing: OP_SleepingBagCamo
	{
		model = "\OP_Baseitems\Assets\Sleepingbags\OP_SleepingBagCamoPlacing.p3d";
		storageCategory = 10;
		hiddenSelections[] = {"placing"};
		hologramMaterial = "car_tent";
		hologramMaterialPath = "dz\gear\camping\data";
		class AnimationSources
		{
			class Placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
	class OP_SleepingBagBlue: Container_Base
	{
		scope = 2;
		displayName = "Sleeping Bag";
		descriptionShort = ".";
		model = "\OP_Baseitems\Assets\Sleepingbags\OP_SleepingBagBlue.p3d";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		slopeTolerance = 0.25;
		hiddenSelectionsTextures[] = {};
		hiddenSelectionsMaterials[] = {};
		openable = 0;
		carveNavmesh = 1;
		itemSize[] = {8,4};
		itemsCargoSize[] = {10,5};
		itemBehaviour = 2;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		attachments[] = {};
		repairableWithKits[] = {5,2};
		repairCosts[] = {30,25};
		SingleUseActions[] = {527};
		InteractActions[] = {1044125,1044124};
		ContinuousActions[] = {231};
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
		class AnimationSources
		{
			class Body
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Inventory
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Pack
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
		};
	};
	class OP_SleepingBagBluePlacing: OP_SleepingBagBlue
	{
		model = "\OP_Baseitems\Assets\Sleepingbags\OP_SleepingBagBluePlacing.p3d";
		storageCategory = 10;
		hiddenSelections[] = {"placing"};
		hologramMaterial = "car_tent";
		hologramMaterialPath = "dz\gear\camping\data";
		class AnimationSources
		{
			class Placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
	class OP_SleepingBagGrey: Container_Base
	{
		scope = 2;
		displayName = "Sleeping Bag";
		descriptionShort = ".";
		model = "\OP_Baseitems\Assets\Sleepingbags\OP_SleepingBagGrey.p3d";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		slopeTolerance = 0.25;
		hiddenSelectionsTextures[] = {};
		hiddenSelectionsMaterials[] = {};
		openable = 0;
		carveNavmesh = 1;
		itemSize[] = {8,4};
		itemsCargoSize[] = {10,5};
		itemBehaviour = 2;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		attachments[] = {};
		repairableWithKits[] = {5,2};
		repairCosts[] = {30,25};
		SingleUseActions[] = {527};
		InteractActions[] = {1044125,1044124};
		ContinuousActions[] = {231};
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
		class AnimationSources
		{
			class Body
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Inventory
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Pack
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
		};
	};
	class OP_SleepingBagGreyPlacing: OP_SleepingBagGrey
	{
		model = "\OP_Baseitems\Assets\Sleepingbags\OP_SleepingBagGreyPlacing.p3d";
		storageCategory = 10;
		hiddenSelections[] = {"placing"};
		hologramMaterial = "car_tent";
		hologramMaterialPath = "dz\gear\camping\data";
		class AnimationSources
		{
			class Placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
};
