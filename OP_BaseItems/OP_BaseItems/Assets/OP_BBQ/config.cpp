////////////////////////////////////////////////////////////////////
//DeRap: OP_BaseItems\Assets\OP_BBQ\config.bin
//Produced from mikero's Dos Tools Dll version 7.89
//https://mikero.bytex.digital/Downloads
//'now' is Tue Jan 12 10:46:18 2021 : 'file' last modified on Thu Nov 19 09:23:15 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class OP_BBQ_Food
	{
		units[] = {"OP_Charcoal","OP_Charc_BBQ"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Scripts","DZ_Gear_Cooking","DZ_Gear_Food"};
	};
};
class CfgSlots
{
	class Slot_Ingredient;
	class Slot_Charcoal
	{
		name = "OP_Charcoal";
		displayName = "OP_Charcoal";
		ghostIcon = "gascanister";
	};
	class Slot_Ingredient1: Slot_Ingredient
	{
		name = "Ingredient1";
		displayName = "Ingredient1";
		ghostIcon = "ingredient";
	};
	class Slot_Ingredient2: Slot_Ingredient
	{
		name = "Ingredient2";
		displayName = "Ingredient2";
		ghostIcon = "ingredient";
	};
	class Slot_Ingredient3: Slot_Ingredient
	{
		name = "Ingredient3";
		displayName = "Ingredient3";
		ghostIcon = "ingredient";
	};
	class Slot_Ingredient4: Slot_Ingredient
	{
		name = "Ingredient4";
		displayName = "Ingredient4";
		ghostIcon = "ingredient";
	};
	class Slot_Ingredient5: Slot_Ingredient
	{
		name = "Ingredient5";
		displayName = "Ingredient5";
		ghostIcon = "ingredient";
	};
	class Slot_Ingredient6: Slot_Ingredient
	{
		name = "Ingredient6";
		displayName = "Ingredient6";
		ghostIcon = "ingredient";
	};
	class Slot_Ingredient7: Slot_Ingredient
	{
		name = "Ingredient7";
		displayName = "Ingredient7";
		ghostIcon = "ingredient";
	};
	class Slot_Ingredient8: Slot_Ingredient
	{
		name = "Ingredient8";
		displayName = "Ingredient8";
		ghostIcon = "ingredient";
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyMeat_steak;
	class ProxyOP_Charcoal: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "OP_Charcoal";
		model = "\OP_BaseItems\Assets\OP_BBQ\charcoalsack.p3d";
	};
	class ProxyBBQ_steak1: ProxyMeat_steak
	{
		inventorySlot = "Ingredient1";
		model = "\OP_Baseitems\Assets\OP_BBQ\proxies\BBQ_Steak1.p3d";
	};
	class ProxyBBQ_steak2: ProxyMeat_steak
	{
		inventorySlot = "Ingredient2";
		model = "\OP_Baseitems\Assets\OP_BBQ\proxies\BBQ_Steak2.p3d";
	};
	class ProxyBBQ_steak3: ProxyMeat_steak
	{
		inventorySlot = "Ingredient3";
		model = "\OP_Baseitems\Assets\OP_BBQ\proxies\BBQ_Steak3.p3d";
	};
	class ProxyBBQ_steak4: ProxyMeat_steak
	{
		inventorySlot = "Ingredient4";
		model = "\OP_Baseitems\Assets\OP_BBQ\proxies\BBQ_Steak4.p3d";
	};
	class ProxyBBQ_steak5: ProxyMeat_steak
	{
		inventorySlot = "Ingredient5";
		model = "\OP_Baseitems\Assets\OP_BBQ\proxies\BBQ_Steak5.p3d";
	};
	class ProxyBBQ_steak6: ProxyMeat_steak
	{
		inventorySlot = "Ingredient6";
		model = "\OP_Baseitems\Assets\OP_BBQ\proxies\BBQ_Steak6.p3d";
	};
	class ProxyBBQ_steak7: ProxyMeat_steak
	{
		inventorySlot = "Ingredient7";
		model = "\OP_Baseitems\Assets\OP_BBQ\proxies\BBQ_Steak7.p3d";
	};
	class ProxyBBQ_steak8: ProxyMeat_steak
	{
		inventorySlot = "Ingredient8";
		model = "\OP_Baseitems\Assets\OP_BBQ\proxies\BBQ_Steak8.p3d";
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class OP_Charcoal: Inventory_Base
	{
		scope = 2;
		displayName = "Charcoal Sack";
		descriptionShort = "A Charcoal sack for the Charcoal grill.";
		model = "\OP_BaseItems\Assets\OP_BBQ\charcoalsack.p3d";
		weight = 340;
		itemSize[] = {4,3};
		inventorySlot = "OP_Charcoal";
		lootCategory = "Tools";
		lootTag[] = {"Civilian","Camping"};
		rotationflags = 17;
		stackedUnit = "w";
		quantityBar = 1;
		varQuantityInit = 50;
		varQuantityMin = 0;
		varQuantityMax = 50;
		class EnergyManager
		{
			switchOnAtSpawn = 1;
			isPassiveDevice = 1;
			energyStorageMax = 1500;
			energyUsagePerSecond = 0;
			energyAtSpawn = 1500;
			powerSocketsCount = 1;
			compatiblePlugTypes[] = {7};
			convertEnergyToQuantity = 1;
		};
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
	};
	class OP_Charc_BBQ: Inventory_Base
	{
		scope = 2;
		displayName = "Charcoal BBQ";
		descriptionShort = "Grab the bros - Requires a Charcoal bag for fuel and an ignition source.";
		model = "\OP_BaseItems\Assets\OP_BBQ\Charc_Grill.p3d";
		rotationFlags = 2;
		openable = 0;
		heavyItem = 1;
		carveNavmesh = 0;
		lootTag[] = {"Camping"};
		lootCategory = "Tools";
		weight = 170;
		itemSize[] = {8,8};
		varTemperatureMax = 250;
		absorbency = 0.3;
		physLayer = "item_large";
		attachments[] = {"Ingredient1","Ingredient2","Ingredient3","Ingredient4","Ingredient5","Ingredient6","Ingredient7","Ingredient8","OP_Charcoal"};
		class GUIInventoryAttachmentsProps
		{
			class Grill
			{
				name = "Grill";
				description = "";
				attachmentSlots[] = {"Ingredient1","Ingredient2","Ingredient3","Ingredient4","Ingredient5","Ingredient6","Ingredient7","Ingredient8"};
				icon = "cat_fp_cooking";
			};
			class Fuel
			{
				name = "Charcoal";
				description = "";
				attachmentSlots[] = {"OP_Charcoal"};
				icon = "gascanister";
			};
		};
		hiddenSelections[] = {"coals","ashes"};
		hiddenSelectionsTextures[] = {"DZ\gear\cooking\data\log01burned_co.paa","dz\gear\cooking\data\stoneground_co.paa"};
		hiddenSelectionsMaterials[] = {"DZ\gear\cooking\data\log02burnednoemit.rvmat","dz\gear\cooking\data\stonegroundnoemit.rvmat"};
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
		class AnimationSources
		{
			class lid1
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.01;
			};
			class lid2
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class charbag
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class coals
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
		};
		class EnergyManager
		{
			switchOnAtSpawn = 0;
			autoSwitchOff = 1;
			autoSwitchOffWhenInCargo = 1;
			energyStorageMax = 0;
			energyUsagePerSecond = 1;
			energyAtSpawn = 0;
			powerSocketsCount = 0;
			plugType = 7;
			attachmentAction = 1;
		};
	};
};
