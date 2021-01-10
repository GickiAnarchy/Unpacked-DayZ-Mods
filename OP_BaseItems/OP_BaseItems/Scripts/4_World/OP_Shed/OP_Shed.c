/*class OP_Shed2 : OP_Shed // test shed (nav mesh not generated )
{
    void OP_Shed2()
    {
        m_Construction.BuildPartServer( "Base_Frame", 1 );
        m_Construction.BuildPartServer( "Base_Wood", 2 );
        m_Construction.BuildPartServer( "Wall1_Frame", 3 );
        m_Construction.BuildPartServer( "Wall2_Frame", 4 );
        m_Construction.BuildPartServer( "Wall3_Frame", 5 );
        m_Construction.BuildPartServer( "Wall4_Frame", 6 );
        m_Construction.BuildPartServer( "Roof_Frame", 7 );
        m_Construction.BuildPartServer( "Wall1_Wood", 8 );
        m_Construction.BuildPartServer( "Wall2_Wood", 9 );
        m_Construction.BuildPartServer( "Wall3_Wood", 10 );
        m_Construction.BuildPartServer( "Wall4_Wood", 11 );
        m_Construction.BuildPartServer( "Roof_Wood", 12 );
        m_Construction.BuildPartServer( "Doors1", 13 );
        m_Construction.BuildPartServer( "Doors2", 14 );
        m_Construction.BuildPartServer( "Roof_Metal", 15 );
    }
}*/
class OP_Shed extends Fence
{
    typename ATTACHMENT_CAMONET    = CamoNet;
    typename ATTACHMENT_LOCK    = OPLock;


    void OP_Shed()
    {
        if ( GetGame().IsServer() )
        {
            SetAllowDamage(false);
        }
    }
    
    OPLock GetOPLock()
    {
        OPLock op_lock = OPLock.Cast( GetAttachmentByType( OPLock ) );
        return op_lock;
    }

    override string GetConstructionKitType()
    {
        return "OP_ShedKit";
    }

    override bool CanDisplayAttachmentSlot( string slot_name )
    {
        ConstructionPart doors1 = GetConstruction().GetConstructionPart("Doors1");
        ConstructionPart doors2 = GetConstruction().GetConstructionPart("Doors2");
        
        if ( slot_name == "Att_CombinationLock" || slot_name == "CamoNet" )
        {

            return true; // fix soon
        }
        
        return true;
    }

    protected bool m_HasGate        = false;
    //Gate
    bool HasGate()
    {
        return m_HasGate;
    }

    void SetGateState( bool has_gate )
    {
        m_HasGate = has_gate;
    }   
    
    override bool IsInventoryVisible()
    {
       /* PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );

        vector ref_pos;
        vector ref_dir;
        vector cam_dir = GetGame().GetCurrentCameraDirection();
        if ( MemoryPointExists( "center" ) )
        {
            ref_pos = ModelToWorld( GetMemoryPointPos( "center" ) );
            ref_dir = ref_pos - GetPosition();
            
            ref_dir.Normalize();
            ref_dir[1] = 0;     //ignore height
            
            cam_dir[1] = 0;     //ignore height
            
            if ( ref_dir.Length() > 0.5 )       //if the distance (m) is too low, ignore this check
            {
                float dot = vector.Dot( cam_dir, ref_dir );
            
                if ( dot < 0 )  
                {
                    return true;
                }
            }
        }
        return false;*/
        return true;
    }
 
    override bool CanReceiveAttachment( EntityAI attachment, int slotId )
    {
        ItemBase item = ItemBase.Cast( attachment );
        //manage action initiator (AT_ATTACH_TO_CONSTRUCTION)
        if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
        {
            PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
            if ( player )
            {
                ConstructionActionData construction_action_data = player.GetConstructionActionData();
                
                //reset action initiator
                construction_action_data.SetActionInitiator( NULL );                
            }
        }
        if ( attachment.IsInherited( ATTACHMENT_CAMONET ) ||  attachment.IsInherited(ATTACHMENT_LOCK)  )
        {
            ConstructionPart doors1 = GetConstruction().GetConstructionPart("Doors1");
            ConstructionPart doors2 = GetConstruction().GetConstructionPart("Doors2");

            if ( doors1.IsBuilt() && doors2.IsBuilt() )
            {
                return true;
            }
        }   
        if ( item.Type() == ATTACHMENT_COMBINATION_LOCK ) // would cast vanilla dialing/nextdial despite other lock being attached
        {
            return false;
        }

        return true;
    }

    override bool CanDisplayCargo()
    {
        //super
        if( IsOpened() )
        {
            return true;
        }
        //
        
        return false;
    }

    override bool CanReceiveItemIntoCargo(EntityAI cargo) // temp since candisplaycargo wont work?
    {
        return IsOpened();
    }

    bool CanReleaseCargo (EntityAI cargo)
    {
        return IsOpened();
    }
    
    override bool CanDisplayAttachmentCategory( string category_name )
    {
        //super
        if ( !super.CanDisplayAttachmentCategory( category_name ) )
        return false;
        
        if ( category_name == "Attachments"  )
        {
            if ( HasGate() )
            {
                return true;
            }           
        }
        if ( category_name == "Materials"  )
        {
                return true;         
        }
        return false;
    }
    
    override void AfterStoreLoad()
    {   
        super.AfterStoreLoad();
        
        if ( !HasBase() )
        {
            SetAnimationPhase( ANIMATION_DEPLOYED,      0 );
        }
    }
    
