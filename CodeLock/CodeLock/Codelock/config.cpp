////////////////////////////////////////////////////////////////////
//DeRap: CodeLock\Codelock\config.bin
//Produced from mikero's Dos Tools Dll version 7.89
//https://mikero.bytex.digital/Downloads
//'now' is Wed Dec 16 03:33:47 2020 : 'file' last modified on Wed Nov 25 13:44:11 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class GDZ_Codelock
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Container_Base;
	class CombinationLock;
	class CodeLock: CombinationLock
	{
		displayName = "CodeLock";
		descriptionShort = "An electronic lock to secure fence gates and tents with a 3-6 character passcode. Runs off of magical energy and doesn't require an external power source.";
		model = "\CodeLock\Codelock\GDZ_codelock.p3d";
		repairableWithKits[] = {7};
		repairCosts[] = {50};
	};
	class MediumTent: Container_Base
	{
		attachments[] = {"CamoNet","Lights","Att_CombinationLock"};
		class GUIInventoryAttachmentsProps
		{
			class CodeLock
			{
				name = "CodeLock";
				description = "";
				attachmentSlots[] = {"Att_CombinationLock"};
				icon = "cat_bb_attachments";
				selection = "wall";
			};
		};
		class AnimationSources
		{
			class CodeLock
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
	class LargeTent: Container_Base
	{
		attachments[] = {"CamoNet","Lights","Att_CombinationLock"};
		class GUIInventoryAttachmentsProps
		{
			class CodeLock
			{
				name = "CodeLock";
				description = "";
				attachmentSlots[] = {"Att_CombinationLock"};
				icon = "cat_bb_attachments";
				selection = "wall";
			};
		};
		class AnimationSources
		{
			class CodeLock
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
	class CarTent: Container_Base
	{
		attachments[] = {"CamoNet","Lights","Att_CombinationLock"};
		class GUIInventoryAttachmentsProps
		{
			class CodeLock
			{
				name = "CodeLock";
				description = "";
				attachmentSlots[] = {"Att_CombinationLock"};
				icon = "cat_bb_attachments";
				selection = "wall";
			};
		};
		class AnimationSources
		{
			class CodeLock
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
};
