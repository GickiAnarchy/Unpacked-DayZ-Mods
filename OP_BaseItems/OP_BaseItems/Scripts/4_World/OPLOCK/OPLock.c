class OPLock extends ItemBase
{
	int m_OPLockDigits;					//how many digits will the combination contain
	int m_OPCombination;					//actual combination that is dialed on lock
	int m_OPCombinationLocked;			//combination that was dialed on lock before the shuffle
	int m_OPDialIndex;					//index of current combination dial
	
	protected LockAction m_LockActionPerformed 		= LockAction.NONE;
	
	protected bool m_IsInitialized;
	
	//Sounds
	//build
	const string SOUND_LOCK_OPEN 			= "combinationlock_open_SoundSet";
	const string SOUND_LOCK_CLOSE 			= "combinationlock_close_SoundSet";
	const string SOUND_LOCK_CHANGE_NUMBER	= "combinationlock_changenumber_SoundSet";
	const string SOUND_LOCK_CHANGE_DIAL		= "combinationlock_changedial_SoundSet";

	protected EffectSound m_Sound;

	void OPLock()
	{
		SetBaseLockValues();
		
		//synchronized variables
		int combination_length = Math.Pow( 10, m_OPLockDigits );
		RegisterNetSyncVariableInt( "m_OPCombination", 0, combination_length - 1 );
		RegisterNetSyncVariableInt( "m_OPCombinationLocked", 0, combination_length - 1 );
		RegisterNetSyncVariableInt( "m_OPDialIndex", 0, m_OPLockDigits - 1 );
		RegisterNetSyncVariableInt( "m_LockActionPerformed", 0, LockAction.COUNT );
	}
	
	protected void SetBaseLockValues()
	{
		//set lock init values
		m_OPLockDigits 			= 5;
		m_OPCombination		 	= 11111;
		m_OPCombinationLocked 	= 99999;		
	}

	override void EEInit()
	{
		super.EEInit();
		
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( SetInitialized, 1000, false );
		//SetInitialized();
		
		//set visual on init
	//	UpdateVisuals();
	}
	
	void SetInitialized()
	{
		m_IsInitialized = true;
	}
	
	bool IsInitialized()
	{
		return m_IsInitialized;
	}
	
	override void OnItemLocationChanged( EntityAI old_owner, EntityAI new_owner ) 
	{
		super.OnItemLocationChanged( old_owner, new_owner );
		
		//Check combination lock
		if ( GetGame().IsServer() )
		{
			if ( IsInitialized() && new_owner )
			{
				LockServer( new_owner );
				OP_Shed shed = OP_Shed.Cast(new_owner); // LOCKERS handled in class
				if ( shed )
				{	
					shed.CloseFence();
				}
			}
		}		
	}	
	
	// --- EVENTS
	override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave( ctx );
		
		//write data
		ctx.Write( m_OPCombination );
		ctx.Write( m_OPCombinationLocked );
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		
		//--- Combination Lock data ---
		//combination
		if ( !ctx.Read( m_OPCombination ) )
		{
			m_OPCombination = 0;
			return false;
		}
		
		//combination locked
		if ( !ctx.Read( m_OPCombinationLocked ) )
		{
			m_OPCombinationLocked = 0;
			return false;
		}
		
		return true;
	}
	/*
	override void AfterStoreLoad()
	{	
		super.AfterStoreLoad();		
		
		//Check combination lock
		if ( GetGame().IsServer() )
		{
			EntityAI parent = GetHierarchyParent();
			if ( !IsLocked())
			{
				if ( parent && parent.IsInherited( Locker ) || parent && parent.IsInherited(OP_Shed) )
				{
					LockServer( parent, true );
				}
			}
	

		}		
		
		//synchronize
		Synchronize();
	}*/
	
	// --- SYNCHRONIZATION
	void Synchronize()
	{
	
		if ( GetGame().IsServer() )
		{
			SetSynchDirty();
			
		//	UpdateVisuals();
		}
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		//update visuals (client)
	//pdateVisuals();
		
		//update sound (client)
		UpdateSound();
		

	}
	
	void SetCombination( int combination )
	{
		m_OPCombination = combination;
	}
	
	void SetCombinationLocked( int combination )
	{
		m_OPCombinationLocked = combination;
	}
	
	int GetCombination()
	{
		return m_OPCombination;
	}

	int GetCombinationLocked()
	{
		return m_OPCombinationLocked;
	}
	
	int GetLockDigits()
	{
		return m_OPLockDigits;
	}
	
	// --- ACTIONS
	void DialNextNumber()
	{
		string combination_text = m_OPCombination.ToString();
		string dialed_text;
		
		//insert zeros to dials with 0 value
		int length_diff = m_OPLockDigits - combination_text.Length();
		for ( int i = 0; i < length_diff; ++i )
		{
			combination_text = "0" + combination_text;
		}
		
		//assemble the whole combination with increased part
		for ( int j = 0; j < combination_text.Length(); ++j )
		{
			if ( j == m_OPDialIndex )
			{
				int next_dialed_number = combination_text.Get( j ).ToInt() + 1;
				if ( next_dialed_number > 9 )
				{
					next_dialed_number = 0;
				}
				
				dialed_text += next_dialed_number.ToString();
			}
			else
			{
				dialed_text += combination_text.Get( j );
			}
		}
		
		//set new number		
		SetCombination( dialed_text.ToInt() );
		m_LockActionPerformed = LockAction.DIAL_INDEX_CHANGED;
		
		//synchronize
		Synchronize();
	}
	
	int GetDialIndex()
	{
		return m_OPDialIndex;
	}
	
	void SetNextDial()
	{
		if ( m_OPLockDigits > 1 )
		{
			if ( m_OPDialIndex <= m_OPLockDigits - 2 )
			{
				m_OPDialIndex++;
			}
			else if ( m_OPDialIndex >= m_OPLockDigits >  - 1 )
			{
				m_OPDialIndex = 0;
			}
		}
		else
		{
			m_OPDialIndex = 0;
		}
		
		//performed action
		m_LockActionPerformed = LockAction.DIAL_NUMBER_CHANED;
		
		//synchronize
		Synchronize();
	}	
	
	//Lock lock
	void LockServer( EntityAI parent, bool ignore_combination = false )
	{
		//
		if ( IsLockAttached() )
		{
			Locker locker = Locker.Cast( parent );
			if ( !ignore_combination )
			{
				SetCombinationLocked( m_OPCombination );
			
				//set slot lock
				InventoryLocation inventory_location = new InventoryLocation;
				GetInventory().GetCurrentInventoryLocation( inventory_location );		
				parent.GetInventory().SetSlotLock( inventory_location.GetSlot(), true );		
				m_LockActionPerformed = LockAction.LOCKED;
			}
			ShuffleLock();
			
			//synchronize
			Synchronize();
		}
		
		//reset performed action
		//m_LockActionPerformed = LockAction.NONE;
	}
	
	void UnlockServer( notnull EntityAI player, EntityAI parent )
	{
	
		if ( IsLockAttached() )
		{
			Locker locker = Locker.Cast( parent );
			InventoryLocation inventory_location = new InventoryLocation;
			if (locker)
			{
				
				GetInventory().GetCurrentInventoryLocation( inventory_location );			
				locker.GetInventory().SetSlotLock( inventory_location.GetSlot(), false );	
				//synchronize
				Synchronize();
			}
			OP_Shed shed = OP_Shed.Cast( parent );
			if ( shed )
			{
				GetInventory().GetCurrentInventoryLocation( inventory_location );			
				shed.GetInventory().SetSlotLock( inventory_location.GetSlot(), false );	
				//synchronize
				Synchronize();
			}
			
		}
		
		//reset performed action
		//m_LockActionPerformed = LockAction.NONE;		
	}

	/*
	something changed with serverdropentity which now causes a client crash after the lock is detatched
[desync] HandleInputData man=SurvivorM_Peter:01 CANNOT move cmd=SYNC_MOVE src={ type=ATTACHMENT item=OPLock:07745 parent=Locker:08886 slot=-1288214684 } dst={ type=GROUND item=OPLock:07745 pos=(3292.07, 200.107, 12741.2) dir=(0.702937, -0.016495, 0.71104, 0.000564584) }
	*/
		
	//Shuffle lock
	void ShuffleLock()
	{
		string combination_text = m_OPCombination.ToString();
		string shuffled_text;
		
		//insert zeros to dials with 0 value
		int length_diff = m_OPLockDigits - combination_text.Length();
		for ( int i = 0; i < length_diff; ++i )
		{
			combination_text = "0" + combination_text;
		}
		
		//assemble the whole combination with increased part
		for ( int j = 0; j < combination_text.Length(); ++j )
		{
			int dial_number = combination_text.Get( j ).ToInt();
			dial_number = ( dial_number + Math.RandomInt( 1, 9 ) ) % 10;
			shuffled_text = shuffled_text + dial_number.ToString();
		}
		
		SetCombination( shuffled_text.ToInt() );
	}
	
	bool IsLocked()
	{
		if ( m_OPCombination != m_OPCombinationLocked )
		{
			return true;
		}
		
		return false;
	}
	

	bool IsLockedOnLocker()
	{
		Locker locker = Locker.Cast( GetHierarchyParent() );
		if ( locker )
		{
			if ( IsLocked() )
			{
				return true;
			}
		}
		return false;
	}
	
	bool IsLockedOnShed()
	{
		OP_Shed shed = OP_Shed.Cast( GetHierarchyParent() );
		if ( shed )
		{
			if ( IsLocked() )
			{
				return true;
			}
		}
		return false;
	}
	bool IsLockAttached()
	{
		Locker locker = Locker.Cast( GetHierarchyParent() );
		if ( locker )
		{
			return true;
		}
		OP_Shed shed = OP_Shed.Cast( GetHierarchyParent() );
		if ( shed )
		{
			return true;
		}
		
		return false;
	}
	
	//destroy lock
	void DestroyLock()
	{
		GetGame().ObjectDelete( this );
	}
	
	void UpdateSound()
	{
		//was locked
		if ( m_LockActionPerformed == LockAction.LOCKED )
		{
			SoundLockClose();
		}
		
		//was unlocked
		if ( m_LockActionPerformed == LockAction.UNLOCKED )
		{
			SoundLockOpen();
		}
		
		//next dial index
		if ( m_LockActionPerformed == LockAction.DIAL_INDEX_CHANGED )
		{
			SoundLockChangeDial();
		}		
		
		//dialed new number
		if ( m_LockActionPerformed == LockAction.DIAL_NUMBER_CHANED )
		{
			SoundLockChangeNumber();
		}
	}
	
	//================================================================
	// SOUNDS
	//================================================================
	protected void SoundLockOpen()
	{
		PlaySoundSet( m_Sound, SOUND_LOCK_OPEN, 0, 0 );
	}

	protected void SoundLockClose()
	{
		PlaySoundSet( m_Sound, SOUND_LOCK_CLOSE, 0, 0 );
	}
	
	void SoundLockChangeNumber()
	{
		PlaySoundSet( m_Sound, SOUND_LOCK_CHANGE_NUMBER, 0, 0 );
	}

	void SoundLockChangeDial()
	{
		PlaySoundSet( m_Sound, SOUND_LOCK_CHANGE_DIAL, 0, 0 );
	}	
	
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionAttach);		
		AddAction(ActionDialOPLock);
		AddAction(ActionNextOPLockDial);
		    
	}
}
