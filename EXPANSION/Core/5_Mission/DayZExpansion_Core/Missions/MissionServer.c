/**
 * MissionServer.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

/**@class		MissionServer
 * @brief		
 **/

modded class MissionServer
{
	// ------------------------------------------------------------
	// MissionServer Constructor
	// ------------------------------------------------------------
	void MissionServer()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("MissionServer::MissionServer - Start");
		#endif

		CreateDayZExpansion();

		#ifdef EXPANSIONEXPRINT
		EXPrint("MissionServer::MissionServer - End");
		#endif
	}

	// ------------------------------------------------------------
	// MissionServer Destructor
	// ------------------------------------------------------------
	void ~MissionServer()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("MissionServer::~MissionServer - Start");
		#endif
		
		DestroyDayZExpansion();
		
		#ifdef EXPANSIONEXPRINT
		EXPrint("MissionServer::~MissionServer - End");
		#endif
	}

	// ------------------------------------------------------------
	// OnMissionStart
	// ------------------------------------------------------------
	override void OnMissionStart()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("MissionServer::OnMissionStart - Start");
		#endif
		
		super.OnMissionStart();
		
		GetDayZExpansion().OnStart();	

		#ifdef EXPANSIONEXPRINT
		EXPrint("MissionServer::OnMissionStart - End");
		#endif
	}
	
	// ------------------------------------------------------------
	// OnMissionLoaded
	// ------------------------------------------------------------
	override void OnMissionLoaded()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("MissionServer::OnMissionLoaded - Start");
		#endif
		
		super.OnMissionLoaded();
		
		GetDayZExpansion().OnLoaded();

		#ifdef EXPANSIONEXPRINT
		EXPrint("MissionServer::OnMissionLoaded - End");
		#endif
	}
	
	// ------------------------------------------------------------
	// OnMissionFinish
	// ------------------------------------------------------------
	override void OnMissionFinish()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("MissionServer::OnMissionFinish - Start");
		#endif
	   
		super.OnMissionFinish();

		//! Save settings on mission finish
		g_exGlobalSettings.Save();
		
		#ifdef EXPANSIONEXPRINT
		EXPrint("MissionServer::OnMissionFinish - End");
		#endif
	}
	
	// ------------------------------------------------------------
	// OnClientReconnectEvent
	// ------------------------------------------------------------
	override void OnClientReconnectEvent( PlayerIdentity identity, PlayerBase player )
	{
		super.OnClientReconnectEvent( identity, player );

		g_exGlobalSettings.Send( identity );
	}
	
	// ------------------------------------------------------------
	// InvokeOnConnect
	// ------------------------------------------------------------
	override void InvokeOnConnect( PlayerBase player, PlayerIdentity identity )
	{
		g_exGlobalSettings.Send( identity );
		
		PlayerBase.AddPlayer( player );
		
		//! Do after, because some modules use PlayerIdentity setup inside AddPlayer of PlayerBase class
		super.InvokeOnConnect( player, identity );
	}

	// ------------------------------------------------------------
	// PlayerDisconnected
	// ------------------------------------------------------------
	override void PlayerDisconnected( PlayerBase player, PlayerIdentity identity, string uid )
	{
		PlayerBase.RemovePlayer( uid );
		
		super.PlayerDisconnected( player, identity, uid );
	}
}
