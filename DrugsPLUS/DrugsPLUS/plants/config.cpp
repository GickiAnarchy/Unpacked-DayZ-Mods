class CfgPatches
{
	class DP_Plants
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Cultivation"
		};
	};
};
class CfgHorticulture
{
	class Plants
	{
		class DP_Plant_Coca
		{
			infestedTex="dz\gear\cultivation\data\cannabis_plant_insect_co.paa";
			infestedMat="dz\gear\cultivation\data\cannabis_plant_insect.rvmat";
			healthyTex="dz\gear\cultivation\data\cannabis_plant_co.paa";
			healthyMat="dz\gear\cultivation\data\cannabis_plant.rvmat";
		};
	};
};
class CfgVehicles
{
	class PlantBase;
	class DP_Plant_Coca: PlantBase
	{
		scope=2;
		model="DZ\gear\cultivation\Cannabis_plant.p3d";
		displayName="Coca Plant";
		descriptionShort="A coca plant.";
		hiddenSelections[]=
		{
			"plantstage_03",
			"plantstage_02",
			"plantstage_04",
			"plantstage_05",
			"plantstage_01",
			"infestedparts"
		};
		hiddenSelectionsTextures[]=
		{
			"DrugsPLUS\plants\data\coca_plant_co.paa",
			"DrugsPLUS\plants\data\coca_plant_co.paa",
			"DrugsPLUS\plants\data\coca_plant_co.paa",
			"DrugsPLUS\plants\data\coca_plant_co.paa",
			"DrugsPLUS\plants\data\coca_plant_co.paa",
			"DrugsPLUS\plants\data\coca_plant_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\cultivation\data\Cannabis_plant.rvmat"
		};
		class Horticulture
		{
			GrowthStagesCount=6;
			CropsType="DP_CocaLeaves";
		};
	};
};