    override void OnPartBuiltServer( notnull Man player, string part_name, int action_id )
    {
        ConstructionPart constrution_part = GetConstruction().GetConstructionPart( part_name );
        
        //check base state
        if ( constrution_part.IsBase() )
        {
            SetBaseState( true );
            CreateConstructionKit();
            SetAnimationPhase( ANIMATION_DEPLOYED,       1 );
        }
        
        //check gate state
        if ( constrution_part.IsGate() )
        {
            SetGateState( true );
        }
        
        //register constructed parts for synchronization
        RegisterPartForSync( constrution_part.GetId() );
        
        //register action that was performed on part
        RegisterActionForSync( constrution_part.GetId(), action_id );
        
        //synchronize
        SynchronizeBaseState();
        
        if (GetGame().IsMultiplayer() && GetGame().IsServer())
            SetPartFromSyncData(constrution_part); // server part of sync, client will be synced from SetPartsFromSyncData
        
        //reset action sync data
        GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( ResetActionSyncData, 100, false, this );
        
        //update visuals (server)
        UpdateVisuals();
    }

    override void OnPartDismantledServer( notnull Man player, string part_name, int action_id )
    {
        ConstructionPart constrution_part = GetConstruction().GetConstructionPart( part_name );

        //check gate state
        if ( constrution_part.IsGate() )
        {
            SetGateState( false );
        }
        
        //check gate state
        if ( constrution_part.IsGate() )
        {
            if ( IsLocked() )
            {
                OPLock oplock = OPLock.Cast( GetAttachmentByType( OPLock ) );
                oplock.UnlockServer( player , this );
            }
        }
        
        super.OnPartDismantledServer( player, part_name, action_id );
    }

    bool IsLocked()
    {
        OPLock op_lock = GetOPLock();
        if ( op_lock && op_lock.IsLocked() )
        {
            GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
            return true;
        }
        
        return false;
    }
        override bool NameOverride(out string output)
    {
        return false;
    }
    //--- OPEN/CLOSE ACTIONS
    bool CanOpenShed()
    {
        if ( !IsOpened() && !IsLocked() )
        {
            return true;
        }
        
        return false;
    }
    
    bool CanCloseShed()
    {
        if ( IsOpened() )
        {
            return true;
        }
        
        return false;
    }
/*
    override void OnPartDestroyedServer( notnull Man player, string part_name, int action_id )
    {
        ConstructionPart constrution_part = GetConstruction().GetConstructionPart( part_name );

        //check gate state
        if ( constrution_part.IsGate() )
        {
            SetGateState( false );
        }

        super.OnPartDestroyedServer( player, part_name, action_id );
    }   */

    void OpenFence()
    {
        //server or single player
        if ( GetGame().IsServer() )
        {

            SetAnimationPhase( "Doors1_Rotate", 1 );
            GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);

            SetOpenedState( true );
            
            //regenerate navmesh
            GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( UpdateNavmesh, GATE_ROTATION_TIME_APPROX, false );
          
            //synchronize
            SynchronizeBaseState();
        }
        
        //client or single player
        if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
        {
            //play sound
            SoundGateOpenStart();
        }
        
    }

    void CloseFence()
    {
        OPLock oplock = GetOPLock();
        if ( oplock && !oplock.IsLocked() )
        {
            oplock.LockServer( this );
        }
        //server or single player
        if ( GetGame().IsServer() )
        {       

            SetAnimationPhase( "Doors1_Rotate",                0);
            SetOpenedState( false );
            
            //regenerate navmesh
            GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( UpdateNavmesh, GATE_ROTATION_TIME_APPROX, false );
            GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
            //synchronize
            SynchronizeBaseState();
        }
        
        //client or single player
        if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
        {
            //play sound
            SoundGateCloseStart();
            
            //add check
            GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( CheckFenceClosed, 0, true );
        }
    }
    
    protected void CheckFenceClosed()
    {
        if ( GetAnimationPhase( "Doors1_Rotate" ) == 0 )         //animation closed
        {
            //play sound
          //  if ( this ) SoundGateCloseEnd();
            
            //remove check
            GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Remove( CheckFenceClosed );
        }
    }
    
    override bool IsFacingPlayer( PlayerBase player, string selection )
    {
        return true;
    }
    
    override bool IsFacingCamera( string selection )
    {
        return true;
    }
    
    override bool HasProperDistance( string selection, PlayerBase player )
    {
        return true;
    }
    override bool IsPlayerInside( PlayerBase player, string selection )
    {
        return true;
    }
    
    override void SetActions()
    {
        super.SetActions();
        
        RemoveAction(ActionOpenFence);
        RemoveAction(ActionCloseFence);
        RemoveAction(ActionDialCombinationLockOnTarget); // when set up to work with both the padlock and combo lock, it wouldn't properly display the dial index
        RemoveAction(ActionNextCombinationLockDialOnTarget);
        RemoveAction(ActionDestroyCombinationLock);
        AddAction(ActionDestroyOPLockOnLocker);
        AddAction(ActionOpenShed);
        AddAction(ActionCloseShed);
        AddAction(ActionDialOPLockOnShed);
        AddAction(ActionNextOPLockDialOnShed);
    }
}
modded class ActionDestroyCombinationLock
{
    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
        Object target_object = target.GetObject();
        string selection = target_object.GetActionComponentName( target.GetComponentIndex() );
        Fence fence = Fence.Cast( target_object );
        
        if ( fence && fence.IsLocked() && selection == "wall_interact" )
        {
            CombinationLock combination_lock = fence.GetCombinationLock(); // would cast on other items inheriting fence despite no CL attached
            if ( combination_lock )
            {
                 return true;
            }   
        }
        return false;
    }
}