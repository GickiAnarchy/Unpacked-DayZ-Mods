////////////////////////////////////////////////////////////////////
//DeRap: OP_BaseItems\Assets\WoodStorage\config.bin
//Produced from mikero's Dos Tools Dll version 7.89
//https://mikero.bytex.digital/Downloads
//'now' is Tue Jan 12 10:46:19 2021 : 'file' last modified on Thu Nov 19 09:23:20 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class OP_WoodStorage
	{
		units[] = {"WoodStorage"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Gear_Camping"};
	};
};
class CfgVehicles
{
	class Container_Base;
	class WoodStorage: Container_Base
	{
		scope = 2;
		displayName = "WoodStorage";
		model = "OP_BaseItems\Assets\Woodstorage\WoodStorage.p3d";
		SingleUseActions[] = {527};
		InteractActions[] = {1025,1026};
		ContinuousActions[] = {155};
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		quantityBar = 0;
		varQuantityMax = 0;
		carveNavmesh = 1;
		canBeDigged = 0;
		heavyItem = 1;
		weight = 10000;
		itemSize[] = {10,15};
		itemBehaviour = 0;
		physLayer = "item_large";
		allowOwnedCargoManipulation = 1;
		lootTag[] = {"Work"};
		hiddenSelections[] = {"camoGround"};
		storageCategory = 1;
		attachments[] = {"Material_WoodenLogs","Material_L1_WoodenLogs","Material_L2_WoodenLogs","Material_L3_WoodenLogs","Material_WoodenPlanks","Material_L1_WoodenPlanks","Material_L1W1_WoodenPlanks","Material_L1W2_WoodenPlanks","Material_L1W3_WoodenPlanks","Material_L2_WoodenPlanks","Firewood","WoodenStick","Rags"};
		class GUIInventoryAttachmentsProps
		{
			class Log_Storage
			{
				name = "Log Storage";
				description = "";
				attachmentSlots[] = {"Material_WoodenLogs","Material_L1_WoodenLogs","Material_L2_WoodenLogs","Material_L3_WoodenLogs"};
				icon = "missing";
			};
			class Plank_Storage
			{
				name = "Plank_Storage";
				description = "";
				attachmentSlots[] = {"Material_WoodenPlanks","Material_L1_WoodenPlanks","Material_L1W1_WoodenPlanks","Material_L1W2_WoodenPlanks","Material_L1W3_WoodenPlanks","Material_L2_WoodenPlanks"};
				icon = "missing";
			};
			class FireWood
			{
				name = "FireWood";
				description = "";
				attachmentSlots[] = {"Firewood","WoodenStick","Rags"};
				icon = "missing";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement
				{
					soundSet = "seachest_movement_SoundSet";
					id = 1;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpSeaChest_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpSeaChest_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "seachest_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
};
