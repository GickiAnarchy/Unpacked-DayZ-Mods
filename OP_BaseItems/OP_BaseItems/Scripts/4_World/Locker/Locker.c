class Locker : Container_Base
{   
    protected ref OpenableBehaviour m_OPOpenable;

    const string ATTACHMENT_SLOT_COMBINATION_LOCK = "Att_CombinationLock";
    const string ATTACHMENT_SLOT_GRENADE = "tripWireAttachment";

    typename ATTACHMENT_COMBINATION_LOCK    = OPLock;
    typename ATTACHMENT_GRENADE     = Grenade_Base;

    void Locker()
    {   

        m_OPOpenable = new OpenableBehaviour(false);
        RegisterNetSyncVariableBool("m_OPOpenable.m_IsOpened");
        RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
        RegisterNetSyncVariableBool("m_IsPlaceSound");
    }

    override void EEInit()
    {
        super.EEInit();
        GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
    }
    
    Grenade_Base GetGbase()
    {
        Grenade_Base gbase = Grenade_Base.Cast( FindAttachmentBySlotName( ATTACHMENT_SLOT_GRENADE ) );
        return gbase;
    }

    OPLock GetOPLock()
    {
        OPLock op_lock = OPLock.Cast( FindAttachmentBySlotName( ATTACHMENT_SLOT_COMBINATION_LOCK ) );
        return op_lock;
    }
    
    vector GetLockSpawnPosition()
    {
        vector position;
        position = GetMemoryPointPos( "lock_spawn_position" );
            
        return ModelToWorld( position ); 
    }   

    override void Open()
    {
        m_OPOpenable.Open();
    
        GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
        SoundSynchRemote();
        UpdateVisualState();
    } 

    override void Close()
    {
        m_OPOpenable.Close();
        
        UpdateVisualState();
        GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
        SoundSynchRemote();
        OPLock oplock = GetOPLock();
        if ( oplock && !oplock.IsLocked() )
        {
            oplock.LockServer( this );
        }
    }

    override bool IsOpen()
    {
        return m_OPOpenable.IsOpened();
    }

    void UpdateVisualState()
    {
        if ( IsOpen() )
        {
            SetAnimationPhase("Lid1",0);
            SetAnimationPhase("Lid3",1);
        }
        else
        {
            SetAnimationPhase("Lid1",1);
            SetAnimationPhase("Lid3",0);
        }
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////
    bool IsLocked()
    {
        OPLock op_lock = GetOPLock();
        if ( op_lock && op_lock.IsLocked() )
        {
            GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
            Close();
            return true;
        }
        
        return false;
    }

    bool CanOpenLocker()
    {
        if (!IsOpen() && !IsLocked() )
        {
            return true;
        }
        
        return false;
    }

    override bool CanPutInCargo( EntityAI parent )
    {
        if( !super.CanPutInCargo(parent) ) {return false;}      
        if (!IsOpen() && !IsLocked() )
        {
            return true;
        }
        return false;
    }
    override bool CanPutIntoHands( EntityAI parent )
    {
        if( !super.CanPutIntoHands( parent ) )
        {
            return false;
        }    
        if (!IsOpen() && !IsLocked() )
        {
            return true;
        }
        return false;
    }


    override void EEItemAttached( EntityAI item, string slot_name )
    {
        super.EEItemAttached( item, slot_name );
        /*
        if ( item.IsInherited( OPLock ) )
        {
            OPLock op_lock = OPLock.Cast( item );
            op_lock.LockServer( this );
            Close();
        }*/
        if ( item.IsInherited( Grenade_Base ) )
        {
            //Close(); 
            SetAnimationPhase( "Grenadewire", 0 );  
        }
        
        if ( item.IsKindOf ( "CamoNet" ) ) 
        {
            SetAnimationPhase( "Camonet", 0 );                
        }
        if (AliceBag_ColorBase.Cast(item))
        {
            HideSelection("Lockerbag");
        }
    }

    override void EEItemDetached(EntityAI item, string slot_name)
    {
        super.EEItemDetached(item, slot_name);
                
        if ( item.IsKindOf ( "CamoNet" ) ) 
        {
            SetAnimationPhase( "Camonet", 1 );
        }
        if (AliceBag_ColorBase.Cast(item))
        {
            ShowSelection("Lockerbag");
        }
        if ( item.IsInherited( Grenade_Base ) )
        {
            //Close();
            SetAnimationPhase( "Grenadewire", 1 );  
        }
    }

    override void OnVariablesSynchronized()
    {
        super.OnVariablesSynchronized();
                
        if ( IsPlaceSound() )
        {
            PlayPlaceSound();
        }
        else
        {
            if ( IsOpen() && IsSoundSynchRemote() && !IsBeingPlaced() )
            {
                SoundBarrelOpenPlay();
            }
            
            if ( !IsOpen() && IsSoundSynchRemote() && !IsBeingPlaced() )
            {
                SoundBarrelClosePlay();
            }
        }
        
        UpdateVisualState();
    }
    
    void SoundBarrelOpenPlay()
    {
        EffectSound sound = SEffectManager.PlaySound( "barrel_open_SoundSet", GetPosition() );
        sound.SetSoundAutodestroy( true );
    }
    void SoundBarrelClosePlay()
    {
        EffectSound sound = SEffectManager.PlaySound( "barrel_close_SoundSet", GetPosition() );
        sound.SetSoundAutodestroy( true );
    }
    override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
    {       
        super.OnPlacementComplete( player );
        SetLifetime(3888000);
        SetIsPlaceSound( true );
    }

    override string GetPlaceSoundset()
    {
        return "placeBarrel_SoundSet";
    }

    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionTogglePlaceObject);
        AddAction(ActionPlaceObject);       
        AddAction(ActionDialOPLockOnLocker);
        AddAction(ActionNextOPLockDialOnLocker);
        AddAction(ActionCloseLocker);
        AddAction(ActionOpenLocker);     
    }
}
class OP_Lockerblue : Locker{};
class OP_StorageCabinetBase extends Locker
{
    override void UpdateVisualState()
    {
        if ( IsOpen() )
        {
            SetAnimationPhase("Lid1",1);
            SetAnimationPhase("Lid3",0);
        }
        else
        {
            SetAnimationPhase("Lid1",0);
            SetAnimationPhase("Lid3",0);
        }
    }  
    override void EEItemAttached( EntityAI item, string slot_name )
    {
        super.EEItemAttached( item, slot_name );
        /*
        if ( item.IsInherited( OPLock ) )
        {
            OPLock op_lock = OPLock.Cast( item );
            op_lock.LockServer( this );
            Close();
        }*/
    }
}

