class GardenboxEmpty extends ItemBase 
{	
	ref protected EffectSound 						m_DeployLoopSound;
	
	void GardenboxEmpty()
	{
		m_DeployLoopSound = new EffectSound;
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
		RegisterNetSyncVariableBool("m_IsDeploySound");
	}
	override bool IsHeavyBehaviour()
	{
		return true;
	}
	override void EEInit()
	{
		super.EEInit();
	}
	
	override bool IsDeployable()
	{
		return true;
	}	

	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
		AddAction(ActionDeployGardenpot);
	}
}

class GardenpotEmpty extends ItemBase
{	
	ref protected EffectSound 						m_DeployLoopSound;
	
	void GardenpotEmpty()
	{
		m_DeployLoopSound = new EffectSound;
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
		RegisterNetSyncVariableBool("m_IsDeploySound");
	}
	
	override void EEInit()
	{
		super.EEInit();
	}
	override bool IsHeavyBehaviour()
	{
		return true;
	}
	override bool IsDeployable()
	{
		return true;
	}	

	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployGardenpot);
		AddAction(ActionPlaceObject);
	}
}

class Gardenpot extends GardenPlot 
{
	void Gardenpot()
	{
		SetBaseFertility(1.25);
	}

	override void EEInit()
	{	
		super.EEInit();
	}	

	override int GetGardenSlotsCount()
	{
		return 3;
	}

	void RefreshSlots()
	{
		HideSelection("SeedBase_1");
		HideSelection("SeedBase_2");
		HideSelection("SeedBase_3");
	}

	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
				
		PlayerBase player_base = PlayerBase.Cast( player );
		vector position1 = player_base.GetLocalProjectionPosition();
		vector orientation1 = player_base.GetLocalProjectionOrientation();
		SetLifetime(3888000);	
		if ( GetGame().IsMultiplayer()  &&  GetGame().IsServer() || !GetGame().IsMultiplayer() )
		{
			// To properly move the clutter cutter from spawn position, it must be deleted and created again.
			if (m_ClutterCutter)
			{
				GetGame().ObjectDelete(m_ClutterCutter);
				m_ClutterCutter = NULL;
			}
			
			if (!m_ClutterCutter)
			{		
				m_ClutterCutter = GetGame().CreateObject( "ClutterCutter6x6", GetPosition(), false );
				m_ClutterCutter.SetOrientation( orientation );
			}
		}
	}

	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionEmptyGardenpot);
	}
}


class Gardenbox extends GardenPlot
{
	void Gardenbox()
	{
		SetBaseFertility(1.25);
	}

	override void EEInit()
	{	
		super.EEInit();
	}	

	override int GetGardenSlotsCount()
	{
		return 3;
	}

	void RefreshSlots()
	{
		HideSelection("SeedBase_1");
		HideSelection("SeedBase_2");
		HideSelection("SeedBase_3");
	}

	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
				
		PlayerBase player_base = PlayerBase.Cast( player );
		vector position1 = player_base.GetLocalProjectionPosition();
		vector orientation1 = player_base.GetLocalProjectionOrientation();
		SetLifetime(3888000);	
		if ( GetGame().IsMultiplayer()  &&  GetGame().IsServer() || !GetGame().IsMultiplayer() )
		{
			// To properly move the clutter cutter from spawn position, it must be deleted and created again.
			if (m_ClutterCutter)
			{
				GetGame().ObjectDelete(m_ClutterCutter);
				m_ClutterCutter = NULL;
			}
			
			if (!m_ClutterCutter)
			{		
				m_ClutterCutter = GetGame().CreateObject( "ClutterCutter6x6", GetPosition(), false );
				m_ClutterCutter.SetOrientation( orientation );
			}
		}
	}
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionEmptyGardenpot);
	}
}
