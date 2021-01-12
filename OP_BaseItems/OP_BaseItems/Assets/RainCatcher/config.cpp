////////////////////////////////////////////////////////////////////
//DeRap: OP_BaseItems\Assets\RainCatcher\config.bin
//Produced from mikero's Dos Tools Dll version 7.89
//https://mikero.bytex.digital/Downloads
//'now' is Tue Jan 12 10:46:18 2021 : 'file' last modified on Thu Nov 19 09:23:18 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class OP_Raincatcher
	{
		units[] = {"OP_Raincatcher","OP_RaincatcherKit","OP_Tarp"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Gear_Crafting","DZ_Gear_Consumables"};
	};
};
class CfgSlots
{
	class Slot_Waterbarrel
	{
		name = "Waterbarrel";
		displayName = "Waterbarrel";
		ghostIcon = "Waterbarrel";
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxywatertank: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Waterbarrel";
		model = "\OP_Baseitems\Assets\RainCatcher\watertank.p3d";
	};
};
class CfgVehicles
{
	class Container_Base;
	class Bottle_Base;
	class Inventory_Base;
	class OP_Raincatcher: Container_Base
	{
		scope = 2;
		displayName = "Rain Catcher";
		descriptionShort = "Attach a Waterbarrel and receive water when it rains";
		model = "\OP_Baseitems\Assets\RainCatcher\OP_Raincatcher.p3d";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		lootCategory = "Crafted";
		carveNavmesh = 1;
		weight = 10000;
		itemSize[] = {6,6};
		physLayer = "item_large";
		rotationFlags = 2;
		attachments[] = {"Waterbarrel"};
		itemBehaviour = 0;
		absorbency = 0.1;
	};
	class OP_RaincatcherKit: Inventory_Base
	{
		scope = 2;
		displayName = "Rain Catcher Kit";
		descriptionShort = "Attach a Waterbarrel and receive water when it rains";
		model = "\OP_Baseitems\Assets\RainCatcher\Raincatcherkit.p3d";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		rotationFlags = 17;
		itemSize[] = {1,5};
		weight = 280;
		itemBehaviour = 1;
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Inventory: AnimSourceHidden{};
			class Placing: AnimSourceHidden{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class crafting_1
				{
					soundSet = "FenceKit_crafting_1_SoundSet";
					id = 1111;
				};
				class crafting_2
				{
					soundSet = "FenceKit_crafting_2_SoundSet";
					id = 1112;
				};
				class crafting_3
				{
					soundSet = "FenceKit_crafting_3_SoundSet";
					id = 1113;
				};
				class crafting_4
				{
					soundSet = "FenceKit_crafting_4_SoundSet";
					id = 1114;
				};
				class crafting_5
				{
					soundSet = "FenceKit_crafting_5_SoundSet";
					id = 1115;
				};
			};
		};
	};
	class OP_Tarp: Inventory_Base
	{
		scope = 2;
		displayName = "Blue Tarp";
		description = "Used to craft an improvised rain catcher - To make Craft this item with wooden sticks";
		model = "OP_Baseitems\Assets\RainCatcher\OP_Tarp_g.p3d";
		itemSize[] = {3,2};
	};
};
