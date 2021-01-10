class CfgPatches
{
	class DP_Fruits
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Food"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class DP_CocaLeaves: Inventory_Base
	{
		scope=2;
		displayName="Coca Leaves";
		descriptionShort="A handful of coca leaves.";
		model="\dz\gear\food\cannabis_seedman.p3d";
		rotationFlags=34;
		lootCategory="Crafted";
		weight=14;
		itemSize[]={1,1};
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"DrugsPLUS\fruits\data\coca_seedman_raw_co.paa",
			"DrugsPLUS\fruits\data\coca_seedman_baked_co.paa",
			"DrugsPLUS\fruits\data\coca_seedman_raw_co.paa",
			"DrugsPLUS\fruits\data\coca_seedman_raw_co.paa",
			"DrugsPLUS\fruits\data\coca_seedman_baked_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DrugsPLUS\fruits\data\coca_seedman_raw.rvmat",
			"DrugsPLUS\fruits\data\coca_seedman_baked.rvmat",
			"DrugsPLUS\fruits\data\coca_seedman_raw.rvmat",
			"DrugsPLUS\fruits\data\coca_seedman_dried.rvmat",
			"DrugsPLUS\fruits\data\coca_seedman_burnt.rvmat",
			"DrugsPLUS\fruits\data\coca_seedman_rotten.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet="openTunaCan_SoundSet";
					id=204;
				};
				class pickUpItem
				{
					soundSet="Zucchini_pickup_SoundSet";
					id=797;
				};
				class Eating_TakeFood
				{
					soundSet="Eating_TakeFood_Soundset";
					id=889;
				};
				class Eating_BoxOpen
				{
					soundSet="Eating_BoxOpen_Soundset";
					id=893;
				};
				class Eating_BoxShake
				{
					soundSet="Eating_BoxShake_Soundset";
					id=894;
				};
				class Eating_BoxEnd
				{
					soundSet="Eating_BoxEnd_Soundset";
					id=895;
				};
			};
		};
	};
};
