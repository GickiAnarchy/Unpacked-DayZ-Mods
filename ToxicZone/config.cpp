class CfgPatches
{
	class ToxicZone_Script
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Characters",
			"DZ_Characters_Backpacks",
			"DZ_Characters_Pants",
			"DZ_Characters_Tops",
			"DZ_Gear_Containers",
			"DZ_Characters_Headgear",
			"DZ_Gear_Medical",
			"DZ_Data",
			"DZ_Structures_Military"
		};
	};
};
class CfgMods
{
	class MyDayZ_ToxicZone
	{
		dir="MyDayZ_ToxicZone";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="ToxicZone";
		credits="LaGTek,DmitriMedeleiv";
		author="DmitriMedeleiv";
		authorID="0";
		version="1.1";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"ToxicZone/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"ToxicZone/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"ToxicZone/scripts/5_Mission"
				};
			};
		};
	};
};
class CfgSlots
{
	class Slot_CharcoalTabTZ
	{
		name="CharcoalTabTZ";
		displayName="CharcoalTabTZ";
		ghostIcon="";
		show="false";
	};
};
class CfgVehicles
{
	class Edible_Base;
	class CharcoalTablets: Edible_Base
	{
		scope=2;
		displayName="$STR_CfgVehicles_CharcoalTablets0";
		descriptionShort="$STR_CfgVehicles_CharcoalTablets1";
		model="\dz\gear\medical\charcoal_tablets.p3d";
		rotationFlags=17;
		CanBeSplit=1;
		varQuantityInit=12;
		varQuantityMin=0;
		varQuantityMax=60;
		varQuantityDestroyOnMin=1;
		itemSize[]={1,2};
		weight=20;
		stackedUnit="pills";
		quantityBar=0;
		absorbency=0.89999998;
		inventorySlot[]=
		{
			"CharcoalTabTZ"
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
								"DZ\gear\medical\data\charcoal_tablets.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\charcoal_tablets.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\charcoal_tablets_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\charcoal_tablets_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\charcoal_tablets_destruct.rvmat"
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
				class Tablets_open
				{
					soundSet="Tablets_open_SoundSet";
					id=201;
				};
				class Tablets_catch
				{
					soundSet="Tablets_catch_SoundSet";
					id=202;
				};
				class Tablets_close
				{
					soundSet="Tablets_close_SoundSet";
					id=203;
				};
				class pickup
				{
					soundSet="purificationtablets_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="purificationtablets_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class Inventory_Base;
	class GP5GasMask_Filter: Inventory_Base
	{
		scope=2;
		displayName="GP5GasMask Filter";
		descriptionShort="Mask filter that can be attach to a GP5GasMask. A full filter provide 45 min of use";
		model="\DZ\characters\masks\GP5GasMask_filter.p3d";
		inventorySlot[]=
		{
			"GasMaskFilter"
		};
		rotationFlags=2;
		weight=200;
		itemSize[]={2,2};
		absorbency=0;
		heatIsolation=0.60000002;
		visibilityModifier=0.94999999;
		quantityBar=1;
		varQuantityInit=2700;
		varQuantityMin=0;
		varQuantityMax=2700;
		hiddenSelections[]=
		{
			"camoGround"
		};
		hiddenSelectionsTextures[]=
		{
			"\dz\characters\masks\data\GP5GasMask_white_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\masks\data\GP5GasMask.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\characters\masks\data\GP5GasMask.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\masks\data\GP5GasMask_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\characters\masks\data\GP5GasMask_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\characters\masks\data\GP5GasMask_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class Clothing;
	class GP5GasMask: Clothing
	{
		scope=2;
		displayName="$STR_CfgVehicles_GP5GasMask0";
		descriptionShort="A GasMask green to protect from radiation and toxic gas. Attach a filter to make it work. It provide 45 min of use.";
		model="\DZ\characters\masks\GP5GasMask_g.p3d";
		itemInfo[]=
		{
			"Clothing",
			"Mask"
		};
		rotationFlags=1;
		weight=1090;
		itemSize[]={3,3};
		absorbency=0;
		heatIsolation=0.60000002;
		visibilityModifier=0.94999999;
		noHelmet=0;
		attachments[]=
		{
			"GasMaskFilter"
		};
		class EnergyManager
		{
			autoSwitchOff=0;
			energyAtSpawn=15;
			energyStorageMax=100;
			energyUsagePerSecond=1;
			updateInterval=59;
		};
		headSelectionsToHide[]=
		{
			"Clipping_GP5GasMask"
		};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\dz\characters\masks\data\GP5GasMask_white_co.paa",
			"\dz\characters\masks\data\GP5GasMask_white_co.paa",
			"\dz\characters\masks\data\GP5GasMask_white_co.paa"
		};
		class ClothingTypes
		{
			male="\DZ\characters\masks\GP5GasMask_m.p3d";
			female="\DZ\characters\masks\GP5GasMask_f.p3d";
		};
		class Protection
		{
			biological=1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="DarkMotoHelmet_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="DarkMotoHelmet_drop_SoundSet";
					id=898;
				};
			};
		};
		soundVoiceType="gasmask";
		soundVoicePriority=5;
	};
	class GasMask: GP5GasMask
	{
		scope=2;
		displayName="$STR_CfgVehicles_GasMask0";
		descriptionShort="A GasMask green to protect from radiation and toxic gas. Attach charcoals tablets to make it work. Each pill provide 1 min of use";
		model="\DZ\characters\masks\GasMask_g.p3d";
		inventorySlot="Mask";
		itemInfo[]=
		{
			"Clothing",
			"Mask"
		};
		rotationFlags=2;
		weight=730;
		itemSize[]={3,4};
		heatIsolation=0.5;
		visibilityModifier=0.89999998;
		noHelmet=0;
		WorkingTimePerPills=60;
		attachments[]=
		{
			"CharcoalTabTZ"
		};
		class EnergyManager
		{
			autoSwitchOff=0;
			energyAtSpawn=15;
			energyStorageMax=100;
			energyUsagePerSecond=1;
			updateInterval=55;
		};
		headSelectionsToHide[]=
		{
			"Clipping_Gasmask"
		};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\dz\characters\masks\data\GasMask_co.paa",
			"\dz\characters\masks\data\GasMask_co.paa",
			"\dz\characters\masks\data\GasMask_co.paa"
		};
		class ClothingTypes
		{
			male="\DZ\characters\masks\GasMask_m.p3d";
			female="\DZ\characters\masks\GasMask_f.p3d";
		};
		class Protection
		{
			biological=1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="DarkMotoHelmet_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="DarkMotoHelmet_drop_SoundSet";
					id=898;
				};
			};
		};
		soundVoiceType="gasmask";
		soundVoicePriority=5;
	};
	class Container_Base;
	class ToxicCase: Container_Base
	{
		scope=2;
		descriptionShort="A Case Found in the Toxic Zone";
		model="\ToxicZone\ToxicCase\ToxicCase.p3d";
		displayName="ToxicCase";
		weight=10000;
		heavyItem=2;
		itemSize[]={50,50};
		carveNavmesh=1;
		rotationFlags=2;
		class Cargo
		{
			itemsCargoSize[]={10,50};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
	};
	class HouseNoDestruct;
	class GreenSmokeLong: HouseNoDestruct
	{
		scope=2;
		displayName="SMOKE";
		model="\dz\weapons\explosives\smokegrenade_rdg2.p3d";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class GreySmokeLong: HouseNoDestruct
	{
		scope=2;
		displayName="SMOKE";
		model="\dz\weapons\explosives\smokegrenade_rdg2.p3d";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class RedSmokeLong: HouseNoDestruct
	{
		scope=2;
		displayName="SMOKE";
		model="\dz\weapons\explosives\smokegrenade_rdg2.p3d";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class BlueSmokeLong: HouseNoDestruct
	{
		scope=2;
		displayName="SMOKE";
		model="\dz\weapons\explosives\smokegrenade_rdg2.p3d";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class WhiteSmokeLong: HouseNoDestruct
	{
		scope=2;
		displayName="SMOKE";
		model="\dz\weapons\explosives\smokegrenade_rdg2.p3d";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class GreenSmoke2Long: HouseNoDestruct
	{
		scope=2;
		displayName="SMOKE";
		model="\dz\weapons\explosives\smokegrenade_rdg2.p3d";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class MustardSmokeLong: HouseNoDestruct
	{
		scope=2;
		displayName="SMOKE";
		model="\dz\weapons\explosives\smokegrenade_rdg2.p3d";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class GreenSmoke: HouseNoDestruct
	{
		scope=2;
		displayName="SMOKE";
		model="\dz\weapons\explosives\smokegrenade_rdg2.p3d";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class MustardSmoke: HouseNoDestruct
	{
		scope=2;
		displayName="SMOKE";
		model="\dz\weapons\explosives\smokegrenade_rdg2.p3d";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class WhiteSmoke: HouseNoDestruct
	{
		scope=2;
		displayName="SMOKE";
		model="\dz\weapons\explosives\smokegrenade_rdg2.p3d";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class GreenSmoke2: HouseNoDestruct
	{
		scope=2;
		displayName="SMOKE";
		model="\dz\weapons\explosives\smokegrenade_rdg2.p3d";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class GreySmoke: HouseNoDestruct
	{
		scope=2;
		displayName="SMOKE";
		model="\dz\weapons\explosives\smokegrenade_rdg2.p3d";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class BlueSmoke: HouseNoDestruct
	{
		scope=2;
		displayName="SMOKE";
		model="\dz\weapons\explosives\smokegrenade_rdg2.p3d";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class RedSmoke: HouseNoDestruct
	{
		scope=2;
		displayName="SMOKE";
		model="\dz\weapons\explosives\smokegrenade_rdg2.p3d";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class PurpleSmoke: HouseNoDestruct
	{
		scope=2;
		displayName="SMOKE";
		model="\dz\weapons\explosives\smokegrenade_rdg2.p3d";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class ToxicBarrel: HouseNoDestruct
	{
		scope=2;
		displayName="Toxic Barrel";
		model="\dz\gear\containers\55galDrum.p3d";
		descriptionShort="Custom Toxic Barrel The Toxic Zone For Freeland";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\Images\ToxicBarrel.paa"
		};
	};
	class Grenade_Base;
	class ToxicM18SmokeGrenade_ColorBase: Grenade_Base
	{
		displayName="$STR_CfgVehicles_M18SmokeGrenade_ColorBase0";
		descriptionShort="$STR_CfgVehicles_M18SmokeGrenade_ColorBase1";
		model="\dz\weapons\explosives\smokegrenade.p3d";
		rotationFlags=17;
		lootTag[]=
		{
			"Military_west"
		};
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\weapons\explosives\data\smokegrenade.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\weapons\explosives\data\smokegrenade.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\explosives\data\smokegrenade.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\explosives\data\smokegrenade_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\explosives\data\smokegrenade_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\explosives\data\smokegrenade_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class EnergyManager
		{
			energyAtSpawn=90;
			energyUsagePerSecond=1;
			wetnessExposure=0.1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Unpin
				{
					soundSet="SmokegGrenades_M18_oneshot_ignite_SoundSet";
					id=201;
				};
			};
		};
	};
	class ToxicM18SmokeGrenade_Red: ToxicM18SmokeGrenade_ColorBase
	{
		scope=2;
		displayName="ToxicM18SmokeGrenade_Red";
		descriptionShort="After activation, a toxic gaz is spreading on a 8 meter radius. The only way to avoid getting sick is to wear a GasMask";
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\images\toxicgrenade_red_co.paa"
		};
	};
	class ToxicM18SmokeGrenade_Green: ToxicM18SmokeGrenade_ColorBase
	{
		scope=2;
		displayName="ToxicM18SmokeGrenade_Green";
		descriptionShort="After activation, a toxic gaz is spreading on a 8 meter radius. The only way to avoid getting sick is to wear a GasMask";
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\images\toxicgrenade_green_co.paa"
		};
	};
	class ToxicM18SmokeGrenade_Purple: ToxicM18SmokeGrenade_ColorBase
	{
		scope=2;
		displayName="ToxicM18SmokeGrenade_Purple";
		descriptionShort="After activation, a toxic gaz is spreading on a 8 meter radius. The only way to avoid getting sick is to wear a GasMask";
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\images\toxicgrenade_violet_co.paa"
		};
	};
	class ToxicM18SmokeGrenade_Yellow: ToxicM18SmokeGrenade_ColorBase
	{
		scope=2;
		displayName="ToxicM18SmokeGrenade_Yellow";
		descriptionShort="After activation, a toxic gaz is spreading on a 8 meter radius. The only way to avoid getting sick is to wear a GasMask";
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\images\toxicgrenade_yellow_co.paa"
		};
	};
	class ToxicM18SmokeGrenade_White: ToxicM18SmokeGrenade_ColorBase
	{
		scope=2;
		displayName="ToxicM18SmokeGrenade_White";
		descriptionShort="After activation, a toxic gaz is spreading on a 8 meter radius. The only way to avoid getting sick is to wear a GasMask";
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\images\toxicgrenade_white_co.paa"
		};
	};
	class Epinephrine;
	class ToxicCure: Epinephrine
	{
		scope=2;
		displayName="Toxic cure";
		descriptionShort="Cure for Toxic sickness";
		model="\dz\gear\medical\Epinephrine.p3d";
		SingleUseActions[]={1998,1999};
		rotationFlags=17;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\images\ToxicCure.paa",
			"ToxicZone\images\ToxicCure.paa",
			"ToxicZone\images\ToxicCure.paa"
		};
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=1;
		itemSize[]={1,2};
		weight=60;
		lootTag[]=
		{
			"Medic"
		};
		lootCategory="Medical";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\epipen.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\epipen.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\epipen_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\epipen_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\epipen_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class ToxicZoneGP5GasMask_black: GP5GasMask
	{
		displayName="GP5GasMask Black";
		descriptionShort="A GP5GasMask green to protect from radiation and toxic gas. Attach a filter to make it work. It provide 45 min of use.";
		scope=2;
		model="\DZ\characters\masks\GP5GasMask_g.p3d";
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\NBC\GP5Gasmask_black.paa",
			"ToxicZone\NBC\GP5Gasmask_black.paa",
			"ToxicZone\NBC\GP5Gasmask_black.paa"
		};
	};
	class ToxicZoneGP5GasMask_green: GP5GasMask
	{
		displayName="GP5GasMask Green";
		descriptionShort="A GP5GasMask green to protect from radiation and toxic gas. Attach a filter to make it work. It provide 45 min of use.";
		scope=2;
		visibilityModifier=0.39999998;
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\NBC\GP5Gasmask_green.paa",
			"ToxicZone\NBC\GP5Gasmask_green.paa",
			"ToxicZone\NBC\GP5Gasmask_green.paa"
		};
	};
	class NBCHoodBase;
	class ToxicZoneSuits_Hood_black: NBCHoodBase
	{
		displayName="NBC Black Hood";
		descriptionShort="A Black NBC Pants to protect from radiation and toxic gas";
		scope=2;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\NBC\Hood_black.paa",
			"ToxicZone\NBC\Hood_black.paa",
			"ToxicZone\NBC\Hood_black.paa"
		};
	};
	class ToxicZoneSuits_Hood_green: NBCHoodBase
	{
		displayName="NBC Green Hood";
		descriptionShort="A NBC Green Hood to protect from radiation and toxic gas";
		scope=2;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\NBC\Hood_green.paa",
			"ToxicZone\NBC\Hood_green.paa",
			"ToxicZone\NBC\Hood_green.paa"
		};
	};
	class ToxicZoneSuits_Hood_yellow: NBCHoodBase
	{
		displayName="NBC Yellow Hood";
		descriptionShort="A Yellow NBC Hood to protect from radiation and toxic gas";
		scope=2;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\NBC\Hood_yellow.paa",
			"ToxicZone\NBC\Hood_yellow.paa",
			"ToxicZone\NBC\Hood_yellow.paa"
		};
	};
	class NBCJacketBase;
	class ToxicZoneSuits_Jacket_black: NBCJacketBase
	{
		displayName="NBC Black Jacket";
		descriptionShort="A Black NBC Jacket to protect from radiation and toxic gas";
		scope=2;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={5,4};
		repairableWithKits[]={8,2};
		repairCosts[]={30,25};
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\NBC\Jacket_black.paa",
			"ToxicZone\NBC\Jacket_black.paa",
			"ToxicZone\NBC\Jacket_black.paa"
		};
	};
	class ToxicZoneSuits_Jacket_green: NBCJacketBase
	{
		displayName="NBC Green Jacket";
		descriptionShort="A NBC Green Jacket to protect from radiation and toxic gas";
		scope=2;
		visibilityModifier=0.39999998;
		itemsCargoSize[]={5,4};
		repairableWithKits[]={8,2};
		repairCosts[]={30,25};
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\NBC\Jacket_green.paa",
			"ToxicZone\NBC\Jacket_green.paa",
			"ToxicZone\NBC\Jacket_green.paa"
		};
	};
	class ToxicZoneSuits_Jacket_yellow: NBCJacketBase
	{
		displayName="NBC Yellow Jacket";
		descriptionShort="A Yellow NBC Jacket to protect from radiation and toxic gas";
		scope=2;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={5,4};
		repairableWithKits[]={8,2};
		repairCosts[]={30,25};
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\NBC\Jacket_yellow.paa",
			"ToxicZone\NBC\Jacket_yellow.paa",
			"ToxicZone\NBC\Jacket_yellow.paa"
		};
	};
	class NBCPantsBase;
	class ToxicZoneSuits_Pants_black: NBCPantsBase
	{
		displayName="NBC Black Pant";
		descriptionShort="A Black NBC Pants to protect from radiation and toxic gas";
		scope=2;
		visibilityModifier=0.69999999;
		repairableWithKits[]={5,2};
		itemsCargoSize[]={5,4};
		repairCosts[]={30,25};
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\NBC\Pants_black.paa",
			"ToxicZone\NBC\Pants_black.paa",
			"ToxicZone\NBC\Pants_black.paa"
		};
	};
	class ToxicZoneSuits_Pants_green: NBCPantsBase
	{
		displayName="NBC Green Pant";
		descriptionShort="A Green NBC Pants to protect from radiation and toxic gas";
		scope=2;
		visibilityModifier=0.39999998;
		repairableWithKits[]={5,2};
		itemsCargoSize[]={5,4};
		repairCosts[]={30,25};
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\NBC\Pants_green.paa",
			"ToxicZone\NBC\Pants_green.paa",
			"ToxicZone\NBC\Pants_green.paa"
		};
	};
	class ToxicZoneSuits_Pants_yellow: NBCPantsBase
	{
		displayName="NBC Yellow Pant";
		descriptionShort="A Yellow NBC Pants to protect from radiation and toxic gas";
		scope=2;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={5,4};
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\NBC\Pants_yellow.paa",
			"ToxicZone\NBC\Pants_yellow.paa",
			"ToxicZone\NBC\Pants_yellow.paa"
		};
	};
	class NBCBootsBase;
	class ToxicZoneSuits_Boots_black: NBCBootsBase
	{
		displayName="NBC Black Shoes";
		descriptionShort="A Black NBC Shoes to protect from radiation and toxic gas";
		scope=2;
		visibilityModifier=0.69999999;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\NBC\Boots_black.paa",
			"ToxicZone\NBC\Boots_black.paa",
			"ToxicZone\NBC\Boots_black.paa"
		};
	};
	class ToxicZoneSuits_Boots_green: NBCBootsBase
	{
		displayName="NBC Green Shoes";
		descriptionShort="A Green NBC Shoes to protect from radiation and toxic gas";
		scope=2;
		visibilityModifier=0.39999998;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\NBC\Boots_green.paa",
			"ToxicZone\NBC\Boots_green.paa",
			"ToxicZone\NBC\Boots_green.paa"
		};
	};
	class ToxicZoneSuits_Boots_yellow: NBCBootsBase
	{
		displayName="NBC Yellow Shoes";
		descriptionShort="A Yellow NBC Shoes to protect from radiation and toxic gas";
		scope=2;
		visibilityModifier=0.69999999;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\NBC\Boots_yellow.paa",
			"ToxicZone\NBC\Boots_yellow.paa",
			"ToxicZone\NBC\Boots_yellow.paa"
		};
	};
	class NBCGloves_ColorBase;
	class ToxicZoneSuits_Gloves_yellow: NBCGloves_ColorBase
	{
		displayName="NBC Yellow Gloves";
		descriptionShort="A Yellow NBC Gloves to protect from radiation and toxic gas";
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\NBC\Gloves_yellow.paa",
			"ToxicZone\NBC\Gloves_yellow.paa",
			"ToxicZone\NBC\Gloves_yellow.paa"
		};
	};
	class ToxicZoneSuits_Gloves_black: NBCGloves_ColorBase
	{
		displayName="NBC Black Gloves";
		descriptionShort="A Black NBC Gloves to protect from radiation and toxic gas";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\NBC\Gloves_black.paa",
			"ToxicZone\NBC\Gloves_black.paa",
			"ToxicZone\NBC\Gloves_black.paa"
		};
	};
	class ToxicZoneSuits_Gloves_green: NBCGloves_ColorBase
	{
		displayName="NBC Green Gloves";
		descriptionShort="A Green NBC Gloves to protect from radiation and toxic gas";
		scope=2;
		visibilityModifier=0.39999998;
		hiddenSelectionsTextures[]=
		{
			"ToxicZone\NBC\Gloves_green.paa",
			"ToxicZone\NBC\Gloves_green.paa",
			"ToxicZone\NBC\Gloves_green.paa"
		};
	};
};
