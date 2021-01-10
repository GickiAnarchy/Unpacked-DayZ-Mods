class CfgPatches
{
	class DP_Bricks
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Containers"
		};
	};
};

class CfgVehicles
{
	class Container_Base;
	class DP_CocaBrick: Container_Base
	{	
		scope=2;
		displayName="Brick of Cocaine";
		descriptionShort="One kilo of cocaine.";
		model="\dz\gear\containers\FirstAidKit.p3d";
		rotationFlags=17;
		//canBeSplit=1;
		lootCategory="Crafted";
		weight=1000;
		itemSize[]={4,4};
		absorbency=0.2;
		//varQuantityInit=1;
		//varQuantityMin=0;
		//varQuantityMax=16;
		//varQuantityDestroyOnMin=1;
		isMeleeWeapon=1;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"DrugsPLUS\bricks\data\coca_brick_co.paa"
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
								"DrugsPLUS\bricks\data\coca_brick.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DrugsPLUS\bricks\data\coca_brick.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DrugsPLUS\bricks\data\coca_brick_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DrugsPLUS\bricks\data\coca_brick_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DrugsPLUS\bricks\data\coca_brick_destruct.rvmat"
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
				class pickUpItem_Light
				{
					soundSet="pickUpCourierBag_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCourierBag_SoundSet";
					id=797;
				};
			};
		};
	};
};
