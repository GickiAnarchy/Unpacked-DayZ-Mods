////////////////////////////////////////////////////////////////////
//DeRap: OP_BaseItems\Assets\Banner_ColorBase\config.bin
//Produced from mikero's Dos Tools Dll version 7.89
//https://mikero.bytex.digital/Downloads
//'now' is Tue Jan 12 10:46:17 2021 : 'file' last modified on Thu Nov 19 09:23:10 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class BannerColorBase
	{
		units[] = {"Banner_Colorbase","OP_CamoNetNatoBanner","OP_CamoNetEastBanner","OP_UCPBanner","OP_WoodlandBanner","OP_BannerMount","OP_BannermountPlacing"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Structures_Military","DZ_Gear_Camping"};
	};
};
class CfgSlots
{
	class Slot_Banner
	{
		name = "Banner";
		displayName = "Banner";
		ghostIcon = "Shoulder";
		show = "true";
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class Banner_Colorbase: Inventory_Base
	{
		scope = 2;
		displayName = "BannerBase";
		description = "Attach to a banner mount!";
		model = "OP_Baseitems\Assets\Banner_ColorBase\OP_Banner_g.p3d";
		inventorySlot[] = {"Banner"};
		itemSize[] = {3,2};
		hiddenSelections[] = {"frontside","backside","frontsideground","backsideground"};
		hiddenSelectionsMaterials[] = {"OP_Baseitems\Assets\Banner_ColorBase\data\banner.rvmat","OP_Baseitems\Assets\Banner_ColorBase\data\banner.rvmat","OP_Baseitems\Assets\Banner_ColorBase\data\bannernowind.rvmat","OP_Baseitems\Assets\Banner_ColorBase\data\bannernowind.rvmat"};
		class AnimationSources
		{
			class Attached
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
		};
	};
	class OP_CamoNetNatoBanner: Banner_Colorbase
	{
		displayName = "Camonet Nato Banner";
		hiddenSelectionsTextures[] = {"DZ\structures\military\Improvised\data\camonet_nato_co.paa","DZ\structures\military\Improvised\data\camonet_nato_co.paa","DZ\structures\military\Improvised\data\camonet_nato_co.paa","DZ\structures\military\Improvised\data\camonet_nato_co.paa"};
	};
	class OP_CamoNetEastBanner: Banner_Colorbase
	{
		displayName = "Camonet East Banner";
		hiddenSelectionsTextures[] = {"DZ\structures\military\Improvised\data\camonet_east_co.paa","DZ\structures\military\Improvised\data\camonet_east_co.paa","DZ\structures\military\Improvised\data\camonet_east_co.paa","DZ\structures\military\Improvised\data\camonet_east_co.paa"};
	};
	class OP_UCPBanner: Banner_Colorbase
	{
		displayName = "UCP Camo Banner";
		hiddenSelectionsTextures[] = {"OP_Baseitems\Assets\Banner_Colorbase\data\BannerUCP_co.paa","OP_Baseitems\Assets\Banner_Colorbase\data\BannerUCP_co.paa","OP_Baseitems\Assets\Banner_Colorbase\data\BannerUCP_co.paa","OP_Baseitems\Assets\Banner_Colorbase\data\BannerUCP_co.paa"};
	};
	class OP_WoodlandBanner: Banner_Colorbase
	{
		displayName = "Woodland Camo Banner";
		hiddenSelectionsTextures[] = {"OP_Baseitems\Assets\Banner_Colorbase\data\bannerwoodland_co.paa","OP_Baseitems\Assets\Banner_Colorbase\data\bannerwoodland_co.paa","OP_Baseitems\Assets\Banner_Colorbase\data\bannerwoodland_co.paa","OP_Baseitems\Assets\Banner_Colorbase\data\bannerwoodland_co.paa"};
		hiddenSelectionsMaterials[] = {"OP_Baseitems\Assets\Banner_ColorBase\data\bannernowind.rvmat","OP_Baseitems\Assets\Banner_ColorBase\data\bannernowind.rvmat"};
	};
	class OP_BannerMount: Container_Base
	{
		scope = 2;
		displayName = "BannerMount";
		descriptionShort = "Attach a banner";
		model = "\OP_Baseitems\Assets\Banner_Colorbase\OP_Bannermount.p3d";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		slopeTolerance = 0.25;
		hiddenSelectionsTextures[] = {};
		hiddenSelectionsMaterials[] = {};
		openable = 0;
		carveNavmesh = 1;
		itemSize[] = {8,4};
		itemsCargoSize[] = {10,10};
		itemBehaviour = 2;
		lootCategory = "Tents";
		attachments[] = {"Banner"};
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
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
		class GUIInventoryAttachmentsProps
		{
			class Banner
			{
				name = "Banner";
				description = "";
				attachmentSlots[] = {"Banner"};
				icon = "cat_camonet";
				view_index = 1;
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
			class Banner
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
		};
	};
	class OP_BannermountPlacing: OP_BannerMount
	{
		model = "\OP_Baseitems\Assets\Banner_Colorbase\OP_BannermountPlacing.p3d";
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
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxySpawnItemBanner: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"Banner"};
		model = "\OP_Baseitems\Assets\Banner_ColorBase\proxies\spawnitembanner.p3d";
	};
};
