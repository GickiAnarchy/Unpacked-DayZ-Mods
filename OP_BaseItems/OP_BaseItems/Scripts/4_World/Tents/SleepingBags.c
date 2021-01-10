class OP_SleepingBagBlue extends TentBase
{
	void OP_SleepingBagBlue()
	{			
		m_ShowAnimationsWhenPitched.Insert( "Body" );
		m_ShowAnimationsWhenPitched.Insert( "Pack" );
		m_ShowAnimationsWhenPacked.Insert( "Inventory");
	}
		
	override void EEInit()
	{		
		super.EEInit();
	}
	
	override void OnItemLocationChanged(EntityAI old_owner, EntityAI new_owner)
	{		
		super.OnItemLocationChanged(old_owner, new_owner);
	}
	
	override string GetSoundOpen()
	{
		return "MediumTent_Door_Open_SoundSet";
	}
	
	override string GetSoundClose()
	{
		return "MediumTent_Door_Close_SoundSet";
	}
	
	override bool HasClutterCutter()
	{
		return true;
	}
	
	override string GetClutterCutter()
	{
		return "MediumTentClutterCutter";
	}
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
		
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
			
		PlayerBase pb = PlayerBase.Cast( player );
		SetLifetime(3888000);
		if ( GetGame().IsServer() )
		{
			if ( !m_ClutterCutter )
			{
				m_ClutterCutter = GetGame().CreateObject( "MediumTentClutterCutter", pb.GetLocalProjectionPosition(), false );
				m_ClutterCutter.SetOrientation( pb.GetLocalProjectionOrientation() );	
			}
		}
	}
    override void SetActions()
    {
        super.SetActions();
        
     	AddAction(ActionPackTentOP);
       	RemoveAction(ActionPackTent);
        //RemoveAction(ActionToggleTentOpen);	
    }	
		
	override string GetDeploySoundset()
	{
		return "placeMediumTent_SoundSet";
	}
	
	override string GetLoopDeploySoundset()
	{
		return "mediumtent_deploy_SoundSet";
	}	
};
class OP_SleepingBagGrey extends TentBase
{
	void OP_SleepingBagGrey()
	{			
		m_ShowAnimationsWhenPitched.Insert( "Body" );
		m_ShowAnimationsWhenPitched.Insert( "Pack" );
		m_ShowAnimationsWhenPacked.Insert( "Inventory");
	}
		
	override void EEInit()
	{		
		super.EEInit();
	}
	
	override void OnItemLocationChanged(EntityAI old_owner, EntityAI new_owner)
	{		
		super.OnItemLocationChanged(old_owner, new_owner);
	}
	
	override string GetSoundOpen()
	{
		return "MediumTent_Door_Open_SoundSet";
	}
	
	override string GetSoundClose()
	{
		return "MediumTent_Door_Close_SoundSet";
	}
	
	override bool HasClutterCutter()
	{
		return true;
	}
	
	override string GetClutterCutter()
	{
		return "MediumTentClutterCutter";
	}
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
		
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
			
		PlayerBase pb = PlayerBase.Cast( player );
		SetLifetime(3888000);
		if ( GetGame().IsServer() )
		{
			if ( !m_ClutterCutter )
			{
				m_ClutterCutter = GetGame().CreateObject( "MediumTentClutterCutter", pb.GetLocalProjectionPosition(), false );
				m_ClutterCutter.SetOrientation( pb.GetLocalProjectionOrientation() );	
			}
		}
	}
    override void SetActions()
    {
        super.SetActions();
        
     	AddAction(ActionPackTentOP);
       	RemoveAction(ActionPackTent);
        //RemoveAction(ActionToggleTentOpen);	
    }	
		
	override string GetDeploySoundset()
	{
		return "placeMediumTent_SoundSet";
	}
	
	override string GetLoopDeploySoundset()
	{
		return "mediumtent_deploy_SoundSet";
	}	
};
class OP_SleepingBagCamo extends TentBase
{
	void OP_SleepingBagCamo()
	{			
		m_ShowAnimationsWhenPitched.Insert( "Body" );
		m_ShowAnimationsWhenPitched.Insert( "Pack" );
		m_ShowAnimationsWhenPacked.Insert( "Inventory");
	}
		
	override void EEInit()
	{		
		super.EEInit();
	}
	
	override void OnItemLocationChanged(EntityAI old_owner, EntityAI new_owner)
	{		
		super.OnItemLocationChanged(old_owner, new_owner);
	}
	
	override string GetSoundOpen()
	{
		return "MediumTent_Door_Open_SoundSet";
	}
	
	override string GetSoundClose()
	{
		return "MediumTent_Door_Close_SoundSet";
	}
	
	override bool HasClutterCutter()
	{
		return true;
	}
	
	override string GetClutterCutter()
	{
		return "MediumTentClutterCutter";
	}
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
		
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
			
		PlayerBase pb = PlayerBase.Cast( player );
		SetLifetime(3888000);
		if ( GetGame().IsServer() )
		{
			if ( !m_ClutterCutter )
			{
				m_ClutterCutter = GetGame().CreateObject( "MediumTentClutterCutter", pb.GetLocalProjectionPosition(), false );
				m_ClutterCutter.SetOrientation( pb.GetLocalProjectionOrientation() );	
			}
		}
	}
    override void SetActions()
    {
        super.SetActions();
        
     	AddAction(ActionPackTentOP);
       	RemoveAction(ActionPackTent);
        //RemoveAction(ActionToggleTentOpen);	
    }	
		
	override string GetDeploySoundset()
	{
		return "placeMediumTent_SoundSet";
	}
	
	override string GetLoopDeploySoundset()
	{
		return "mediumtent_deploy_SoundSet";
	}	
};
