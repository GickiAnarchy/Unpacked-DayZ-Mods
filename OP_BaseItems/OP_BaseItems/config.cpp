////////////////////////////////////////////////////////////////////
//DeRap: OP_BaseItems\config.bin
//Produced from mikero's Dos Tools Dll version 7.89
//https://mikero.bytex.digital/Downloads
//'now' is Fri Jan 08 19:45:10 2021 : 'file' last modified on Thu Nov 19 09:23:20 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class OP_BaseItems
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Scripts"};
	};
};
class CfgMods
{
	class OP_BaseItems
	{
		dir = "OP_BaseItems";
		name = "OP_BaseItems";
		credits = "OP";
		author = "OP";
		authorID = "0";
		version = "1.25";
		extra = 0;
		type = "mod";
		dependencies[] = {"World","Game"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"OP_BaseItems/scripts/4_World"};
			};
			class gameScriptModule
			{
				value = "";
				files[] = {"OP_BaseItems/scripts/3_Game"};
			};
		};
	};
};
