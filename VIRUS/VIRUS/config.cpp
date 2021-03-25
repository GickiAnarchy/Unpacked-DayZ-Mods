////////////////////////////////////////////////////////////////////
//DeRap: VIRUS\config.bin
//Produced from mikero's Dos Tools Dll version 7.97
//https://mikero.bytex.digital/Downloads
//'now' is Sat Mar 13 19:26:38 2021 : 'file' last modified on Mon Dec 21 06:58:17 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class VIRUS
	{
		units[] = {"WTF69PathogenVial","AntiBodiesVial","WTF69VirusCure","Cure_Petridish","brain_Mung_virus","cure_microscope","WTF69VirusInjector"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Gear_Medical","DZ_Characters","DZ_Structures_Furniture","DZ_Data"};
	};
};
class CfgMods
{
	class VIRUS
	{
		dir = "VIRUS";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "VIRUS";
		credits = "munghard jadesnood saltybob";
		author = "SHoover80";
		authorID = "";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"World","Game"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"VIRUS/3_game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"VIRUS/4_world"};
			};
		};
	};
};
class CfgVehicles
{
	class DZ_LightAI;
	class DayZInfected: DZ_LightAI{};
	class ZombieBase: DayZInfected
	{
		class Skinning
		{
			class brain
			{
				item = "brain_Mung_virus";
				count = 1;
			};
		};
	};
	class Inventory_Base;
	class WTF69PathogenVial: Inventory_Base
	{
		scope = 2;
		displayName = "Pathogen Vial";
		descriptionShort = "Vial containing isolated infection pathogen";
		model = "\dz\gear\medical\InjectionVial.p3d";
		itemSize[] = {2,2};
		weight = 50;
		lootCategory = "Medical";
		varQuantityInit = 2;
		varQuantityMin = 0;
		varQuantityMax = 2;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"VIRUS\textures\WTF69virusvial_co.paa","VIRUS\textures\WTF69virusvial_co.paa","VIRUS\textures\WTF69virusvial_co.paa"};
	};
	class AntiBodiesVial: Inventory_Base
	{
		scope = 2;
		displayName = "Antibodies Vial";
		descriptionShort = "Vial containing antibodies";
		model = "\dz\gear\medical\InjectionVial.p3d";
		itemSize[] = {2,2};
		weight = 50;
		lootCategory = "Medical";
		varQuantityInit = 10;
		varQuantityMin = 0;
		varQuantityMax = 10;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"VIRUS\textures\Antibodiesvial_co.paa","VIRUS\textures\Antibodiesvial_co.paa","VIRUS\textures\Antibodiesvial_co.paa"};
	};
	class Cure_Petridish: Inventory_Base
	{
		scope = 2;
		displayName = "Petridish";
		descriptionShort = "Petridish for research";
		model = "\dz\structures\furniture\school_equipment\lab_petri_dish.p3d";
		weight = 0;
		interactionWeight = 1;
		itemSize[] = {2,1};
		inventorySlot = "Material_Petridish";
		hiddenSelections[] = {"component1"};
		hiddenSelectionsTextures[] = {"\DZ\structures\furniture\school_equipment\data\lab_set_ca.paa","\DZ\structures\furniture\school_equipment\data\lab_set_ca.paa","\DZ\structures\furniture\school_equipment\data\lab_set_ca.paa"};
		hiddenSelectionsMaterials[] = {"\DZ\data\data\penetration\glass.rvmat","\DZ\data\data\penetration\glass.rvmat","\DZ\data\data\penetration\glass.rvmat"};
	};
	class brain_Mung_virus: Inventory_Base
	{
		scope = 2;
		displayName = "Brain";
		descriptionShort = "Infected brain";
		model = "\VIRUS\brain\brain.p3d";
		inventorySlot = "Material_Brain";
		rotationFlags = 34;
		itemSize[] = {3,3};
		weight = 265;
		isMeleeWeapon = 1;
	};
	class BloodBagFull: Inventory_Base
	{
		inventorySlot = "Material_BloodBagFull";
	};
	class cure_microscope: Inventory_Base
	{
		scope = 2;
		displayName = "Microscope";
		descriptionShort = "Microscope for research";
		model = "\dz\structures\furniture\school_equipment\lab_microscope.p3d";
		itemSize[] = {3,5};
		attachments[] = {"Material_Petridish","Material_Brain","Material_BloodBagFull"};
		hiddenSelections[] = {"component1"};
		hiddenSelectionsTextures[] = {"\DZ\structures\furniture\school_equipment\data\lab_set_ca.paa","\DZ\structures\furniture\school_equipment\data\lab_set_ca.paa","\DZ\structures\furniture\school_equipment\data\lab_set_ca.paa"};
		hiddenSelectionsMaterials[] = {"\DZ\structures\furniture\school_equipment\data\lab_set.rvmat"};
		class GUIInventoryAttachmentsProps
		{
			class Materials
			{
				name = "Research Items";
				description = "";
				attachmentSlots[] = {"Material_Petridish","Material_Brain","Material_BloodBagFull"};
				icon = "missing";
			};
		};
	};
	class Injector_Base: Inventory_Base
	{
		model = "\dz\gear\medical\Epinephrine.p3d";
		rotationFlags = 17;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 1;
		itemSize[] = {1,2};
		weight = 60;
		lootCategory = "Medical";
		lootTag[] = {"Medic"};
		hiddenSelections[] = {"zbytek"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{"DZ\gear\medical\data\epipen.rvmat"}},{0.7,{"DZ\gear\medical\data\epipen.rvmat"}},{0.5,{"DZ\gear\medical\data\epipen_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\epipen_damage.rvmat"}},{0,{"DZ\gear\medical\data\epipen_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Morphine_spear
				{
					soundSet = "Morphine_spear_SoundSet";
					id = 201;
				};
				class Morphine_out
				{
					soundSet = "Morphine_out_SoundSet";
					id = 202;
				};
			};
		};
	};
	class WTF69VirusCure: Injector_Base
	{
		scope = 2;
		displayName = "WTF-69 cure";
		descriptionShort = "Cure for the WTF-69 virus";
		hiddenSelectionsTextures[] = {"VIRUS\textures\WTF69Cure_1_co.paa","VIRUS\textures\WTF69Cure_1_co.paa","VIRUS\textures\WTF69Cure_1_co.paa"};
	};
	class BloodSyringe;
	class WTF69VirusInjector: BloodSyringe
	{
		scope = 2;
		displayName = "WTF-69 Virus";
		descriptionShort = "Syringe containing The WTF-69 virus";
	};
};
class CfgSoundCurves
{
	class CfgSoundCurvesBloodVomit
	{
		points[] = {{0,1},{0.1,0.98},{0.2,0.92},{0.3,0.8},{0.4,0.65},{0.5,0.5},{0.6,0.35},{0.7,0.2},{0.8,0.08},{0.9,0.02},{1,0}};
	};
};
class CfgSound3DProcessors
{
	class default3DProcessingBloodVomit
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
	class base_SoundShaderBloodVomit
	{
		range = 10;
		rangeCurve = "CfgSoundCurvesBloodVomit";
		volume = 8;
	};
	class base_SoundShaderPlayerInfected
	{
		range = 10;
		rangeCurve = "CfgSoundCurvesBloodVomit";
		volume = 8;
	};
	class BloodVomit_SoundShader: base_SoundShaderBloodVomit
	{
		volume = 8;
		range = 10;
		rangeCurve = "CfgSoundCurvesBloodVomit";
		samples[] = {{"VIRUS\sounds\Puke2",1},{"VIRUS\sounds\vomiting-02",1},{"VIRUS\sounds\vomiting-04",1},{"VIRUS\sounds\vomiting-06",1},{"VIRUS\sounds\vomit_6",1},{"VIRUS\sounds\vomit_3",1}};
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
	class base_SoundSetSpeech
	{
		sound3DProcessingType = "default3DProcessingTypeSpeech";
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
	class BloodVomit_SoundSet: base_SoundSet
	{
		soundShaders[] = {"BloodVomit_SoundShader"};
		volume = 8;
	};
};
class CfgSlots
{
	class Slot_Material_Brain
	{
		name = "Material_Brain";
		displayName = "Zombie Brain";
		selection = "Material_Brain";
		ghostIcon = "missing";
		show = "false";
		stackMax = 2;
	};
	class Slot_Material_BloodBagFull
	{
		name = "Material_BloodBagFull";
		displayName = "Full BloodBag";
		selection = "Material_BloodBagFull";
		ghostIcon = "missing";
		show = "false";
		stackMax = 2;
	};
	class Slot_Material_Petridish
	{
		name = "Material_Petridish";
		displayName = "Petridish";
		selection = "Material_Petridish";
		ghostIcon = "missing";
		show = "false";
		stackMax = 2;
	};
};
