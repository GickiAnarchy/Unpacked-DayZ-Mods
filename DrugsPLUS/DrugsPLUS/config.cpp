class CfgPatches
{
	class DP_scripts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"JM_CF_Scripts"
		};
	};
};
class CfgMods
{
	class DrugsPLUS
	{
		dir="DrugsPLUS";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="DrugsPLUS";
		credits="IceBlade";
		author="IceBlade";
		authorID="0";
		version="1.0";
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
					"DrugsPLUS/scripts/3_game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"DrugsPLUS/scripts/4_world"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"DrugsPLUS/scripts/5_mission"
				};
			};
		};
	};
};
