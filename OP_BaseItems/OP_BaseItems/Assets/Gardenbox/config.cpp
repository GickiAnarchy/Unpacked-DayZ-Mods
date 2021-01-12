////////////////////////////////////////////////////////////////////
//DeRap: OP_BaseItems\Assets\Gardenbox\config.bin
//Produced from mikero's Dos Tools Dll version 7.89
//https://mikero.bytex.digital/Downloads
//'now' is Tue Jan 12 10:46:17 2021 : 'file' last modified on Thu Nov 19 09:23:13 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class OP_Gardenbox
	{
		units[] = {"Gardenbox","GardenboxEmpty","GardenpotEmpty","Gardenpot"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Gear_Cultivation","DZ_Structures_Residential"};
	};
};
class CfgVehicles
{
	class GardenPlot;
	class Inventory_Base;
	class HouseNoDestruct;
	class GardenboxEmpty: Inventory_Base
	{
		scope = 2;
		displayName = "Empty Garden Box";
		model = "OP_Baseitems\Assets\Gardenbox\GardenboxEmpty.p3d";
		storageCategory = 1;
		lootCategory = "Crafted";
		heavyItem = 1;
		useEntityHierarchy = "true";
		slopeTolerance = 0.3;
		alignHologramToTerain = 1;
		itemSize[] = {5,10};
		yawPitchRollLimit[] = {10,10,10};
		attachments[] = {"SeedBase_1","SeedBase_2","SeedBase_3"};
		class Cargo
		{
			itemsCargoSize[] = {0,0};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		class GUIInventoryAttachmentsProps
		{
			class Filling
			{
				name = "$STR_attachment_Filling0";
				description = "";
				attachmentSlots[] = {"SeedBase_1","SeedBase_2","SeedBase_3"};
				icon = "cat_gp_filling";
			};
		};
	};
	class GardenpotEmpty: Inventory_Base
	{
		scope = 2;
		displayName = "Empty Garden Pot";
		model = "OP_Baseitems\Assets\Gardenbox\GardenpotEmpty.p3d";
		storageCategory = 1;
		lootCategory = "Crafted";
		heavyItem = 1;
		useEntityHierarchy = "true";
		slopeTolerance = 0.3;
		alignHologramToTerain = 1;
		itemSize[] = {5,5};
		yawPitchRollLimit[] = {10,10,10};
		attachments[] = {"SeedBase_1"};
		class Cargo
		{
			itemsCargoSize[] = {0,0};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		class GUIInventoryAttachmentsProps
		{
			class Filling
			{
				name = "$STR_attachment_Filling0";
				description = "";
				attachmentSlots[] = {"SeedBase_1"};
				icon = "cat_gp_filling";
			};
		};
	};
	class Gardenpot: HouseNoDestruct
	{
		scope = 2;
		displayName = "Garden Box";
		model = "OP_Baseitems\Assets\Gardenbox\Gardenpot.p3d";
		storageCategory = 1;
		lootCategory = "Crafted";
		useEntityHierarchy = "true";
		slopeTolerance = 0.3;
		alignHologramToTerain = 1;
		physLayer = "item_small";
		yawPitchRollLimit[] = {10,10,10};
		attachments[] = {"SeedBase_1"};
		class GUIInventoryAttachmentsProps
		{
			class Filling
			{
				name = "$STR_attachment_Filling0";
				description = "";
				attachmentSlots[] = {"SeedBase_1"};
				icon = "cat_gp_filling";
			};
		};
		hiddenSelections[] = {"SeedBase_1","SeedBase_2","SeedBase_3","SeedBase_4","SeedBase_5","SeedBase_6","SeedBase_7","SeedBase_8","SeedBase_9","slotCovered_01","slotCovered_02","slotCovered_03","slotCovered_04","slotCovered_05","slotCovered_06","slotCovered_07","slotCovered_08","slotCovered_09","placing"};
		hiddenSelectionsTextures[] = {"dz\gear\cultivation\data\soil_cultivated_co.paa","dz\gear\cultivation\data\soil_cultivated_limed_CO.paa","dz\gear\cultivation\data\soil_cultivated_compost_CO.paa","","","","","","","","","","","","","","","","dz\gear\cultivation\data\tile_co.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","","","","","","","","","","dz\gear\cultivation\data\tile.rvmat"};
		hologramMaterial = "tile";
		hologramMaterialPath = "dz\gear\cultivation\data";
		class AnimationSources
		{
			class slotVisible
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class slotHidden: slotVisible
			{
				initPhase = 1;
			};
			class SeedBase_1: slotVisible{};
			class slotCovered_01: slotHidden{};
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
		};
	};
	class Gardenbox: HouseNoDestruct
	{
		scope = 2;
		displayName = "Garden Box";
		model = "OP_Baseitems\Assets\Gardenbox\Gardenbox.p3d";
		storageCategory = 1;
		lootCategory = "Crafted";
		useEntityHierarchy = "true";
		slopeTolerance = 0.3;
		alignHologramToTerain = 1;
		physLayer = "item_small";
		carveNavmesh = 0;
		yawPitchRollLimit[] = {10,10,10};
		attachments[] = {"SeedBase_1","SeedBase_2","SeedBase_3"};
		class GUIInventoryAttachmentsProps
		{
			class Filling
			{
				name = "$STR_attachment_Filling0";
				description = "";
				attachmentSlots[] = {"SeedBase_1","SeedBase_2","SeedBase_3"};
				icon = "cat_gp_filling";
			};
		};
		hiddenSelections[] = {"SeedBase_1","SeedBase_2","SeedBase_3","SeedBase_4","SeedBase_5","SeedBase_6","SeedBase_7","SeedBase_8","SeedBase_9","slotCovered_01","slotCovered_02","slotCovered_03","slotCovered_04","slotCovered_05","slotCovered_06","slotCovered_07","slotCovered_08","slotCovered_09","placing"};
		hiddenSelectionsTextures[] = {"dz\gear\cultivation\data\soil_cultivated_co.paa","dz\gear\cultivation\data\soil_cultivated_limed_CO.paa","dz\gear\cultivation\data\soil_cultivated_compost_CO.paa","","","","","","","","","","","","","","","","dz\gear\cultivation\data\tile_co.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","","","","","","","","","","dz\gear\cultivation\data\tile.rvmat"};
		hologramMaterial = "tile";
		hologramMaterialPath = "dz\gear\cultivation\data";
		class AnimationSources
		{
			class slotVisible
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class slotHidden: slotVisible
			{
				initPhase = 1;
			};
			class SeedBase_1: slotVisible{};
			class slotCovered_01: slotHidden{};
			class SeedBase_2: slotVisible{};
			class slotCovered_02: slotHidden{};
			class SeedBase_3: slotVisible{};
			class slotCovered_03: slotHidden{};
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
		};
	};
};
