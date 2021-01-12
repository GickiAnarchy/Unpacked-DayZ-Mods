////////////////////////////////////////////////////////////////////
//DeRap: OP_BaseItems\Assets\DirtMound\config.bin
//Produced from mikero's Dos Tools Dll version 7.89
//https://mikero.bytex.digital/Downloads
//'now' is Tue Jan 12 10:46:17 2021 : 'file' last modified on Thu Nov 19 09:23:12 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class OP_Dirtmound
	{
		units[] = {"Dirtmound"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Gear_Tools","DZ_Rocks"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class HouseNoDestruct;
	class Dirtmound: HouseNoDestruct
	{
		scope = 2;
		model = "OP_BaseItems\Assets\Dirtmound\Dirtmoundnew.p3d";
		storageCategory = 1;
		lootCategory = "Crafted";
		useEntityHierarchy = "true";
		slopeTolerance = 0.3;
		alignHologramToTerain = 1;
		yawPitchRollLimit[] = {10,10,10};
		hologramMaterial = "tile";
		hologramMaterialPath = "dz\gear\cultivation\data";
	};
};
