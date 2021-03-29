/**
 * KeybindingsMenu.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class KeybindingsMenu
{
	override Widget Init()
	{
		layoutRoot = super.Init();
		
		SetGameVersion();
		
		return layoutRoot;
	}
	
	// ------------------------------------------------------------
	// Expansion SetGameVersion
	// ------------------------------------------------------------
	protected void SetGameVersion()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionKeybindingsMenu::SetGameVersion - Start");
		#endif

		TextWidget version_widget = TextWidget.Cast( layoutRoot.FindAnyWidget("version") );
		string version;
		GetGame().GetVersion( version );
		string expansion_version;	
		
		if ( GetDayZGame() )
		{
			expansion_version = GetDayZGame().GetExpansionClientVersion();
			m_Version.SetText( "DayZ SA #main_menu_version" + " " + version + "   DayZ Expansion #main_menu_version" + " " + expansion_version );
		}
		else
		{
			m_Version.SetText( "DayZ SA #main_menu_version" + " " + version );
		}
		
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionKeybindingsMenu::SetGameVersion - End");
		#endif
	}
	
	override void Refresh()
	{
		SetGameVersion();
	}
}