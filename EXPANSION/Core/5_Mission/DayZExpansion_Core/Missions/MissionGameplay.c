/**
 * MissionGameplay.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

/**@class		MissionGameplay
 * @brief		
 **/
modded class MissionGameplay
{
	// ------------------------------------------------------------
	// Constructor
	// ------------------------------------------------------------
	void MissionGameplay()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("MissionGameplay::MissionGameplay - Start");
		#endif

		CreateDayZExpansion();
		
		if ( IsMissionClient() )
			GetExpansionClientSettings().Load();

		if ( !IsMissionOffline() )
			g_exGlobalSettings.Unload();

		#ifdef EXPANSIONEXPRINT
		EXPrint("MissionGameplay::MissionGameplay - End");
		#endif
	}

	// ------------------------------------------------------------
	// Destructor
	// ------------------------------------------------------------
	void ~MissionGameplay()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("MissionGameplay::~MissionGameplay - Start");
		#endif

		DestroyDayZExpansion();

		g_exGlobalSettings.Unload();

		#ifdef EXPANSIONEXPRINT
		EXPrint("MissionGameplay::~MissionGameplay - End");
		#endif
	}
	
	// ------------------------------------------------------------
	// Override PlayerControlDisable
	// ------------------------------------------------------------
	override void PlayerControlDisable(int mode)
	{
		switch (mode)
		{
			case INPUT_EXCLUDE_ALL:
			{
				GetUApi().ActivateExclude("menuexpansion");
				break;
			}
			
			case INPUT_EXCLUDE_CHAT_EXPANSION:
			{
				GetUApi().ActivateExclude("chatexpansion");
				break;
			}
		}
		
		super.PlayerControlDisable(mode);
	}
	
	// ------------------------------------------------------------
	// OnMissionStart
	// ------------------------------------------------------------
	override void OnMissionStart()
	{
		super.OnMissionStart();
		
		#ifdef EXPANSIONEXPRINT
		EXPrint("MissionGameplay::OnMissionStart - Start");
		#endif

		if ( !GetGame().IsMultiplayer() )
		{
			// GetDayZExpansion().OnMissionStart();
		}

		#ifdef EXPANSIONEXPRINT
		EXPrint("MissionGameplay::OnMissionStart - End");
		#endif
	}

	// ------------------------------------------------------------
	// OnMissionLoaded
	// ------------------------------------------------------------
	override void OnMissionLoaded()
	{
		super.OnMissionLoaded();
		
		#ifdef EXPANSIONEXPRINT
		EXPrint("MissionGameplay::OnMissionLoaded - Start");
		#endif
		
		if ( !GetGame().IsMultiplayer() )
		{
			// GetDayZExpansion().OnMissionLoaded();
		}
		
		#ifdef EXPANSIONEXPRINT
		EXPrint("MissionGameplay::OnMissionLoaded - End");
		#endif
	}

	// ------------------------------------------------------------
	// OnUpdate
	// ------------------------------------------------------------
	override void OnUpdate( float timeslice )
	{	
		#ifdef EXPANSIONEXPRINT
		EXPrint("MissionGameplay::OnUpdate - Start");
		#endif

		super.OnUpdate( timeslice );

		if ( !m_bLoaded )
		{
			#ifdef EXPANSIONEXPRINT
			EXPrint("MissionGameplay::OnUpdate - End");
			#endif

			return;
		}
		
		// GetDayZExpansion().OnUpdate( timeslice );

		//! Checking for keyboard focus
		bool inputIsFocused = false;
		
		//! Reference to focused windget
		Widget focusedWidget = GetFocus();

		if ( focusedWidget )
		{
			if ( focusedWidget.ClassName().Contains( "EditBoxWidget" ) )
			{
				inputIsFocused = true;
			} 
			else if ( focusedWidget.ClassName().Contains( "MultilineEditBoxWidget" ) )
			{
				inputIsFocused = true;
			}
		}

		//! Refernce to man
		Man man = GetGame().GetPlayer();

		//! Reference to input
		Input input = GetGame().GetInput();

		//! Expansion reference to menu
		UIScriptedMenu topMenu = m_UIManager.GetMenu();

		//! Expansion reference to player
		PlayerBase playerPB = PlayerBase.Cast( man );
		
		if ( playerPB )
		{
			HumanCommandVehicle hcv = playerPB.GetCommand_Vehicle();
			if ( hcv && hcv.GetVehicleSeat() == DayZPlayerConstants.VEHICLESEAT_DRIVER )
			{
				CarScript carScript = CarScript.Cast( hcv.GetTransport() );
				if ( carScript )
				{
					carScript.UpdateExpansionController();
				}
			}

			ExpansionHumanCommandVehicle ehcv = playerPB.GetCommand_ExpansionVehicle();
			if ( ehcv && ehcv.GetVehicleSeat() == DayZPlayerConstants.VEHICLESEAT_DRIVER )
			{
				ExpansionVehicleBase expansionVehicleScript = ExpansionVehicleBase.Cast( ehcv.GetTransport() );
				if ( expansionVehicleScript )
				{
					expansionVehicleScript.UpdateExpansionController();
				}
			}
		}

		#ifdef EXPANSIONEXPRINT
		EXPrint("MissionGameplay::OnUpdate - End");
		#endif
	}
};