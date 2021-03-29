/**
 * ExpansionMarketTraderJose.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionMarketTraderJose: ExpansionMarketTrader
{
	// ------------------------------------------------------------
	// Expansion Defaults
	// ------------------------------------------------------------
	override void Defaults()
	{
		super.Defaults();
		
		TraderName = "ExpansionTraderJose";
		DisplayName = "#STR_EXPANSION_MARKET_TRADER_BOATS";
		m_FileName = "Boats_Trader_Jose";
		
		//! AddItem( "ExpansionAmphibiaBoat" );
		AddItem( "ExpansionUtilityBoat" );
		AddItem( "ExpansionZodiacBoat" );
	}
}