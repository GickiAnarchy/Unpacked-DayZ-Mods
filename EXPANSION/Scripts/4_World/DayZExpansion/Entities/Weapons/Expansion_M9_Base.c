/**
 * Expansion_M9_Base.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class Expansion_M9_Base : Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("Expansion_M9_Base::SpawnRecoilObject");
		#endif

		return new Cz75Recoil(this);
	}
};