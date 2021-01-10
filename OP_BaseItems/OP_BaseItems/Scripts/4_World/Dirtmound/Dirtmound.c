class Dirtmound extends GardenBase
{
	Object 	m_ClutterCutter;
	const string COMPATIBLE_SURFACES[] = {"cp_dirt", "cp_broadleaf_dense1", "cp_broadleaf_dense2", "cp_broadleaf_sparse1", "cp_broadleaf_sparse2", "cp_conifer_common1", "cp_conifer_common2", "cp_conifer_moss1", "cp_conifer_moss2", "cp_grass", "cp_grass_tall", "cp_gravel", "cp_rock", "textile_carpet_int"};
	static const int COMPATIBLE_SURFACES_COUNT = 14; // Count if elements of COMPATIBLE_SURFACES array

	
	override bool CanBePlaced( Man player, vector position )
	{
		string surface_type;
		GetGame().SurfaceGetType( position[0], position[2], surface_type );
		
		for (int i=0; i < COMPATIBLE_SURFACES_COUNT; i++)
		{
			if (COMPATIBLE_SURFACES[i] == surface_type)
			{
				return true;
			}
		}
		
		return false;
	}

    override void SetActions()
    {
        super.SetActions();        
        AddAction(ActionRemoveDirtmound);
  //      AddAction(ActionTogglePlaceObject);
      //  AddAction(ActionFoldOPShedkit);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
class ActionDigDirtmoundCB : ActiondeployObjectCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DIG_GARDEN);
	}
	
	override void DropDuringPlacing()
	{
		if ( m_ActionData.m_MainItem.CanMakeDirtmound() )
		{
			return;
		} 
	}
};
class ActionRemoveDirtmound: ActionInteractBase
{
	void ActionRemoveDirtmound()
	{
		//m_MessageSuccess = "";
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Dirtmound target_entity = Dirtmound.Cast( target.GetObject() );	

		if ( target_entity )	
		{
			return true;
		}
		
		return false;
	}

	override string GetText()
	{
		return "Remove Mound";
	}
	
	override void OnStartServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		if ( targetObject && targetObject.IsKindOf( "Dirtmound" ) )
		{
			GetGame().ObjectDelete( action_data.m_Target.GetObject() );
		}
	}
}
class ActionDigDirtmound: ActionDeployObject
{	
	Dirtmound dirtmound;
	
	void ActionDigDirtmound()
	{
		m_CallbackClass	= ActionDigDirtmoundCB;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
	}
/*
	override int GetType()
	{
		return 34324354;
	}*/
		
	override string GetText()
	{
		return "Dig Dirtmound";
	}
	
	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{
		//Client
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			if ( player.IsPlacingLocal() )
			{
				Hologram hologram = player.GetHologramLocal();
				Dirtmound item_DM;
				Class.CastTo(item_DM,  hologram.GetProjectionEntity() );	
				CheckSurfaceBelowDirtmound(player, item_DM, hologram);
	
				if ( !hologram.IsColliding() )
				{
					return true;
				}
			}
			return false;
		}
		//Server
		return true;
	}

	override void SetupAnimation( ItemBase item )
	{
		if ( item )
		{
			m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIG;
		}
	}
	
	void CheckSurfaceBelowDirtmound(PlayerBase player, Dirtmound item_DM, Hologram hologram)
	{
		if (item_DM) // TO DO: When GardenPlot is renamed back to GardenPlot then remove this check.
		{
			if ( item_DM.CanBePlaced(player, item_DM.GetPosition() )  )
			{
				if( item_DM.CanBePlaced(NULL, item_DM.CoordToParent(hologram.GetLeftCloseProjectionVector())) )
				{
					if( item_DM.CanBePlaced(NULL, item_DM.CoordToParent(hologram.GetRightCloseProjectionVector())) )
					{
						if( item_DM.CanBePlaced(NULL, item_DM.CoordToParent(hologram.GetLeftFarProjectionVector())) )
						{
							if( item_DM.CanBePlaced(NULL, item_DM.CoordToParent(hologram.GetRightFarProjectionVector())) )
							{
								hologram.SetIsCollidingGPlot( false );
	
								return;
							}
						}
					}
				}
			}
			
			hologram.SetIsCollidingGPlot( true );
		}
	}
	
	override void OnFinishProgressClient( ActionData action_data )
	{
		
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{	
		PlaceObjectActionData poActionData;
		poActionData = PlaceObjectActionData.Cast(action_data);
		EntityAI entity_for_placing = action_data.m_MainItem; //EntityAI.Cast(  );
		vector position = action_data.m_Player.GetLocalProjectionPosition();
		vector orientation = action_data.m_Player.GetLocalProjectionOrientation();
				
		if ( GetGame().IsMultiplayer() )
		{		
			dirtmound = Dirtmound.Cast( action_data.m_Player.GetHologramServer().PlaceEntity( entity_for_placing ));
			dirtmound.SetOrientation( orientation );
			action_data.m_Player.GetHologramServer().CheckPowerSource();
			action_data.m_Player.PlacingCompleteServer();	
				
			dirtmound.OnPlacementComplete( action_data.m_Player );
		}
			
		//local singleplayer
		if ( !GetGame().IsMultiplayer())
		{						
			dirtmound = Dirtmound.Cast( action_data.m_Player.GetHologramLocal().PlaceEntity( entity_for_placing ));
			dirtmound.SetOrientation( orientation );
			action_data.m_Player.PlacingCompleteLocal();
			
			dirtmound.OnPlacementComplete( action_data.m_Player );
		}
		
		GetGame().ClearJuncture( action_data.m_Player, entity_for_placing );
		action_data.m_MainItem.SetIsBeingPlaced( false );
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		poActionData.m_AlreadyPlaced = true;	
		action_data.m_MainItem.SoundSynchRemoteReset();
		action_data.m_MainItem.DecreaseHealth ( "", "", 50 );
	}
};
