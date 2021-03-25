class cure_microscope : ItemBase
{ 	
	const string 				ATTACHMENT_SLOT_BRAIN = "Material_Brain";
	const string 				ATTACHMENT_SLOT_BLOODBAG = "Material_BloodBagFull";
	const string 				ATTACHMENT_SLOT_PETRIDISH = "Material_Petridish";
	static const string 		MICROSCOPE_ATTACH_SOUND = "sparkplug_attach_SoundSet";
	static const string 		MICROSCOPE_DETACH_SOUND = "sparkplug_detach_SoundSet";
	
	protected Object			AntiBodiesVial;
	protected Object			WTF69PathogenVial;



	ItemBase	m_Cure_Petridish; 
	ItemBase	m_brain_Mung; 
	ItemBase	m_BloodBagFull; 
    
	void cure_microscope()
    {   
		m_Cure_Petridish = NULL;
		m_brain_Mung = NULL;
		m_BloodBagFull = NULL;
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
		RegisterNetSyncVariableBool("m_IsPlaceSound");		
    }

	//COUNTS THE INGRED FOR BOTH CONTRUSTION AND DESTRUCTION
	int getQuantity( string slotName )
	{
		int slot_id;
        ItemBase ingredient;
		slot_id = InventorySlots.GetSlotIdFromString(slotName);
		ingredient = ItemBase.Cast( GetInventory().FindAttachment(slot_id) ); 
		return ingredient.GetQuantity();
	}
	
	void removeQuanity( int amount, string slotName )
	{
		int slot_id;
        ItemBase ingredient;
		slot_id = InventorySlots.GetSlotIdFromString(slotName);
		ingredient = ItemBase.Cast( GetInventory().FindAttachment(slot_id) ); 
		ingredient.SetQuantity(ingredient.GetQuantity() - amount);
	}
	


	override void EEItemAttached ( EntityAI item, string slot_name )
	{
		super.EEItemAttached ( item, slot_name );
		
		ItemBase item_IB = ItemBase.Cast( item );
		
		if ( item_IB.IsKindOf("Cure_Petridish") )
		{

			m_Cure_Petridish = item_IB;
			
			if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() )
			{
				SEffectManager.PlaySound(MICROSCOPE_ATTACH_SOUND, GetPosition() );
			}
		}
		if ( item_IB.IsKindOf("brain_Mung_virus") )
		{

			m_brain_Mung = item_IB;
			
			if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() )
			{
				SEffectManager.PlaySound(MICROSCOPE_ATTACH_SOUND, GetPosition() );
			}
		}
		if ( item_IB.IsKindOf("BloodBagFull") )
		{

			m_BloodBagFull = item_IB;
			
			if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() )
			{
				SEffectManager.PlaySound(MICROSCOPE_ATTACH_SOUND, GetPosition() );
			}
		}
	}
	
	override void EEItemDetached ( EntityAI item, string slot_name )
	{
		super.EEItemDetached ( item, slot_name );
		
		ItemBase item_IB = ItemBase.Cast( item );
		
		if ( item_IB.IsKindOf("Cure_Petridish") )
		{
			m_Cure_Petridish = NULL;
			if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() )
			{
				SEffectManager.PlaySound(MICROSCOPE_DETACH_SOUND, GetPosition() );
			}
		}
		if ( item_IB.IsKindOf("brain_Mung_virus") )
		{
			m_brain_Mung = NULL;
			if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() )
			{
				SEffectManager.PlaySound(MICROSCOPE_DETACH_SOUND, GetPosition() );
			}
		}
		if ( item_IB.IsKindOf("BloodBagFull") )
		{
			m_BloodBagFull = NULL;

			if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() )
			{
				SEffectManager.PlaySound(MICROSCOPE_DETACH_SOUND, GetPosition() );
			}
		}
	}	
	override bool CanPutInCargo( EntityAI parent )
    {
        if( !super.CanPutInCargo(parent) ) {return false;}        
        if ( GetNumberOfItems() == 0)
        {
            return true;
        }
        return true;
    }
    override bool CanPutIntoHands(EntityAI parent)
    {
        if( !super.CanPutIntoHands( parent ) )
        {
            return true;
        }
        if ( GetNumberOfItems() == 0 )
        {
            return true;
        }
        return true;
    }
	// Checks GP_Keg
	bool HasCure_Petridish()
	{
		if ( m_Cure_Petridish )
		{
			if ( !m_Cure_Petridish.IsRuined() )
			{
				return true;
			}
		}
		
		return false;
	}	
	// Checks S_Brass_Cases
	bool Hasbrain_Mung()
	{
		if ( m_brain_Mung )
		{
			if ( !m_brain_Mung.IsRuined() )
			{
				return true;
			}
		}
		
		return false;
	}	
	// Checks Copper_Jackets_A
	bool HasBloodBagFull()
	{
		if ( m_BloodBagFull )
		{
			if ( !m_BloodBagFull.IsRuined() )
			{
				return true;
			}
		}
		
		return false;
	}	
	
    void DeleteRPRZBloodBagFull()
    {
        BloodBagFull RPRZBloodBagFull = BloodBagFull.Cast( FindAttachmentBySlotName( ATTACHMENT_SLOT_BLOODBAG ) );
        RPRZBloodBagFull.RPRZ_BloodBagFullDestroy();
    }

    void DeleteRPRZbrain_Mung()
    {
        brain_Mung_virus RPRZbrain_Mung = brain_Mung_virus.Cast( FindAttachmentBySlotName( ATTACHMENT_SLOT_BRAIN ) );
        RPRZbrain_Mung.RPRZ_brain_MungDestroy();
    }
    void DeleteRPRZCure_Petridish()
    {
        Cure_Petridish RPRZCure_Petridish = Cure_Petridish.Cast( FindAttachmentBySlotName( ATTACHMENT_SLOT_PETRIDISH ) );
        RPRZCure_Petridish.RPRZ_Cure_PetridishDestroy();
    }
	void AnalyseVirus()
	{
			AntiBodiesVial = GetGame().CreateObject("AntiBodiesVial", this.GetPosition() +"0 0 0.2", false );
			WTF69PathogenVial = GetGame().CreateObject("WTF69PathogenVial", this.GetPosition() +"0 0 0.3", false );
			DeleteRPRZBloodBagFull();
			DeleteRPRZbrain_Mung();
			DeleteRPRZCure_Petridish();
	}

	

}

