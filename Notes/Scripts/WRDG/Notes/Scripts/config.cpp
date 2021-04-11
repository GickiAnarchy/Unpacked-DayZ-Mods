////////////////////////////////////////////////////////////////////
//DeRap: Scripts\config.bin
//Produced from mikero's Dos Tools Dll version 7.97
//https://mikero.bytex.digital/Downloads
//'now' is Sun Apr 11 04:54:36 2021 : 'file' last modified on Wed Nov 04 01:12:49 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class Notes_Scripts
	{
		requiredAddons[] = {};
		units[] = {};
		weapons[] = {};
	};
};
class CfgMods
{
	class Notes
	{
		type = "mod";
		author = "Wardog";
		dir = "Notes";
		name = "Notes";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				files[] = {"WRDG/Notes/Scripts/3_Game"};
			};
			class worldScriptModule
			{
				files[] = {"WRDG/Notes/Scripts/4_World"};
			};
			class missionScriptModule
			{
				files[] = {"WRDG/Notes/Scripts/5_Mission"};
			};
		};
	};
};
