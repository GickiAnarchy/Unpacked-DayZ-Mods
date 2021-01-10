modded class Grenade_Base
{

    void PopLockandDropit( notnull EntityAI player, EntityAI parent ) // so the explosion fx are still visible when opening locker with grenade in slot
    {
        Locker locker = Locker.Cast( parent );
        if ( locker )
        {
            AActivate(); 
        }
    }

    void AActivate()
    {
        if( !m_FuseTimer.IsRunning() )
        {
            //! run only the remaining part (already unpinned and pinned)
            if( m_RemainingFuseTime > 0 )
            {
                m_FuseTimer.Run(m_RemainingFuseTime, this, "OnActivateFinished");
            }
            else
            {
                m_FuseTimer.Run(2, this, "OnActivateFinished"); // 4 is too long
            }

        }
    }
}/*
modded class ActionDestroyCombinationLock
{   
    override void OnFinishProgressServer( ActionData action_data )
    {   
        OP_Shed shed = OP_Shed.Cast( action_data.m_Target.GetObject() );
        if ( shed )
        {
            OPLock lock = shed.GetOPLock();
            if ( lock )
            {
                lock.UnlockServer( action_data.m_Player, shed );
                GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( lock.DestroyLock, 200, false );
       
        
                action_data.m_MainItem.DecreaseHealth( UADamageApplied.SAW_LOCK, false );
        
        //soft skills
                action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
             }
        }
        super.OnFinishProgressServer( action_data );
    }
};