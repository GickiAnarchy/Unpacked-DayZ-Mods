////////////////////////////////////////////////////////////////////
//DeRap: OP_BaseItems\Assets\WaterBarrel\config.bin
//Produced from mikero's Dos Tools Dll version 7.89
//https://mikero.bytex.digital/Downloads
//'now' is Tue Jan 12 10:46:19 2021 : 'file' last modified on Thu Nov 19 09:23:19 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class OP_Water
	{
		units[] = {"Waterbarrelcomplete","Waterbarrel","BarrelFrame"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Bottle_Base;
	class Waterbarrelcomplete: Bottle_Base
	{
		scope = 2;
		displayName = "Waterbarrel Kit";
		descriptionShort = "A waterbarrel";
		model = "\OP_Baseitems\Assets\Waterbarrel\watertankcomplete.p3d";
		overrideDrawArea = "8.0";
		forceFarBubble = "true";
		SingleUseActions[] = {527};
		InteractActions[] = {1025,1026};
		ContinuousActions[] = {155};
		slopeTolerance = 0.3;
		attachments[] = {};
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		quantityBar = 1;
		carveNavmesh = 1;
		canBeDigged = 0;
		heavyItem = 1;
		weight = 10000;
		itemSize[] = {10,15};
		itemBehaviour = 0;
		stackedUnit = "ml";
		randomQuantity = 1;
		liquidContainerType = "1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit = 0.0;
		varQuantityMin = 0.0;
		varQuantityMax = 10000.0;
		absorbency = 0.1;
		physLayer = "item_large";
		allowOwnedCargoManipulation = 1;
		lootTag[] = {"Work"};
		class GUIInventoryAttachmentsProps{};
		class Cargo
		{
			itemsCargoSize[] = {};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		class AnimationSources
		{
			class WaterBarrel
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.01;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement
				{
					soundSet = "barrel_movement_SoundSet";
					id = 1;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpBarrelLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpBarrel_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "barrel_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class Waterbarrel: Bottle_Base
	{
		scope = 2;
		displayName = "Waterbarrel";
		descriptionShort = "Combine with Waterbarrel frame or Rain procurement kit";
		model = "\OP_Baseitems\Assets\Waterbarrel\watertank.p3d";
		overrideDrawArea = "8.0";
		useEntityHierarchy = "true";
		itemSize[] = {5,5};
		weight = 25;
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		inventoryslot = "Waterbarrel";
		varLiquidTypeInit = 512;
		liquidContainerType = "1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 10000;
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class WaterBottle_in_B
				{
					soundSet = "WaterBottle_in_B_SoundSet";
					id = 202;
				};
				class WaterBottle_in_C
				{
					soundSet = "WaterBottle_in_C_SoundSet";
					id = 203;
				};
				class WaterBottle_in_C1
				{
					soundSet = "WaterBottle_in_C1_SoundSet";
					id = 204;
				};
				class WaterBottle_out_A
				{
					soundSet = "WaterBottle_out_A_SoundSet";
					id = 205;
				};
				class WaterBottle_out_B
				{
					soundSet = "WaterBottle_out_B_SoundSet";
					id = 206;
				};
				class WellPond_loop
				{
					soundSet = "WellPond_loop_SoundSet";
					id = 209;
				};
				class WellBottle_loop
				{
					soundSet = "WellBottle_loop_SoundSet";
					id = 210;
				};
				class pickup
				{
					soundSet = "WaterBottle_pickup_SoundSet";
					id = 797;
				};
			};
		};
	};
	class BarrelFrame: Inventory_Base
	{
		scope = 2;
		displayName = "WaterBarrelFrame";
		descriptionShort = "Combine with Waterbarrel for a Water kit";
		model = "\OP_Baseitems\Assets\Waterbarrel\Barrelframe.p3d";
		overrideDrawArea = "8.0";
		useEntityHierarchy = "true";
		itemSize[] = {5,5};
	};
};
