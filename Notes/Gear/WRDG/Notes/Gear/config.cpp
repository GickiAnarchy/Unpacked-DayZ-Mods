////////////////////////////////////////////////////////////////////
//DeRap: Gear\config.bin
//Produced from mikero's Dos Tools Dll version 7.97
//https://mikero.bytex.digital/Downloads
//'now' is Sun Apr 11 04:54:44 2021 : 'file' last modified on Wed Nov 04 01:12:48 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class Notes_Gear
	{
		requiredAddons[] = {"DZ_Gear_Tools","DZ_Gear_Consumables"};
		units[] = {"WrittenNote","Pen_Black","Pen_Red","Pen_Green","Pen_Blue"};
		weapons[] = {};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Journal_Base: Inventory_Base
	{
		scope = 0;
		model = "DZ\gear\books\Book_kniga.p3d";
		rotationFlags = 1;
		itemSize[] = {2,2};
	};
	class Journal: Journal_Base
	{
		scope = 0;
		displayName = "$STR_JOURNAL_NAME";
		descriptionShort = "$STR_JOURNAL_DESC";
		hiddenSelectionsTextures[] = {"WRDG\Notes\Gear\Data\journal_book_co.paa"};
	};
	class Paper;
	class WrittenNote: Inventory_Base
	{
		scope = 2;
		model = "\dz\gear\consumables\Paper.p3d";
		displayName = "$STR_WRITTEN_NOTE_NAME";
		descriptionShort = "$STR_WRITTEN_NOTE_DESC";
		inventorySlot[] = {};
	};
	class Pen_ColorBase;
	class Pen_Black: Pen_ColorBase
	{
		scope = 2;
		displayName = "$STR_PEN_BLACK";
		rgbColor[] = {0,0,0};
	};
	class Pen_Red: Pen_ColorBase
	{
		scope = 2;
		displayName = "$STR_PEN_RED";
		rgbColor[] = {180,4,4};
	};
	class Pen_Green: Pen_ColorBase
	{
		scope = 2;
		displayName = "$STR_PEN_GREEN";
		rgbColor[] = {8,138,8};
	};
	class Pen_Blue: Pen_ColorBase
	{
		scope = 2;
		displayName = "$STR_PEN_BLUE";
		rgbColor[] = {4,49,180};
	};
};
