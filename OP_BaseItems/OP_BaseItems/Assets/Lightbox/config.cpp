////////////////////////////////////////////////////////////////////
//DeRap: OP_BaseItems\Assets\Lightbox\config.bin
//Produced from mikero's Dos Tools Dll version 7.89
//https://mikero.bytex.digital/Downloads
//'now' is Tue Jan 12 10:46:17 2021 : 'file' last modified on Thu Nov 19 09:23:13 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class OP_Lightbox
	{
		units[] = {"OP_Lightbox","OP_Lightbox_AlwaysOn"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Scripts","DZ_Gear_Camping","DZ_Gear_Cultivation"};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class OP_Lightbox: HouseNoDestruct
	{
		scope = 2;
		displayName = "Lightbox";
		descriptionShort = "Lightbox";
		model = "\OP_BaseItems\Assets\Lightbox\Lightbox.p3d";
		carveNavmesh = 0;
		openable = 0;
		physLayer = "item_large";
		varQuantityInit = 1000;
		varQuantityMin = 0;
		varQuantityMax = 20;
		varQuantityDestroyOnMin = 0;
		hiddenSelections[] = {"lightinner"};
		hiddenSelectionsTextures[] = {"\OP_BaseItems\Assets\Lightbox\data\lightint_co.paa"};
		hiddenSelectionsMaterials[] = {"\OP_BaseItems\Assets\Lightbox\data\lightboxlight.rvmat"};
		class EnergyManager
		{
			energyAtSpawn = 20000;
			energyUsagePerSecond = 1;
			updateInterval = 5;
			convertEnergyToQuantity = 1;
		};
	};
	class OP_Lightbox_AlwaysOn: OP_Lightbox{};
};
