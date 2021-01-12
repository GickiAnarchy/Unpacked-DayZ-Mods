////////////////////////////////////////////////////////////////////
//DeRap: OP_BaseItems\Assets\TentBase\config.bin
//Produced from mikero's Dos Tools Dll version 7.89
//https://mikero.bytex.digital/Downloads
//'now' is Tue Jan 12 10:46:19 2021 : 'file' last modified on Thu Nov 19 09:23:19 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class OP_Tents
	{
		units[] = {"OP_ImpTent","OP_ImpTentPlacing"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Structures_Military","DZ_Gear_Camping"};
	};
};
class CfgVehicles
{
	class Container_Base;
	class OP_ImpTent: Container_Base
	{
		scope = 2;
		displayName = "Improvised Tent";
		descriptionShort = "Improvised";
		model = "\OP_BaseItems\Assets\TentBase\OP_ImpTent.p3d";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		slopeTolerance = 0.25;
		hiddenSelectionsTextures[] = {};
		hiddenSelectionsMaterials[] = {};
		openable = 0;
		carveNavmesh = 1;
		itemSize[] = {4,4};
		itemsCargoSize[] = {10,10};
		itemBehaviour = 2;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		attachments[] = {"CamoNet"};
		repairableWithKits[] = {5,2};
		repairCosts[] = {30,25};
		SingleUseActions[] = {527};
		InteractActions[] = {1044124};
		ContinuousActions[] = {231};
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
		class AnimationSources
		{
			class Body
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Inventory
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Pack
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class CamoNet
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class CamoNet
			{
				name = "$STR_attachment_camonet0";
				description = "";
				attachmentSlots[] = {"CamoNet"};
				icon = "cat_camonet";
				view_index = 1;
			};
		};
	};
	class OP_ImpTentPlacing: OP_ImpTent
	{
		model = "\OP_BaseItems\Assets\TentBase\OP_ImpTentPlacing.p3d";
		storageCategory = 10;
		hiddenSelections[] = {"placing"};
		hologramMaterial = "car_tent";
		hologramMaterialPath = "dz\gear\camping\data";
		class AnimationSources
		{
			class Placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
};
