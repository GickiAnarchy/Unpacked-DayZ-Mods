/**
 * ExpansionMarketTraderFrancis.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionMarketTraderFrancis: ExpansionMarketTrader
{
	// ------------------------------------------------------------
	// Expansion Defaults
	// ------------------------------------------------------------
	override void Defaults()
	{
		super.Defaults();
		
		TraderName = "ExpansionTraderFrancis";
		DisplayName = "#STR_EXPANSION_MARKET_TRADER_ATTACHMENTS";
		m_FileName = "Attachments_Trader_Francis";
		
		// MAGAZINES
		AddItem("Mag_FNX45_15Rnd");
		AddItem("Mag_CZ75_15Rnd");
		AddItem("Mag_Glock_15Rnd");
		AddItem("Mag_IJ70_8Rnd");
		AddItem("Mag_Deagle_9Rnd");
		AddItem("Mag_MP5_30Rnd");
		AddItem("Mag_CZ61_20Rnd");
		AddItem("Mag_MKII_10Rnd");
		AddItem("Mag_Ruger1022_10Rnd");
		AddItem("Mag_Ruger1022_15Rnd");
		//AddItem("Mag_CLIP762x54_5Rnd");
		//AddItem("Mag_CLIP762x39_10Rnd");
		AddItem("Mag_AKM_30Rnd");
		AddItem("Mag_CZ527_5rnd");
		AddItem("Mag_STANAG_30Rnd");
		AddItem("Mag_AK101_30Rnd");
		AddItem("Mag_AK74_30Rnd");
		AddItem("Mag_SVD_10Rnd");
		AddItem("Mag_FAL_20Rnd");
		AddItem("Mag_UMP_25Rnd");
		AddItem("Mag_VSS_10Rnd");
		AddItem("Mag_Saiga_5Rnd");
		AddItem("Mag_Saiga_8Rnd");
		AddItem("Mag_Saiga_Drum20Rnd");
		
		AddItem("Mag_Expansion_Taser");
		AddItem("Mag_Expansion_M9_15Rnd");
		AddItem("Mag_Expansion_Kedr_20Rnd");
		AddItem("Mag_Expansion_MPX_40Rnd");
		AddItem("Mag_Expansion_MP7_40Rnd");
		AddItem("Mag_Expansion_Vityaz_30Rnd");
		AddItem("Mag_Expansion_G36_30Rnd");
		AddItem("Mag_Expansion_AWM_5Rnd");
		AddItem("Mag_Expansion_M14_10Rnd");
		AddItem("Mag_Expansion_M14_20Rnd");
		
		// MUZZLES
		AddItem("AK_Bayonet");
		AddItem("M9A1_Bayonet");
		AddItem("Mosin_Bayonet");
		AddItem("SKS_Bayonet");
		AddItem("Expansion_Kar98_Bayonet");
	
		AddItem("Mosin_Compensator");
		AddItem("MP5_Compensator");
	
		AddItem("M4_Suppressor");
		AddItem("AK_Suppressor");
		AddItem("PistolSuppressor");
		
		// OPTICS
		AddItem("M4_CarryHandleOptic");
		AddItem("BUISOptic");
		AddItem("M68Optic");
		AddItem("M4_T3NRDSOptic");
		AddItem("FNP45_MRDSOptic");
		AddItem("ReflexOptic");
		AddItem("ACOGOptic");
		AddItem("PUScopeOptic");
		AddItem("KashtanOptic");
		AddItem("HuntingOptic");
		AddItem("PSO1Optic");
		AddItem("PSO11Optic");
		AddItem("KobraOptic");
		AddItem("PistolOptic");

		AddItem("ExpansionReflexMRSOptic");
		AddItem("ExpansionEXPS3HoloOptic");
		AddItem("ExpansionHAMROptic");
		AddItem("ExpansionDeltapointOptic");
		AddItem("ExpansionKar98ScopeOptic");
		AddItem("Expansion_M1A_RailAtt");
		AddItem("Expansion_ANPEQ15_Red");
		AddItem("Expansion_ANPEQ15_Green");

		// Buttstocks
		AddItem("M4_OEBttstck");
		AddItem("M4_MPBttstck");
		AddItem("M4_CQBBttstck");
		AddItem("AK_WoodBttstck");
		AddItem("AK74_WoodBttstck");
		AddItem("AK_FoldingBttstck");
		AddItem("AK_PlasticBttstck");
		AddItem("AKS74U_Bttstck");
		AddItem("MP5k_StockBttstck");
		AddItem("Fal_OeBttstck");
		AddItem("Fal_FoldingBttstck");
		
		// Handguards
		AddItem("M4_PlasticHndgrd");
		AddItem("M4_RISHndgrd");
		AddItem("M4_MPHndgrd");
		AddItem("AK_WoodHndgrd");
		AddItem("AK74_Hndgrd");
		AddItem("AK_RailHndgrd");
		AddItem("AK_PlasticHndgrd");
		AddItem("MP5_PlasticHndgrd");
		AddItem("MP5_RailHndgrd");
		
		// Ghillie Attachments
		AddItem("GhillieAtt_Tan");
		AddItem("GhillieAtt_Woodland");
		AddItem("GhillieAtt_Mossy");
	}
}