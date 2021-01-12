////////////////////////////////////////////////////////////////////
//DeRap: OP_BaseItems\Assets\Building\config.bin
//Produced from mikero's Dos Tools Dll version 7.89
//https://mikero.bytex.digital/Downloads
//'now' is Tue Jan 12 10:46:17 2021 : 'file' last modified on Thu Nov 19 09:23:11 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class OP_BaseBuilding
	{
		units[] = {"Locker","OP_StorageCabinetBase","OP_StorageCabinetGrey","OP_StorageCabinetBlack","OP_StorageCabinetGreen","OP_Worktable","OP_Lockerblue","OP_StorageCabinetSmall"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Melee","DZ_Gear_Camping","DZ_Structures_Military","DZ_Structures_Furniture","DZ_Radio","DZ_Characters_Backpacks","DZ_Characters_Headgear","DZ_Spawn_Proxies","DZ_Gear_Tools","DZ_Weapons_Firearms_MosinNagant","DZ_Weapons_Firearms_AKM","DZ_Weapons_Firearms_cz61","DZ_Weapons_Firearms_IZH18","DZ_Weapons_Firearms_M4","DZ_Weapons_Firearms_MP5","DZ_Weapons_Firearms_SVD","DZ_Weapons_Firearms_UMP"};
	};
};
class CfgVehicles
{
	class Barrel_ColorBase;
	class HouseNoDescruct;
	class Container_Base;
	class Inventory_Base;
	class OP_Worktable: Container_Base
	{
		scope = 2;
		displayName = "WorkTable";
		storageCategory = 1;
		descriptionShort = "A worktable used to construct items.";
		model = "\OP_BaseItems\Assets\building\worktable.p3d";
		overrideDrawArea = "8.0";
		useEntityHierarchy = "true";
		attachments[] = {"Melee","Knife"};
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		quantityBar = 0;
		SingleUseActions[] = {527};
		InteractActions[] = {1025,1026};
		ContinuousActions[] = {155};
		carveNavmesh = 0;
		canBeDigged = 0;
		heavyItem = 1;
		weight = 250;
		itemSize[] = {10,15};
		itemBehaviour = 0;
		stackedUnit = "ml";
		randomQuantity = 2;
		liquidContainerType = "";
		varQuantityInit = 0;
		physLayer = "item_large";
		varQuantityMin = 0;
		varQuantityMax = 0;
		absorbency = 0.1;
		allowOwnedCargoManipulation = 1;
		lootTag[] = {"Work"};
		hiddenSelections[] = {"camoGround"};
		class Cargo
		{
			itemsCargoSize[] = {7,3};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		class GUIInventoryAttachmentsProps
		{
			class Tools
			{
				name = "Tools";
				description = "";
				attachmentSlots[] = {"Melee","Knife"};
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
	class Locker: Container_Base
	{
		scope = 2;
		storageCategory = 1;
		displayName = "Locker";
		model = "OP_BaseItems\Assets\Building\locker.p3d";
		overrideDrawArea = "8.0";
		forceFarBubble = "true";
		SingleUseActions[] = {527};
		InteractActions[] = {1025,1026,4343432,2334544};
		ContinuousActions[] = {155,32323322,6945849};
		attachments[] = {"Vest","Back","Headgear","Legs","Body","Melee","Shoulder","Gloves","Feet","Hips","CamoNet","WalkieTalkie","Att_CombinationLock","tripWireAttachment"};
		destroyOnEmpty = 0;
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
		class Cargo
		{
			itemsCargoSize[] = {10,7};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		class GUIInventoryAttachmentsProps
		{
			class Base
			{
				name = "Clothing";
				description = "";
				attachmentSlots[] = {"Body","Legs","Vest","Back","Headgear","Melee","Shoulder"};
				icon = "missing";
			};
			class Accessories
			{
				name = "Accessories";
				description = "";
				attachmentSlots[] = {"Gloves","Feet","Hips","WalkieTalkie"};
				icon = "missing";
			};
			class Lock
			{
				name = "Attachments";
				description = "";
				attachmentSlots[] = {"Att_CombinationLock","CamoNet"};
				icon = "missing";
			};
			class Traps
			{
				name = "Grenade Trap";
				description = "";
				attachmentSlots[] = {"tripWireAttachment"};
				icon = "missing";
			};
		};
		class AnimationSources
		{
			class Lid1
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Lid3
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.01;
			};
			class Camonet
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Lockerbag
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.01;
			};
			class Grenadewire
			{
				source = "user";
				initPhase = 1;
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
	class OP_Lockerblue: Locker
	{
		model = "OP_BaseItems\Assets\Building\lockerblue.p3d";
	};
	class OP_StorageCabinetBase: Locker
	{
		scope = 2;
		displayName = "Storage Cabinet";
		descriptionShort = "A place to store stuff.";
		model = "OP_BaseItems\Assets\Building\OP_CabinetStorage.p3d";
		SingleUseActions[] = {527};
		itemsCargoSize[] = {10,50};
		InteractActions[] = {1025,1026,4343432,2334544};
		ContinuousActions[] = {155,32323322,453423};
		hiddenSelections[] = {"camoGround"};
		attachments[] = {"Att_CombinationLock"};
		class GUIInventoryAttachmentsProps
		{
			class Lock
			{
				name = "Attachments";
				description = "";
				attachmentSlots[] = {"Att_CombinationLock"};
				icon = "missing";
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {10,20};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		class AnimationSources
		{
			class Lid1
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1;
			};
			class Lid3
			{
				source = "user";
				initPhase = 1;
				animPeriod = 1;
			};
		};
	};
	class OP_StorageCabinetSmall: OP_StorageCabinetBase
	{
		scope = 2;
		displayName = "Storage Cabinet";
		descriptionShort = "A place to store stuff.";
		model = "OP_BaseItems\Assets\Building\CNET.p3d";
		SingleUseActions[] = {527};
		itemsCargoSize[] = {10,50};
		InteractActions[] = {1025,1026,4343432,2334544};
		ContinuousActions[] = {155,32323322,453423};
		hiddenSelections[] = {"camoGround"};
		attachments[] = {"Att_CombinationLock"};
		class GUIInventoryAttachmentsProps
		{
			class Lock
			{
				name = "Attachments";
				description = "";
				attachmentSlots[] = {"Att_CombinationLock"};
				icon = "missing";
			};
		};
		class AnimationSources
		{
			class Lid1
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1;
			};
			class Lid3
			{
				source = "user";
				initPhase = 1;
				animPeriod = 1;
			};
		};
	};
	class OP_StorageCabinetGrey: OP_StorageCabinetBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"OP_BaseItems\Assets\Building\Data\gunstoragegray_co.paa"};
	};
	class OP_StorageCabinetBlack: OP_StorageCabinetBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"OP_BaseItems\Assets\Building\Data\gunstorage_co.paa"};
	};
	class OP_StorageCabinetGreen: OP_StorageCabinetBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"OP_BaseItems\Assets\Building\Data\gunstoragegreen_co.paa"};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyspawnMeleeWeapon1: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Knife";
		model = "\OP_BaseItems\Assets\Building\Proxies\SpawnMeleeWeapon.p3d";
	};
	class ProxyspawnWeapon1: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Shoulder";
		model = "\OP_BaseItems\Assets\Building\Proxies\SpawnWeapon1.p3d";
	};
	class ProxyspawnShovel: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Melee";
		model = "\OP_BaseItems\Assets\Building\Proxies\spawnShovel.p3d";
	};
	class ProxyspawnItemClothing1: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Headgear";
		model = "\OP_BaseItems\Assets\Building\Proxies\SpawnItemClothing1.p3d";
	};
	class ProxyspawnItemBackpack1: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Back";
		model = "\OP_BaseItems\Assets\Building\Proxies\SpawnItemClothing1.p3d";
	};
	class ProxyspawnItemGloves1: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Gloves";
		model = "\OP_BaseItems\Assets\Building\Proxies\SpawnItemGloves1.p3d";
	};
	class ProxyspawnItemBoots: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Feet";
		model = "\OP_BaseItems\Assets\Building\Proxies\SpawnItemBoots.p3d";
	};
	class ProxyspawnItemWalkie: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "WalkieTalkie";
		model = "\OP_BaseItems\Assets\Building\Proxies\spawnItemWalkie.p3d";
	};
	class Proxyboxy: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "yomomma";
		model = "\DZ\gear\camping\wooden_case.p3d";
	};
};
