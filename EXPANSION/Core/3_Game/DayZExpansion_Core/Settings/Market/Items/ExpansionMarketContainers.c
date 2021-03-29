/**
 * ExpansionMarketContainers.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionMarketContainers: ExpansionMarketCategory
{
	// ------------------------------------------------------------
	// Expansion Defaults
	//
	// Price calculation and legend:
	// SN - Silver Nugget 	- .1
	// SB - Silver Bar 		- 1
	// GN - Gold Nugget 	- 10
	// GB - Gold Bar 		- 2500
	//
	//	string 	ClassName 			- Item class name that gets defined
	//	float 	MinPriceThreshold 	- Min price for the price threshold calculation
	//	float	MaxPriceThreshold 	- Max price for the price threshold calculation
	//	int		MinStockThreshold 	- Min stock for the price threshold calculation
	//	int		MaxStockThreshold 	- Max stock for the price threshold calculation
	//	int		PurchaseType		- 0 = Normal Item Trader / 1 = Vehicle Trader
	//	array	SpawnAttachments	- Array of item class names that gets attached to this item on buy.
	// ------------------------------------------------------------
	override void Defaults()
	{
		super.Defaults();

		CategoryID = 16;
		DisplayName = "#STR_EXPANSION_MARKET_CATEGORY_CONTAINERS";
		m_FileName = "Containers";

		AddItem("SmallProtectorCase", 			7,			9,			1,		250,	0 );
		AddItem("AmmoBox", 						8,			10,			1,		250,	0 );
		AddItem("BarrelHoles_Blue", 			800,		850,		1,		250,	0 );
		AddItem("BarrelHoles_Green", 			800,		850,		1,		250,	0 );
		AddItem("BarrelHoles_Red", 				800,		850,		1,		250,	0 );
		AddItem("BarrelHoles_Yellow", 			800,		850,		1,		250,	0 );
		AddItem("Barrel_Blue", 					1500,		1650,		1,		250,	0 );
		AddItem("Barrel_Green", 				1500,		1650,		1,		250,	0 );
		AddItem("Barrel_Red", 					1500,		1650,		1,		250,	0 );
		AddItem("Barrel_Yellow", 				1500,		1650,		1,		250,	0 );
		AddItem("SeaChest", 					2000,		2200,		1,		250,	0 );
	}
};