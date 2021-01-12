////////////////////////////////////////////////////////////////////
//DeRap: OP_BaseItems\Assets\OPClock\config.bin
//Produced from mikero's Dos Tools Dll version 7.89
//https://mikero.bytex.digital/Downloads
//'now' is Tue Jan 12 10:46:17 2021 : 'file' last modified on Thu Nov 19 09:23:14 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class OP_Clock
	{
		units[] = {"OP_watch"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Radio"};
	};
};
class CfgVehicles
{
	class Compass;
	class OP_watch: Compass
	{
		scope = 2;
		displayName = "Pocketwatch";
		descriptionShort = "What is the time?";
		model = "\OP_Baseitems\Assets\OPClock\OPwatch.p3d";
		animClass = "Compass";
		itemSize[] = {1,2};
		SingleUseActions[] = {501,538};
		ContinuousActions[] = {230};
		weight = 190;
		simulation = "ItemCompass";
		class AnimationSources
		{
			class cover
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 0;
			};
		};
	};
};
