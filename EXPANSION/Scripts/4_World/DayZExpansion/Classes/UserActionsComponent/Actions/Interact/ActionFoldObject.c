/**
 * ActionFoldObject.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class ActionFoldObject
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( player.IsInSafeZone() )
			return false;
			
		Object targetObject = target.GetObject();
		if ( targetObject.IsInherited(HescoBox) )
		{
			HescoBox hesco = HescoBox.Cast( targetObject );
			
			if ( hesco && hesco.GetState() == HescoBox.UNFOLDED )
			{
				// Is he in a territory ?
				if ( player.IsInTerritory() )
					return player.IsInsideOwnTerritory(); // show the prompt if it's his territory
			}
		}

		return false;
	}
}
