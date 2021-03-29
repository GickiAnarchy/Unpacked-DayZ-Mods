/**
 * ExpansionElectricityBase.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionElectricityBase
{
	void ExpansionElectricityBase( ItemBase item )
	{
	}

	void OnStoreSave_OLD( ParamsWriteContext ctx )
	{
	}

	bool OnStoreLoad_OLD( ParamsReadContext ctx, int vanillaVersion, int expansionVersion )
	{
	}

	#ifdef CF_MODULE_MODSTORAGE
	void OnStoreSave( CF_ModStorage storage )
	{
	}

	bool OnStoreLoad( CF_ModStorage storage )
	{
	}
	#endif
};