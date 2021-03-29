class CfgPatches
{
	class DevilsDandruff
	{
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Characters",
			"DZ_Characters_Vests",
			"DZ_Characters_Tops",
			"DZ_Characters_Pants",
			"DZ_Characters_Gloves",
			"DZ_Characters_Headgear",
			"DZ_Characters_Shoes",
			"DZ_Characters_Backpacks",
			"DZ_Characters_Belts",
			"DZ_Gear_Containers",
			"DZ_Data","DZ_Scripts",
			"DZ_characters_masks",
			"DZ_Gear_Cultivation",
			"DZ_Weapons_Melee",
			"DZ_Gear_Consumables"
			};
		units[] = {
			"DevilsDandruff_Poppy_Plant",
			"DevilsDandruff_CocaineBrick",
			"DevilsDandruff_CocaineRocks"
			};
		weapons[] = {};
	};
};

class CfgMods
{
	class Cocaine_Scripts
	{
		dir = "";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 1;
		name = "DevilsDandruff";
		credits = "";
		author = "OneLargeMammal";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[]=
		{
			"World",
			"Game",
			"Mission"
		};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[]=
				{
					"DevilsDandruff\scripts\4_world"
				};
			};
		};
	};
};

class CfgVehicles
{
	class DisinfectantAlcohol;
	class GardenLime;
	class Inventory_Base;
	class DevilsDandruff_Poppy_Plant: Inventory_Base
	{
		scope=2;
		displayName="Poppy Plant";
		descriptionShort="Yes I know, technically this is an opium poppy that is the base to make heroine. We're using this instead as it looks way cooler than a boring coca bush which is the true base of cocaine. Go gather 20 poppies, find a bag of Pablo's cutting agent, combine in hand to produce 5 raw rocks of Devils Dandruff.";
		model="DevilsDandruff\assets\poppy\poppyplant.p3d";
		itemSize[]={1,3};
		canBeSplit=1;
		varQuantityInit=20;
		varQuantityDestroyOnMin=1;
		varQuantityMin=0;
		varQuantityMax=20;
		stackedUnit="";
	};
	class DevilsDandruff_CocaineBrick: Inventory_Base
	{
		scope=2;
		displayName="Key of Charlie";
		descriptionShort="A brick of top quality, uncut Devil's Dandruff. Bitch, this weight ain't gonna move itself. Now smuggle this shit to the Black Market trader for a large payday.";
		model="DevilsDandruff\assets\brick\brick.p3d";
		itemSize[]={4,4};
	};
	class DevilsDandruff_CocaineRocks: Inventory_Base
	{
		scope=2;
		displayName="Raw White Rocks";
		descriptionShort="Rocks of raw, unprocessed Snow White. Produce 100 rocks and combine with a bottle of Sulfuric Acid in hand to produce a key of the finest pure white Colombian nose candy. Giddy up.";
		model="DevilsDandruff\assets\rocks\rocks.p3d";
		itemSize[]={1,1};
		canBeSplit=1;
		varQuantityInit=100;
		varQuantityDestroyOnMin=1;
		varQuantityMin=0;
		varQuantityMax=100;
		stackedUnit="";
	};
	class CuttingAgent: GardenLime
	{
		scope = 2;
		displayName= "Cutting Agent";
		descriptionShort= "Pablo Escobar's secret cutting agent. Its the secret herbs and spices that makes his charlie the best. Combine with 20 poppies in hand to produce 5 raw rocks.";
		repairableWithKits[] = {};
		repairCosts[] = {};
		visibilityModifier = 0.95;
		hiddenSelections[] = {"zbytek","camo"};
		hiddenSelectionsTextures[] = 
		{
			"DevilsDandruff\data\pablos_cutting_agent.paa",
			"DevilsDandruff\data\pablos_cutting_agent.paa",
			"DevilsDandruff\data\pablos_cutting_agent.paa",
			"DevilsDandruff\data\pablos_cutting_agent.paa",
			"DevilsDandruff\data\pablos_cutting_agent.paa"
		};
	};
	class SulfuricAcid: DisinfectantAlcohol
	{
		scope = 2;
		displayName= "Sulfuric Acid";
		descriptionShort= "A bottle of Sulfuric Acid. The final ingredient needed to turn raw rocks into world class Charlie. Combine with 100 rocks in hand to produce a key of pure Devils Dandruff.";
		repairableWithKits[] = {};
		repairCosts[] = {};
		visibilityModifier = 0.95;
		hiddenSelections[] = {"zbytek","camo"};
		hiddenSelectionsTextures[] = 
		{
			"DevilsDandruff\data\sulfuric_acid.paa",
			"DevilsDandruff\data\sulfuric_acid.paa",
			"DevilsDandruff\data\sulfuric_acid.paa",
			"DevilsDandruff\data\sulfuric_acid.paa",
			"DevilsDandruff\data\sulfuric_acid.paa"
		};
	};
};