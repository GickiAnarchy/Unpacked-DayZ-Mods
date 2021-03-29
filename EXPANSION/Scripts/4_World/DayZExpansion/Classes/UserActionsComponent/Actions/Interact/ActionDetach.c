/**
 * ExpansionActionDetach.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class ActionDetach
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		EntityAI tgt_parent = EntityAI.Cast( target.GetParent() );
		CarScript m_Car;
		
		if ( Class.CastTo( m_Car, target.GetParent() ) )
		{
			if ( m_Car.IsLocked() )
			{
				return false;
			}
		}
		
		return super.ActionCondition( player, target, item );
	}
}