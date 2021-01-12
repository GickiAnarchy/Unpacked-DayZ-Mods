////////////////////////////////////////////////////////////////////
//DeRap: OP_BaseItems\Assets\Lock\config.bin
//Produced from mikero's Dos Tools Dll version 7.89
//https://mikero.bytex.digital/Downloads
//'now' is Tue Jan 12 10:46:17 2021 : 'file' last modified on Thu Nov 19 09:23:14 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class OP_Lock
	{
		units[] = {"OPLock"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class CombinationLock;
	class OPLock: Inventory_Base
	{
		scope = 2;
		displayName = "Lock";
		descriptionShort = "Lock";
		model = "OP_BaseItems\Assets\Lock\Padlock.p3d";
		SingleUseActions[] = {575,464542423};
		ContinuousActions[] = {3353542};
		inventorySlot = "Att_CombinationLock";
		rotationFlags = 34;
		itemSize[] = {3,3};
		weight = 350;
	};
};
