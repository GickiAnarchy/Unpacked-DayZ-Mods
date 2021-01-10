class CfgPatches
{
	class DP_Bags
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Tools"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;

	class DP_CocaBag: Inventory_Base
	{
		scope=2;
		displayName="Baggy of cocaine.";
		descriptionShort="About an ounce of the finest cocaine.";
		model="\DZ\gear\tools\Heatpack.p3d";
		rotationFlags=17;
		canBeSplit=1;
		lootCategory="Crafted";
		weight=28;
		itemSize[]={2,2};
		absorbency=0.2;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=35;
		varQuantityDestroyOnMin=1;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"DrugsPLUS\bags\data\coca_bag_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=30;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\tools\data\heat_pack.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\tools\data\heat_pack.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\tools\data\heat_pack_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\tools\data\heat_pack_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\tools\data\heat_pack_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="pickUpBloodBag_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="bloodbag_drop_SoundSet";
					id=898;
				};
			};
		};

	};
};
