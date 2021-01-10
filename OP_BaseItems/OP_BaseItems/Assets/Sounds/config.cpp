////////////////////////////////////////////////////////////////////
//DeRap: OP_BaseItems\Assets\Sounds\config.bin
//Produced from mikero's Dos Tools Dll version 7.89
//https://mikero.bytex.digital/Downloads
//'now' is Fri Jan 08 19:45:10 2021 : 'file' last modified on Thu Nov 19 09:23:19 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class OP_SOUNDS
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgSoundShaders
{
	class portablegaslamp_burn_SoundShader;
	class OP_portablegaslamp_burn_SoundShader: portablegaslamp_burn_SoundShader
	{
		samples[] = {{"DZ\sounds\Characters\actions\items\portablegaslamp\portablegaslamp_burn",1}};
		volume = 0.1;
	};
};
class CfgSoundSets
{
	class portablegaslamp_burn_SoundSet;
	class OP_portablegaslamp_burn_SoundSet: portablegaslamp_burn_SoundSet
	{
		soundShaders[] = {"OP_portablegaslamp_burn_SoundShader"};
		loop = 1;
	};
};
