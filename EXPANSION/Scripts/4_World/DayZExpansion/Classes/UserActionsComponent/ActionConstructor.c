/**
 * ActionConstructor.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

/**@class		ActionConstructor
 * @brief		
 **/
modded class ActionConstructor
{
	// ------------------------------------------------------------
	// RegisterActions
	// ------------------------------------------------------------
	override void RegisterActions( TTypenameArray actions )
	{
		super.RegisterActions( actions );	

		//! Basebuilding
		actions.Insert( ExpansionActionSelectNextPlacement );
		actions.Insert( ExpansionActionDamageBaseBuilding );

		actions.Insert( ExpansionActionConnectElectricityToSource );
		actions.Insert( ExpansionActionDisconnectElectricityToSource );
		
		actions.Insert( ExpansionActionTogglePowerSwitch );
		
		//! Generator
		actions.Insert( ExpansionActionTurnOnGeneratorOnGround );
		actions.Insert( ExpansionActionTurnOffGeneratorOnGround );

		//! Paracute
		actions.Insert( ExpansionActionOpenParachute );
		actions.Insert( ExpansionActionCutParachute );

		//! Traders
		actions.Insert( ExpansionActionOpenTraderMenu );
		actions.Insert( ExpansionActionClose );
		actions.Insert( ExpansionActionOpen );

		//! Locks
		actions.Insert( ExpansionActionEnterCodeLock );
		actions.Insert( ExpansionActionChangeCodeLock );
		actions.Insert( ExpansionActionEnterSafeLock );
		actions.Insert( ExpansionActionChangeSafeLock );

		//! Safes
		actions.Insert( ExpansionActionCloseSafeLock );
		actions.Insert( ExpansionActionCloseSafeUnlock ); 

		actions.Insert( ExpansionActionPaint );
		actions.Insert( ExpansionActionCycleOpticsModeInHands );
		actions.Insert( ExpansionActionCycleOpticsMode );
		actions.Insert( ExpansionActionWritePaper );
		actions.Insert( ExpansionActionEnterFlagMenu );
		actions.Insert( ExpansionActionDismantleFlag );

		//! Music
		actions.Insert( ExpansionActionStartPlayingGuitar );
		actions.Insert( ExpansionActionStopPlayingGuitar );

		actions.Insert( ExpansionActionDestroyTerritory );
		
		//! Removed because it wont be in first release
		//actions.Insert( ExpansionActionTakeChicken );
		//actions.Insert( ExpansionActionGetQuest );
		//actions.Insert( ExpansionActionTakeInQuest );
	}
}