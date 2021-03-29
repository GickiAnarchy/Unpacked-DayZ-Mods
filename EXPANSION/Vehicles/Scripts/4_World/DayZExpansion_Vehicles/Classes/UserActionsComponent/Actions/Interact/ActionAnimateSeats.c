/**
 * ActionAnimateSeats.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class ActionAnimateSeats
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( target.GetObject().IsInherited( ExpansionHelicopterScript ) || target.GetObject().IsInherited( ExpansionVehiclePlaneBase ) ) 
			return false;

		return super.ActionCondition(player, target, item);
	}
}