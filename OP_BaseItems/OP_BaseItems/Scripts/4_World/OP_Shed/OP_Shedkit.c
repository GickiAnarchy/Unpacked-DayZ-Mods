class OP_ShedKit extends ItemBase
{   
    ref protected EffectSound                       m_DeployLoopSound;
    protected Object            m_ClutterCutter;
    void OP_ShedKit()
    {
        m_DeployLoopSound = new EffectSound;
        RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
        RegisterNetSyncVariableBool("m_IsDeploySound");
    }
    
    void ~OP_ShedKit()
    {
        if ( m_DeployLoopSound )
        {
            SEffectManager.DestroySound( m_DeployLoopSound );
        }
    }
    
    override void EEInit()
    {
        super.EEInit();
        
        //set visual on init
        UpdateVisuals();
       // UpdatePhysics();
    }
    
    override void AfterStoreLoad()
    {   
    }
    override void OnItemLocationChanged( EntityAI old_owner, EntityAI new_owner ) 
    {
        super.OnItemLocationChanged( old_owner, new_owner );
        
        //update visuals after location change
   //     UpdatePhysics();
    }
        
    
    //Update visuals and physics
    void UpdateVisuals()
    {
        SetAnimationPhase( "Inventory", 0 );
        SetAnimationPhase( "Placing", 1 );
    }
    /*
    void UpdatePhysics()
    {
        AddProxyPhysics( "Inventory" );
        RemoveProxyPhysics( "Placing" );        
    }   
    
    /*override bool IsOneHandedBehaviour()
    {
        return true;
    }*/
    
    override void OnVariablesSynchronized()
    {
        super.OnVariablesSynchronized();
        
        if ( IsDeploySound() )
        {
            PlayDeploySound();
        }
                
        if ( CanPlayDeployLoopSound() )
        {
            PlayDeployLoopSound();
        }
                    
        if ( m_DeployLoopSound && !CanPlayDeployLoopSound() )
        {
            StopDeployLoopSound();
        }
    }
    
    //================================================================
    // ADVANCED PLACEMENT
    //================================================================          
        
    override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
    {
        if ( GetGame().IsServer() )
        {
            //Create fence
            PlayerBase player_base = PlayerBase.Cast( player );
            vector position1 = player_base.GetLocalProjectionPosition();
            vector orientation1 = player_base.GetLocalProjectionOrientation();
            
            OP_Shed fence = OP_Shed.Cast( GetGame().CreateObject( "OP_Shed", GetPosition() ) );
            fence.SetPosition( position );
            fence.SetOrientation( orientation );
            fence.SetLifetime(3888000);
            
                //
          //  m_ClutterCutter = GetGame().CreateObject( "LargeTentClutterCutter", player_base.GetLocalProjectionPosition(), false );
          //  m_ClutterCutter.SetOrientation( player_base.GetLocalProjectionOrientation() );   

         //   GetGame().ObjectDelete(this) deleting object this way causes a player to not interact with anything for a 5 second peried, delete in the UA
            
            SetIsDeploySound( true );
        }   
    }
    
    override bool IsDeployable()
    {
        return true;
    }   
    
    override string GetDeploySoundset()
    {
        return "putDown_FenceKit_SoundSet";
    }
    
    override string GetLoopDeploySoundset()
    {
        return "BarbedWire_Deploy_loop_SoundSet";
    }
    
    void PlayDeployLoopSound()
    {       
        if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
        {       
            if ( !m_DeployLoopSound.IsSoundPlaying() )
            {
                m_DeployLoopSound = SEffectManager.PlaySound( GetLoopDeploySoundset(), GetPosition() );
            }
        }
    }
    
    void StopDeployLoopSound()
    {
        if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
        {   
            m_DeployLoopSound.SetSoundFadeOut(0.5);
            m_DeployLoopSound.SoundStop();
        }
    }
    
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
        AddAction(ActionDeployOPBI);
    }
}
class OP_ShedKitProjection : ItemBase{}
class CraftShedKit extends RecipeBase
{   
    override void Init()
    {
        //m_Name = "#STR_CraftHandDrillKit0";
        m_Name = "Craft Shedkit";
        m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
        m_AnimationLength = 0.5;//animation length in relative time units
        m_Specialty = -0.02;// value > 0 for roughness, value < 0 for precision
        
        
        //conditions
        m_MinDamageIngredient[0] = -1;//-1 = disable check
        m_MaxDamageIngredient[0] = 3;//-1 = disable check
        
        m_MinQuantityIngredient[0] = 1;//-1 = disable check
        m_MaxQuantityIngredient[0] = -1;//-1 = disable check
        
        m_MinDamageIngredient[1] = -1;//-1 = disable check
        m_MaxDamageIngredient[1] = 3;//-1 = disable check
        
        m_MinQuantityIngredient[1] = 2;//-1 = disable check
        m_MaxQuantityIngredient[1] = -1;//-1 = disable check
        //----------------------------------------------------------------------------------------------------------------------
        
        //INGREDIENTS
        //ingredient 1
        InsertIngredient(0,"Rope");//you can insert multiple ingredients this way
        
        m_IngredientAddHealth[0] = 0;// 0 = do nothing
        m_IngredientSetHealth[0] = -1; // -1 = do nothing
        m_IngredientAddQuantity[0] = -1;// 0 = do nothing
        m_IngredientDestroy[0] = true;//true = destroy, false = do nothing
        m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
        
        //ingredient 2
        InsertIngredient(1,"WoodenStick");//you can insert multiple ingredients this way
        InsertIngredient(1,"Ammo_SharpStick");//you can insert multiple ingredients this way
        
        m_IngredientAddHealth[1] = 0;// 0 = do nothing
        m_IngredientSetHealth[1] = -1; // -1 = do nothing
        m_IngredientAddQuantity[1] = -2;// 0 = do nothing
        m_IngredientDestroy[1] = false;// false = do nothing
        m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
        //----------------------------------------------------------------------------------------------------------------------
        
        //result1
        AddResult("OP_ShedKit");//add results here

        m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
        m_ResultSetQuantity[0] = -1;//-1 = do nothing
        m_ResultSetHealth[0] = -1;//-1 = do nothing
        m_ResultInheritsHealth[0] = -2;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
        m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
        m_ResultToInventory[0] = -2;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
        m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
        m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
    }

    override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
    {
        return true;
    }

    override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
    {
        Debug.Log("Recipe Do method called","recipes");
    }
};
