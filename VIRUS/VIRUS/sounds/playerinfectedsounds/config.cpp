////////////////////////////////////////////////////////////////////
//DeRap: VIRUS\sounds\playerinfectedsounds\config.bin
//Produced from mikero's Dos Tools Dll version 7.97
//https://mikero.bytex.digital/Downloads
//'now' is Sat Mar 13 19:26:38 2021 : 'file' last modified on Mon Dec 21 06:58:17 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class DayzLater28playersounds
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Gear_Medical","DZ_Characters"};
	};
};
class CfgVehicles
{
	class AllVehicles;
	class Man: AllVehicles
	{
		class ViewPilot;
		class HeadLimits;
	};
	class SurvivorBase: Man
	{
		class SoundVoice
		{
			class AnimEvents
			{
				class Sounds
				{
					class playerInfectedsounds
					{
						soundset = "ZmbM_Skinny_HeavyHit_Soundset";
						id = 666999;
					};
				};
			};
		};
	};
};
class CfgSoundCurves
{
	class CfgSoundCurvesPlayerInfectedsounds
	{
		points[] = {{0,1},{0.1,0.98},{0.2,0.92},{0.3,0.8},{0.4,0.65},{0.5,0.5},{0.6,0.35},{0.7,0.2},{0.8,0.08},{0.9,0.02},{1,0}};
	};
};
class CfgSound3DProcessors
{
	class default3DProcessingPlayerInfectedsounds
	{
		type = "emitter";
		innerRange = 15;
		range = 10;
		radius = 5;
		volume = 8;
	};
	class default3DProcessingTypeSpeech
	{
		type = "emitter";
		innerRange = 15;
		range = 10;
		radius = 5;
		volume = 0.30118722;
	};
};
class CfgSoundShaders
{
	class base_SoundShaderPlayerInfectedsounds
	{
		range = 10;
		rangeCurve = "CfgSoundCurvesPlayerInfectedsounds";
		volume = 8;
	};
	class PlayerInfectedsounds_SoundShader: base_SoundShaderPlayerInfectedsounds
	{
		volume = 8;
		range = 10;
		rangeCurve = "CfgSoundCurvesPlayerInfectedsounds";
		samples[] = {{"VIRUS\sounds\playerinfectedsounds\zmbf_normal_attack_3",1},{"VIRUS\sounds\playerinfectedsounds\zmbf_normal_attack_4",1},{"VIRUS\sounds\playerinfectedsounds\zmbf_normal_attack_5",1},{"VIRUS\sounds\playerinfectedsounds\zmbf_normal_attack_6",1}};
	};
};
class CfgSoundSets
{
	class base_SoundSet
	{
		sound3DProcessingType = "default3DProcessingBloodVomit";
		spatial = 1;
		doppler = 0;
		loop = 1;
	};
	class PlayerInfected_SoundSet: base_SoundSet
	{
		soundShaders[] = {"PlayerInfectedsounds_SoundShader"};
		volume = 8;
	};
};
