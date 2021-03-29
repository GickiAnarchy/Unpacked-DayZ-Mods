/**
 * ExpansionIngameHud.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionIngameHud
{
	//! HUD UI META
	protected Widget										m_WgtRoot;
	protected ref ExpansionIngameHudEventHandler 			m_ExpansionEventHandler;
	
	//! CONDITIONS
	protected bool											m_ExpansionHudState;
	protected bool											m_ExpansionHudDebuggerState;
	protected bool 											m_ExpansionHudGPSState;
	protected bool											m_ExpansionHudGPSMapState;
	protected bool											m_ExpansionHudGPSMapStatsState;
	protected bool											m_ExpansionHudNVState;
	protected bool											m_ExpansionEarplugState;
	protected bool 											m_ExpansionGPSSetting;
	protected bool											m_ExpansionGPSPosSetting;
	protected bool											m_ExpansionNVSetting;
	protected bool											m_ClientClockShow;
	
	//! GPS
	protected Widget										m_GPSPanel;
	protected Widget										m_MapStatsPanel;
	protected Widget 										m_MapPosPanel;
	protected TextWidget 									m_PlayerPosVal;
	protected Widget 										m_PlayerPosPanel;
	protected TextWidget									m_PlayerALTVal;
	protected Widget 										m_PlayerALTPanel;
	protected TextWidget 									m_PlayerDirVal;
	protected Widget 										m_PlayerDirPanel;
	
	protected Widget										m_GPSMapPanel;
	protected Widget										m_MapFrame;
	protected MapWidget										m_MapWidget;
	protected ref ExpansionMapMarkerPlayerArrow 			m_PlayerArrowMarker;
	
	protected float											m_GPSMapScale = 0.1;
	
	//! NIGHTVISION
	protected Widget 										m_NVPanel;
	protected ImageWidget 									m_NVOverlayImage;
	protected ImageWidget 									m_NVBatteryIcon;
	protected TextWidget									m_NVBatteryVal;
	protected int											m_NVBatteryState;
	//! EARPLUG
	protected ImageWidget 									m_EarPlugIcon;

	//! DEBUGER
	protected MultilineTextWidget							m_ExpansionDebug;

	// ------------------------------------------------------------
	// ExpansionIngameHud Constructor
	// ------------------------------------------------------------
	void ExpansionIngameHud()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionIngameHud::ExpansionIngameHud Start");
		#endif
		
		m_ExpansionEarplugState = false;
			
		GetExpansionClientSettings().SI_UpdateSetting.Insert( RefreshExpansionHudVisibility );
		
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionIngameHud::ExpansionIngameHud End");
		#endif
	}

	// ------------------------------------------------------------
	// ~ExpansionIngameHud Destructor
	// ------------------------------------------------------------
	void ~ExpansionIngameHud()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionIngameHud::~ExpansionIngameHud Start");
		#endif
		
		GetExpansionClientSettings().SI_UpdateSetting.Remove( RefreshExpansionHudVisibility );

		delete m_WgtRoot;

		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionIngameHud::~ExpansionIngameHud End");
		#endif
	}
	
	// ------------------------------------------------------------
	// Expansion Init
	// ------------------------------------------------------------
	void Init( Widget hud_panel_widget )
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionIngameHud::Init Start");
		#endif
		m_WgtRoot = hud_panel_widget;
		m_WgtRoot.Show( true );
		
		//! GPS
		m_GPSPanel								= Widget.Cast( m_WgtRoot.FindAnyWidget("GPSPanel") );
		m_GPSPanel.Show( false );
		if ( m_GPSPanel )
		{
			m_MapStatsPanel							= Widget.Cast( m_GPSPanel.FindAnyWidget("MapStatsPanel") );
			m_MapPosPanel 							= Widget.Cast( m_GPSPanel.FindAnyWidget("cursor_position") );
			m_PlayerPosVal 							= TextWidget.Cast( m_GPSPanel.FindAnyWidget("player_position_value") );
			m_PlayerPosPanel 						= Widget.Cast( m_GPSPanel.FindAnyWidget("player_position") );
			m_PlayerALTVal 							= TextWidget.Cast( m_GPSPanel.FindAnyWidget("player_alt_value") );
			m_PlayerALTPanel 						= Widget.Cast( m_GPSPanel.FindAnyWidget("player_alt") );
			m_PlayerDirVal							= TextWidget.Cast( m_GPSPanel.FindAnyWidget("player_direction_value") );
			m_PlayerDirPanel 						= Widget.Cast( m_GPSPanel.FindAnyWidget("player_direction") );
			
			m_GPSMapPanel							= Widget.Cast( m_GPSPanel.FindAnyWidget("GPSMapPanel") );
			m_MapFrame								= Widget.Cast( m_GPSPanel.FindAnyWidget("GPSMapFrame") );
			m_MapWidget 							= MapWidget.Cast( m_GPSPanel.FindAnyWidget("Map") );
			
			if ( GetExpansionSettings().GetMap().ShowPlayerPosition == 1 || GetExpansionSettings().GetMap().ShowPlayerPosition == 2 )
			{
				m_PlayerArrowMarker = new ExpansionMapMarkerPlayerArrow( m_WgtRoot, m_MapWidget );
				m_PlayerArrowMarker.SetName("");
			}
		}
		
		//! NIGHTVISION OVERLAY
		m_NVPanel 								= Widget.Cast( m_WgtRoot.FindAnyWidget("NVPanel") );
		if (m_NVPanel)
		{
			m_NVOverlayImage 						= ImageWidget.Cast( m_NVPanel.FindAnyWidget("NVOverlay") );
			m_NVBatteryIcon							= ImageWidget.Cast( m_NVPanel.FindAnyWidget("NVBatteryIcon") );
			
			m_NVBatteryIcon.LoadImageFile( 0, "DayZExpansion/GUI/icons/hud/battery_empty_64x64.edds");
			m_NVBatteryIcon.LoadImageFile( 1, "DayZExpansion/GUI/icons/hud/battery_low_64x64.edds");
			m_NVBatteryIcon.LoadImageFile( 2, "DayZExpansion/GUI/icons/hud/battery_med_64x64.edds");
			m_NVBatteryIcon.LoadImageFile( 3, "DayZExpansion/GUI/icons/hud/battery_high_64x64.edds");
			
			m_NVBatteryVal							= TextWidget.Cast( m_NVPanel.FindAnyWidget("NVBatteryVal") );
		}
		
		//! EARPLUGS		
		m_EarPlugIcon 							= ImageWidget.Cast( m_WgtRoot.FindAnyWidget("EarPlug_Icon") );
		
		Class.CastTo( m_ExpansionDebug, m_WgtRoot.FindAnyWidget( "ExpansionDebugger" ) );
		
		//! SET UI EVENT HANDLER
		m_ExpansionEventHandler = new ExpansionIngameHudEventHandler( this );
		m_WgtRoot.SetHandler( m_ExpansionEventHandler );
		
		m_ExpansionHudState = g_Game.GetProfileOption( EDayZProfilesOptions.HUD );
		
		#ifdef EXPANSIONEXLOGPRINT
		EXLogPrint("ExpansionIngameHud::Init End");
		#endif
	}
	
	// ------------------------------------------------------------
	// Expansion GetCurrentMapPos
	// ------------------------------------------------------------	
	vector GetCurrentMapPos()
	{
		vector cameraPos;
		vector mapPos;

		cameraPos = GetGame().GetCurrentCameraPosition();
		mapPos = m_MapWidget.MapToScreen(cameraPos);

		return mapPos;
	}
	
	// ------------------------------------------------------------
	// Expansion GetCurrentMapDir
	// ------------------------------------------------------------	
	int GetCurrentMapDir()
	{
		vector cameraOri;
		float yaw;
		float normalizedAngle;
		int dir;

		cameraOri = GetGame().GetCurrentCameraDirection().VectorToAngles();
		yaw = cameraOri[0];
		normalizedAngle = Math.NormalizeAngle(yaw);
		dir = Math.Round(normalizedAngle);

		return dir;
	}
	
	// ------------------------------------------------------------
	// Expansion UpdateExpansionDebugText
	// ------------------------------------------------------------
	void UpdateExpansionDebugText()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionIngameHud::UpdateExpansionDebugText Start");
		#endif
		
		array< ExpansionDebuggerBlock > blocks = new array< ExpansionDebuggerBlock >;
		ExpansionDebugger.GetEnabledBlocks( blocks );

		array< string > text = new array< string >();
		for ( int i = 0; i < blocks.Count(); i++ )
		{
			for ( int j = 0; j < blocks[i]._readyBuffer.Count(); j++ )
			{
				text.Insert( blocks[i]._readyBuffer[j] );
			}
		}

		string txt = "";
		for ( i = 0; i < text.Count(); i++ )
		{
			txt = txt + " \n\r " + text[i];
		}

		for ( int k = i; k < 256; k++ )
		{
			txt = txt + " \n\r ";
		}

		if ( m_ExpansionDebug )
			m_ExpansionDebug.SetText( txt );

		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionIngameHud::UpdateExpansionDebugText End");
		#endif
	}
	
	// ------------------------------------------------------------
	// Expansion Show
	// ------------------------------------------------------------
	void Show( bool show )
	{
		m_WgtRoot.Show( show );
	}
	
	// ------------------------------------------------------------
	// Expansion Update
	// ------------------------------------------------------------
	void Update( float timeslice )
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionIngameHud::Update Start");
		#endif

		RefreshExpansionHudVisibility();
		
		UpdateExpansionDebugText();
		
		if (m_ExpansionEventHandler)
			m_ExpansionEventHandler.Update(timeslice);
		
		if ( GetExpansionSettings().GetMap().ShowPlayerPosition == 1 || GetExpansionSettings().GetMap().ShowPlayerPosition == 2 )
		{
			if ( m_PlayerArrowMarker )
				m_PlayerArrowMarker.Update( timeslice );
		}

		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionIngameHud::Update End");
		#endif
	}
	
	// ------------------------------------------------------------
	// Expansion RefreshExpansionHudVisibility
	// ------------------------------------------------------------
	void RefreshExpansionHudVisibility()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionIngameHud::RefreshExpansionHudVisibility Start");
		#endif
		
		m_ExpansionGPSSetting = GetExpansionSettings().GetMap().EnableHUDGPS;
		m_ExpansionGPSPosSetting = GetExpansionSettings().GetMap().ShowPlayerPosition;
		m_ExpansionNVSetting = GetExpansionSettings().GetGeneral().EnableHUDNightvisionOverlay; 
		
		
		if ( m_ExpansionDebug )
			m_ExpansionDebug.Show( m_ExpansionHudState && m_ExpansionHudDebuggerState );
		
		if ( m_GPSPanel )
		{
			m_GPSPanel.Show( m_ExpansionHudState && m_ExpansionHudGPSState && m_ExpansionGPSSetting );
			if ( m_GPSPanel.IsVisible() )
				UpdateGPS();
		}
		
		if ( m_GPSMapPanel )
			m_GPSMapPanel.Show( m_ExpansionHudState && m_ExpansionHudGPSState && m_ExpansionHudGPSMapState && m_ExpansionGPSSetting );
		
		if ( GetExpansionSettings().GetMap().ShowPlayerPosition == 1 || GetExpansionSettings().GetMap().ShowPlayerPosition == 2 )
		{
			if ( m_PlayerArrowMarker )
				m_PlayerArrowMarker.ShowRoot( m_ExpansionHudState && m_ExpansionHudGPSState && m_ExpansionHudGPSMapState && m_ExpansionGPSSetting );
		}
		
		if ( m_MapStatsPanel )
			m_MapStatsPanel.Show( m_ExpansionHudState && m_ExpansionHudGPSState && m_ExpansionHudGPSMapStatsState && m_ExpansionGPSSetting );
		
		if ( m_NVPanel )
		{
			m_NVPanel.Show( m_ExpansionHudNVState && m_ExpansionNVSetting );
			if ( m_NVPanel.IsVisible() )
				UpdateNV();
		}
		
		if ( m_EarPlugIcon )
			m_EarPlugIcon.Show( m_ExpansionHudState && m_ExpansionEarplugState );	

		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionIngameHud::RefreshExpansionHudVisibility End");
		#endif
	}
	
	// ------------------------------------------------------------
	// Expansion IsInitialized
	// ------------------------------------------------------------
	bool IsInitialized()
	{
		if ( m_WgtRoot == NULL || !m_WgtRoot )
		{
			return false;
		}
		
		return true;
	}
	
	// ------------------------------------------------------------
	// Expansion OnClick
	// ------------------------------------------------------------
	bool OnClick( Widget w, int x, int y, int button )
	{
		return false;
	}
	
	// ------------------------------------------------------------
	// Expansion OnMouseWheel
	// ------------------------------------------------------------
	bool OnMouseWheel(Widget w, int x, int y, int wheel)
	{
		return false;
	}
	
	// ------------------------------------------------------------
	// Expansion UpdateGPS
	// ------------------------------------------------------------
	void UpdateGPS()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionIngameHud::UpdateGPS Start");
		#endif
		if ( m_MapStatsPanel.IsVisible() )
		{
			UpdateGPSMapStats();
		}
		
		if ( m_GPSMapPanel.IsVisible() )
		{
			UpdateGPSMap();
		}
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionIngameHud::UpdateGPS End");
		#endif
	}
	
	// ------------------------------------------------------------
	// Expansion UpdateGPSMapStats
	// ------------------------------------------------------------
	void UpdateGPSMapStats()
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionIngameHud::UpdateGPSMapStats Start");
		#endif
		vector m_cameraPosition, m_cameraDirection;
		float yaw, normalizedAngle;
		int dir, alt;
		PlayerBase player;
		
		if ( Class.CastTo(player, GetGame().GetPlayer()) )
		{
			m_cameraPosition = GetGame().GetCurrentCameraPosition();
			m_cameraDirection = GetGame().GetCurrentCameraDirection().VectorToAngles();
			yaw = m_cameraDirection[0];
			normalizedAngle = Math.NormalizeAngle(yaw);
			dir = Math.Round(normalizedAngle);
			alt = Math.Round(m_cameraPosition[1]);
			
			m_PlayerPosVal.SetText( Math.Round(m_cameraPosition[0]).ToString() + " : " + Math.Round(m_cameraPosition[2]).ToString() );
			m_PlayerDirVal.SetText( dir.ToString() );
			m_PlayerALTVal.SetText( alt.ToString() );
		}

		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionIngameHud::UpdateGPSMapStats End");
		#endif
	}
	
	// ------------------------------------------------------------
	// Expansion UpdateGPSMap
	// ------------------------------------------------------------
	void UpdateGPSMap()
	{
		#ifdef EXPANSIONEXLOGPRINT
		EXLogPrint("ExpansionIngameHud::UpdateGPSMap Start");
		#endif

		float scale;
		vector map_pos, camera_pos;
		float camera_x, camera_y;
		int deviation_x, deviation_y;
		int multiplier;
		float shift_x, shift_y;
		string worldName;
		
		if ( GetGame().GetPlayer() && GetGame().GetCurrentCameraPosition() )
		{
			GetGame().GetWorldName(worldName);
			worldName.ToLower();
		
			camera_pos = GetGame().GetCurrentCameraPosition();
			camera_x = camera_pos[0];
			camera_y = camera_pos[2];
			scale = GetCurrentGPSMapScale();
			
			multiplier = Math.Round(scale * 10);
			
			if ( worldName.Contains("chernarus") )	// CHERNARUS
			{
				if( scale >= 0.1 )
				{	
					shift_x = 642.5;
					shift_y = 485.5;
				}			
			} 
			else if ( worldName.Contains("enoch") )	// LIVONIA
			{
				if( scale >= 0.1 )
				{	
					shift_x = 545.0;
					shift_y = 412.5;
				}		
			}
			
			camera_x = camera_x + (shift_x * multiplier);
			camera_y = camera_y - (shift_y * multiplier);
			map_pos = Vector(camera_x, 0, camera_y);
			
			m_MapWidget.SetScale( scale );
			m_MapWidget.SetMapPos(map_pos);
		}

		#ifdef EXPANSIONEXLOGPRINT
		EXLogPrint("ExpansionIngameHud::UpdateGPSMap End");
		#endif
	}
	
	// ------------------------------------------------------------
	// Expansion ShowHud
	// ------------------------------------------------------------
	void ShowHud( bool show )
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionIngameHud::ShowHud Start");
		#endif
		m_ExpansionHudState = show;
		RefreshExpansionHudVisibility();
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionIngameHud::ShowHud End");
		#endif
	}
	
	// ------------------------------------------------------------
	// Expansion Bool GetExpansionHudState
	// ------------------------------------------------------------
	bool GetExpansionHudState()
	{
		return m_ExpansionHudState;
	}
	
	// ------------------------------------------------------------
	// Expansion Bool ShowDebugger
	// ------------------------------------------------------------
	void ShowDebugger( bool show )
	{
		m_ExpansionHudDebuggerState = show;
		RefreshExpansionHudVisibility();
	}
	
	// ------------------------------------------------------------
	// Expansion GetDebuggerState
	// ------------------------------------------------------------
	bool GetDebuggerState()
	{
		return m_ExpansionHudDebuggerState;
	}
	
	// ------------------------------------------------------------
	// Expansion ShowGPS
	// ------------------------------------------------------------
	void ShowGPS( bool show )
	{
		m_ExpansionHudGPSState = show;
		
		RefreshExpansionHudVisibility();
	}
	
	// ------------------------------------------------------------
	// Expansion GetGPSState
	// ------------------------------------------------------------
	bool GetGPSState()
	{
		return m_ExpansionHudGPSState;
	}
	
	// ------------------------------------------------------------
	// Expansion GetGPSMapState
	// ------------------------------------------------------------
	bool GetGPSMapState()
	{
		return m_ExpansionHudGPSMapState;
	}
	
	// ------------------------------------------------------------
	// Expansion ShowGPSMap
	// ------------------------------------------------------------
	void ShowGPSMap(bool show)
	{
		m_ExpansionHudGPSMapState = show;
		RefreshExpansionHudVisibility();
	}
	
	// ------------------------------------------------------------
	// Expansion GetGPSMapStatsState
	// ------------------------------------------------------------
	bool GetGPSMapStatsState()
	{
		return m_ExpansionHudGPSMapStatsState;
	}
	
	// ------------------------------------------------------------
	// Expansion ShowGPSMapStats
	// ------------------------------------------------------------
	void ShowGPSMapStats(bool show)
	{
		m_ExpansionHudGPSMapStatsState = show;
		RefreshExpansionHudVisibility();
	}
	
	// ------------------------------------------------------------
	// Expansion ShowNV
	// ------------------------------------------------------------
	void ShowNV( bool show )
	{
		m_ExpansionHudNVState = show;
		RefreshExpansionHudVisibility();
	}
	
	// ------------------------------------------------------------
	// Expansion GetNVState
	// ------------------------------------------------------------
	bool GetNVState()
	{
		return m_ExpansionHudNVState;
	}
	
	protected int BATTERY_EMPTY_COLOR = ARGB(255,231,76,60);
	protected int BATTERY_LOW_COLOR = ARGB(255,230,126,34);
	protected int BATTERY_MED_COLOR = ARGB(255,243,156,18);
	protected int BATTERY_FULL_COLOR = ARGB(255,46,204,113);
	// ------------------------------------------------------------
	// Expansion GetNVState
	// ------------------------------------------------------------
	void RefreshNVBatteryState(int percent)
	{
		if( percent < 25 )
		{
			//! 0 - 25% Energy 
			m_NVBatteryIcon.SetImage( 0 );
			m_NVBatteryIcon.SetColor( BATTERY_EMPTY_COLOR );
		}
		else if( percent >= 25 && percent < 30 )
		{
			//! 25 - 30% Energy 
			m_NVBatteryIcon.SetImage( 1 );
			m_NVBatteryIcon.SetColor( BATTERY_LOW_COLOR );		
		}
		else if( percent >= 30 && percent < 75 )
		{
			//! 30 - 75% Energy 
			m_NVBatteryIcon.SetImage( 2 );	
			m_NVBatteryIcon.SetColor( BATTERY_MED_COLOR );
		}
		else if( percent >= 75 )
		{
			//! 75 - 100% Energy 
			m_NVBatteryIcon.SetImage( 3 );	
			m_NVBatteryIcon.SetColor( BATTERY_FULL_COLOR );
		}
		
		m_NVBatteryVal.SetText( percent.ToString() + "%" );
	}
	
	// ------------------------------------------------------------
	// Expansion SetNVBatteryState
	// ------------------------------------------------------------
	void SetNVBatteryState(int percent)
	{
		m_NVBatteryState = percent;
	}
	
	// ------------------------------------------------------------
	// Expansion UpdateNV
	// ------------------------------------------------------------
	void UpdateNV()
	{
		RefreshNVBatteryState( m_NVBatteryState );
	}
	
	// ------------------------------------------------------------
	// Expansion GetEarplugsState
	// ------------------------------------------------------------
	bool GetEarplugsState()
	{
		return m_ExpansionEarplugState;
	}
	
	// ------------------------------------------------------------
	// Expansion OnResizeScreen
	// ------------------------------------------------------------
	void OnResizeScreen()
	{
		float x, y;
		m_WgtRoot.GetScreenSize( x, y );
		m_WgtRoot.Update();
	}

	// ------------------------------------------------------------
	// Expansion ToggleEarplugs
	// ------------------------------------------------------------
	void ToggleEarplugs()
	{
		m_ExpansionEarplugState = !m_ExpansionEarplugState;
		
		if ( m_ExpansionEarplugState )
		{
			if ( GetExpansionClientSettings() )
			{
				GetGame().GetSoundScene().SetSoundVolume( GetExpansionClientSettings().EarplugLevel, 1 );
			}
			else
			{
				GetGame().GetSoundScene().SetSoundVolume( 0.5, 1 );
			}
		}
		else
		{
			GetGame().GetSoundScene().SetSoundVolume( g_Game.m_volume_sound, 1 );
		}

		RefreshExpansionHudVisibility();
	}

	// ------------------------------------------------------------
	// Expansion ToggleEarplugs
	// ------------------------------------------------------------
	void UpdateEarplugs()
	{
		if ( GetExpansionClientSettings() )
		{
			GetGame().GetSoundScene().SetSoundVolume( GetExpansionClientSettings().EarplugLevel, 1 );
			
			RefreshExpansionHudVisibility();
		}
	}
	
	// ------------------------------------------------------------
	// Expansion GetCurrentGPSMapScale
	// ------------------------------------------------------------
	float GetCurrentGPSMapScale()
	{
		return m_GPSMapScale;
	}
	
	// ------------------------------------------------------------
	// Expansion SetGPSMapScale
	// ------------------------------------------------------------
	void SetGPSMapScale(float scale)
	{	
		m_GPSMapScale = scale;
		UpdateGPSMap();
		
		#ifdef EXPANSIONEXLOGPRINT
		EXLogPrint("ExpansionIngameHud::SetGPSMapScale:: m_GPSMapScale set to: " + m_GPSMapScale.ToString());
		#endif
	}
}
