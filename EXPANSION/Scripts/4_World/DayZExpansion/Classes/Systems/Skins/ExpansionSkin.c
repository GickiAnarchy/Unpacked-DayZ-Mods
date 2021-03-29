/**
 * ExpansionSkin.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionSkin : Managed
{
	ref array< ref ExpansionSkinHiddenSelection > HiddenSelections;
	ref array< ref ExpansionSkinDamageZone > DamageZones;

	string HornEXT;
	string HornINT;
	
	void ExpansionSkin()
	{
		HiddenSelections = new array< ref ExpansionSkinHiddenSelection >;
		DamageZones = new array< ref ExpansionSkinDamageZone >;
	}

	void ~ExpansionSkin()
	{
		delete HiddenSelections;
		delete DamageZones;
	}
};