class ActionDestroyGbaseOnLockerCB : ActionContinuousBaseCB
{
    override void CreateActionComponent()
    {
        m_ActionData.m_ActionComponent = new CAContinuousTime(5);
    }
};

class ActionDestroyGbaseOnLocker: ActionContinuousBase
{   
    void ActionDestroyGbaseOnLocker()
    {
        m_CallbackClass = ActionDestroyGbaseOnLockerCB;
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
        m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;     
        m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
    /*
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
        m_FullBody = true;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
        m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_MEDIUM;*/
    }
    
    override void CreateConditionComponents()  
    {   
        m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
        m_ConditionItem = new CCINonRuined;
    }
    override string GetText()
    {
        return "Disarm Trap";
    }

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
        Object targetObject = target.GetObject();
        if ( targetObject )
        {
            Locker locker = Locker.Cast( targetObject );
            
            if ( locker && locker.GetAttachmentByType(Grenade_Base) )
            {
                return true;
            };
        };
        return false;
    }

    override void OnFinishProgressServer( ActionData action_data )
    {   
        Locker locker = Locker.Cast( action_data.m_Target.GetObject() );
        if ( locker )
        {
            float rand;
            rand = Math.RandomFloatInclusive(0.0, 1.0);

            Grenade_Base gbase = locker.GetGbase();

            
           // Print(gbase.GetType());


            if ( gbase )
            {
                if ( rand < 0.99 )
                {
                    GetGame().CreateObject(gbase.GetType(), locker.GetLockSpawnPosition()); 
                    GetGame().ObjectDelete(gbase);           
                }   
                else
                {
                    gbase.AActivate();
                }
            }           
        }
    }
};

    
