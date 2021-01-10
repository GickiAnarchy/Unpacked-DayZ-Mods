////////////////////////////////////////////////////////////////////
//DeRap: CodeLock\config.bin
//Produced from mikero's Dos Tools Dll version 7.89
//https://mikero.bytex.digital/Downloads
//'now' is Wed Dec 16 03:33:47 2020 : 'file' last modified on Wed Nov 25 13:44:11 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class CodeLock
	{
		requiredAddons[] = {};
		units[] = {};
		weapons[] = {};
	};
};
class CfgMods
{
	class CodeLock
	{
		type = "mod";
		author = "RoomService & Wardog";
		dir = "CodeLock";
		name = "CodeLock";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				files[] = {"CodeLock\scripts\3_game"};
			};
			class worldScriptModule
			{
				files[] = {"CodeLock\scripts\4_world"};
			};
			class missionScriptModule
			{
				files[] = {"CodeLock\scripts\5_mission"};
			};
		};
	};
};
