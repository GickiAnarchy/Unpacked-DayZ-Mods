/**
 * ExpansionRamp.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionRampBase extends ExpansionBaseBuilding
{
	override string GetConstructionKitType()
	{
		return "ExpansionRampKit";
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		UpdateVisuals();
	}
	
	override void AfterStoreLoad()
	{	
		super.AfterStoreLoad();
		
		UpdateVisuals();	
	}

	override void OnPartBuiltServer( notnull Man player, string part_name, int action_id )
	{
		super.OnPartBuiltServer(player, part_name, action_id );

		UpdateVisuals();
	}

	override void OnPartDismantledServer( notnull Man player, string part_name, int action_id )
	{
		super.OnPartDismantledServer( player, part_name, action_id );

		UpdateVisuals();
	}

	override void OnPartDestroyedServer( Man player, string part_name, int action_id, bool destroyed_by_connected_part = false )
	{
		super.OnPartDestroyedServer( player, part_name, action_id, destroyed_by_connected_part );

		UpdateVisuals();
	}

	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}

	override bool IsFacingPlayer( PlayerBase player, string selection )
	{
		return false;
	}

	override bool IsFacingCamera( string selection )
	{
		return false;
	}
	
	override void EEKilled( Object killer )
	{
		if ( !killer.IsInherited( CarScript ) )
		{
			super.EEKilled( killer );
		
			this.Delete();
		}
	}
}