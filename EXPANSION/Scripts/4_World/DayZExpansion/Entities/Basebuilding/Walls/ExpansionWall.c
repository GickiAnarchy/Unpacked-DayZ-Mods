/**
 * ExpansionWallBase.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionWallBase: ExpansionBaseBuilding
{
	private bool m_IsOpened;

	private string m_CurrentBuild;

	private bool m_HasWindow;
	private bool m_HasDoor;
	private bool m_HasGate;

	void ExpansionWallBase()
	{
		RegisterNetSyncVariableBool( "m_HasWindow" );
		RegisterNetSyncVariableBool( "m_HasDoor" );
		RegisterNetSyncVariableBool( "m_HasGate" );

		m_CurrentBuild = "wood";
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction( ExpansionActionEnterCodeLock );
		AddAction( ExpansionActionChangeCodeLock );
	}

	override string GetConstructionKitType()
	{
		return "ExpansionWallKit";
	}

	override bool CanBeDamaged()
	{
		if (GetExpansionSettings().GetRaid().BaseBuildingRaidMode == 1)
		{
			return m_HasDoor || m_HasGate;
		} else if (GetExpansionSettings().GetRaid().BaseBuildingRaidMode == 2)
		{
			return m_HasDoor || m_HasGate || m_HasWindow;
		}
		
		return super.CanBeDamaged();
	}

	override void OnStoreSave( ParamsWriteContext ctx )
	{
		#ifdef CF_MODULE_MODSTORAGE
		if ( GetGame().SaveVersion() >= 116 )
		{
			super.OnStoreSave( ctx );
			return;
		}
		#endif

		super.OnStoreSave( ctx );
		
		ctx.Write( m_HasWindow );
		ctx.Write( m_HasDoor );
		ctx.Write( m_HasGate );
	}

	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		#ifdef CF_MODULE_MODSTORAGE
		if ( version >= 116 )
			return super.OnStoreLoad( ctx, version );
		#endif

		if ( !super.OnStoreLoad( ctx, version ) )
			return false;

		if ( Expansion_Assert_False( ctx.Read( m_HasWindow ), "[" + this + "] Failed reading m_HasWindow" ) )
			return false;
		if ( Expansion_Assert_False( ctx.Read( m_HasDoor ), "[" + this + "] Failed reading m_HasDoor" ) )
			return false;
		if ( Expansion_Assert_False( ctx.Read( m_HasGate ), "[" + this + "] Failed reading m_HasGate" ) )
			return false;
		
		return true;
	}

	#ifdef CF_MODULE_MODSTORAGE
	override void CF_OnStoreSave( CF_ModStorage storage, string modName )
	{
		super.CF_OnStoreSave( storage, modName );

		if ( modName != "DZ_Expansion" )
			return;

		storage.Write( m_HasWindow );
		storage.Write( m_HasDoor );
		storage.Write( m_HasGate );
	}
	
	override bool CF_OnStoreLoad( CF_ModStorage storage, string modName )
	{
		if ( !super.CF_OnStoreLoad( storage, modName ) )
			return false;

		if ( modName != "DZ_Expansion" )
			return true;

		if ( Expansion_Assert_False( storage.Read( m_HasWindow ), "[" + this + "] Failed reading m_HasWindow" ) )
			return false;
		if ( Expansion_Assert_False( storage.Read( m_HasDoor ), "[" + this + "] Failed reading m_HasDoor" ) )
			return false;
		if ( Expansion_Assert_False( storage.Read( m_HasGate ), "[" + this + "] Failed reading m_HasGate" ) )
			return false;

		return true;
	}
	#endif

	override bool HasBase()
	{
		return (GetConstruction().IsPartConstructed( "wood_base" ) || GetConstruction().IsPartConstructed( "wood_base_third" ) || GetConstruction().IsPartConstructed( "wood_base_half" ));
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		UpdateVisuals();
	}
	
	override void AfterStoreLoad()
	{	
		super.AfterStoreLoad();
		
		UpdateVisuals();	
	}

	override bool CanReleaseAttachment( EntityAI attachment )
	{
		if ( attachment.IsInherited( ExpansionCodeLock ) )
		{
			ExpansionCodeLock codelock = ExpansionCodeLock.Cast( attachment );
			if ( !codelock.IsLocked() )
			{
				return true;
			}
		}

		return super.CanReleaseAttachment( attachment );
	}

	override bool ExpansionHasCodeLock( string selection )
	{
		if ( selection == "codelock_door" || GetExpansionSettings().GetBaseBuilding() && GetExpansionSettings().GetBaseBuilding().CodelockActionsAnywhere )
		{
			if ( m_HasDoor && FindAttachmentBySlotName( "Att_ExpansionCodeLock_1" ) )
			{
				return true;
			}
		}

		if ( selection == "codelock_gate" || GetExpansionSettings().GetBaseBuilding() && GetExpansionSettings().GetBaseBuilding().CodelockActionsAnywhere )
		{
			if ( m_HasGate && FindAttachmentBySlotName( "Att_ExpansionCodeLock_2" ) )
			{
				return true;
			}
		}

		return false;
	}

	override ExpansionCodeLock ExpansionGetCodeLock()
	{
		if (m_HasDoor)
			return ExpansionCodeLock.Cast(FindAttachmentBySlotName("Att_ExpansionCodeLock_1"));

		if (m_HasGate)
			return ExpansionCodeLock.Cast(FindAttachmentBySlotName("Att_ExpansionCodeLock_2"));

		return null;
	}

	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}

	override bool ExpansionIsOpenable()
	{
		return m_HasWindow || m_HasDoor || m_HasGate;
	}

	bool ExpansionHasGate()
	{
		return m_HasGate;
	}

	bool ExpansionHasDoor()
	{
		return m_HasDoor;
	}
	
	override void OnPartBuiltServer( notnull Man player, string part_name, int action_id )
	{
		m_HasWindow = false;
		m_HasDoor = false;
		m_HasGate = false;

		if ( part_name == m_CurrentBuild + "_windowfinished" )
		{
			m_HasWindow = true;
		}

		if ( part_name == m_CurrentBuild + "_doorfinished" )
		{
			m_HasDoor = true;
		}

		if ( part_name == m_CurrentBuild + "_gatefinished" )
		{
			m_HasGate = true;
		}

		SetAllowDamage(CanBeDamaged());
		super.OnPartBuiltServer(player, part_name, action_id );

		UpdateVisuals();
	}

	override void OnPartDismantledServer( notnull Man player, string part_name, int action_id )
	{
		m_HasWindow = false;
		m_HasDoor = false;
		m_HasGate = false;

		SetAllowDamage(CanBeDamaged());
		super.OnPartDismantledServer( player, part_name, action_id );

		UpdateVisuals();
	}

	override void OnPartDestroyedServer( Man player, string part_name, int action_id, bool destroyed_by_connected_part = false )
	{
		m_HasWindow = false;
		m_HasDoor = false;
		m_HasGate = false;

		SetAllowDamage(CanBeDamaged());
		super.OnPartDestroyedServer( player, part_name, action_id, destroyed_by_connected_part );

		UpdateVisuals();
	}

	override void UpdateVisuals()
	{
		if ( m_HasWindow )
		{
			ShowSelectionProxy( m_CurrentBuild + "_window_ll" );
			ShowSelectionProxy( m_CurrentBuild + "_window_lr" );
			ShowSelectionProxy( m_CurrentBuild + "_window_rl" );
			ShowSelectionProxy( m_CurrentBuild + "_window_rr" );
		} else
		{
			HideSelectionProxy( m_CurrentBuild + "_window_ll" );
			HideSelectionProxy( m_CurrentBuild + "_window_lr" );
			HideSelectionProxy( m_CurrentBuild + "_window_rl" );
			HideSelectionProxy( m_CurrentBuild + "_window_rr" );
		}

		if ( m_HasDoor )
		{
			ShowSelectionProxy( m_CurrentBuild + "_door" );
		} else
		{
			HideSelectionProxy( m_CurrentBuild + "_door" );
		}

		if ( m_HasGate )
		{
			ShowSelectionProxy( m_CurrentBuild + "_gate_l" );
			ShowSelectionProxy( m_CurrentBuild + "_gate_r" );
		} else
		{
			HideSelectionProxy( m_CurrentBuild + "_gate_l" );
			HideSelectionProxy( m_CurrentBuild + "_gate_r" );
		}

		super.UpdateVisuals();
	}

	private bool ExpansionCanAcceptCodeLock( string slot_name )
	{
		if ( slot_name == "Att_ExpansionCodeLock_1" )
		{
			if ( !m_HasDoor )
			{
				return false;
			}
		}
		
		if ( slot_name == "Att_ExpansionCodeLock_2" )
		{
			if ( !m_HasGate )
			{
				return false;
			}
		}

		return true;
	}
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if ( item && (slot_name == "Att_ExpansionCodeLock_1" || slot_name == "Att_ExpansionCodeLock_2") && HasCode() )
		{
			//Reset code on the building
			SetCode("");
		}
	}
	
	override bool CanDisplayAttachmentCategory( string category_name )
	{
		if ( !super.CanDisplayAttachmentCategory( category_name ) )
		{
			return false;
		}

		if ( category_name == "Attachments" )
		{
			if ( !( m_HasGate || m_HasDoor ) )
			{
				return false;
			}
		}

		return true;
	}

	override bool CanDisplayAttachmentSlot( string slot_name )
	{
		if ( !super.CanDisplayAttachmentSlot( slot_name ) )
		{
			return false;
		}

		if ( !ExpansionCanAcceptCodeLock( slot_name ) )
		{
			return false;
		}
		
		return true;
	}

	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
	{
		if ( !super.CanReceiveAttachment( attachment, slotId ) )
		{
			return false;
		}

		string slot_name = InventorySlots.GetSlotName( slotId );

		if ( !ExpansionCanAcceptCodeLock( slot_name ) )
		{
			return false;
		}
		
		return true;
	}
	
	override bool ExpansionCanOpen( PlayerBase player, string selection )
	{
		if ( !ExpansionIsOpenable() )
			return false;

		if ( m_HasWindow && !IsFacingPlayer( player, selection ) && ( !IsMissionClient() || !IsFacingCamera( selection ) ) )
		{
			if ( selection == (m_CurrentBuild + "_window_ll") && GetAnimationPhase( m_CurrentBuild + "_window_ll_rotate" ) < 0.5 )
				return true;
			if ( selection == (m_CurrentBuild + "_window_lr") && GetAnimationPhase( m_CurrentBuild + "_window_lr_rotate" ) < 0.5 )
				return true;
			if ( selection == (m_CurrentBuild + "_window_rl") && GetAnimationPhase( m_CurrentBuild + "_window_rl_rotate" ) < 0.5 )
				return true;
			if ( selection == (m_CurrentBuild + "_window_rr") && GetAnimationPhase( m_CurrentBuild + "_window_rr_rotate" ) < 0.5 )
				return true;
		}

		if ( m_HasDoor && !IsLocked() )
		{
			if ( selection == (m_CurrentBuild + "_door") && GetAnimationPhase( m_CurrentBuild + "_door_rotate" ) < 0.5 )
				return true;
		}

		if ( m_HasGate && !IsLocked() )
		{
			if ( selection == (m_CurrentBuild + "_gate_l") && GetAnimationPhase( m_CurrentBuild +"_gate_l_rotate" ) < 0.5 )
				return true;
			if ( selection == (m_CurrentBuild + "_gate_r") && GetAnimationPhase( m_CurrentBuild + "_gate_r_rotate" ) < 0.5 )
				return true;
		}

		return false;
	}
	
	override bool CanClose( string selection )
	{
		if ( !ExpansionIsOpenable() )
			return false;

		if ( m_HasWindow )
		{
			if ( selection == (m_CurrentBuild + "_window_ll") && GetAnimationPhase( m_CurrentBuild + "_window_ll_rotate" ) > 0.5 )
				return true;
			if ( selection == (m_CurrentBuild + "_window_lr") && GetAnimationPhase( m_CurrentBuild + "_window_lr_rotate" ) > 0.5 )
				return true;
			if ( selection == (m_CurrentBuild + "_window_rl") && GetAnimationPhase( m_CurrentBuild + "_window_rl_rotate" ) > 0.5 )
				return true;
			if ( selection == (m_CurrentBuild + "_window_rr") && GetAnimationPhase( m_CurrentBuild + "_window_rr_rotate" ) > 0.5 )
				return true;
		}

		if ( m_HasDoor )
		{
			if ( selection == (m_CurrentBuild + "_door") && GetAnimationPhase( m_CurrentBuild + "_door_rotate" ) > 0.5 )
				return true;
		}

		if ( m_HasGate )
		{
			if ( selection == (m_CurrentBuild + "_gate_l") && GetAnimationPhase( m_CurrentBuild +"_gate_l_rotate" ) > 0.5 )
				return true;
			if ( selection == (m_CurrentBuild + "_gate_r") && GetAnimationPhase( m_CurrentBuild + "_gate_r_rotate" ) > 0.5 )
				return true;
		}

		return false;
	}

	override bool IsOpened()
	{
		return m_IsOpened;
	}
	
	override void Open( string selection ) 
	{	
		if ( IsMissionHost() && m_HasWindow )
		{
			if (selection == (m_CurrentBuild + "_window_ll"))
				SetAnimationPhase( m_CurrentBuild + "_window_ll_rotate", 1 );
			if (selection == (m_CurrentBuild + "_window_lr"))
				SetAnimationPhase( m_CurrentBuild + "_window_lr_rotate", 1 );	
			if (selection == (m_CurrentBuild + "_window_rl"))
				SetAnimationPhase( m_CurrentBuild + "_window_rl_rotate", 1 );	
			if (selection == (m_CurrentBuild + "_window_rr"))
				SetAnimationPhase( m_CurrentBuild + "_window_rr_rotate", 1 );

			m_IsOpened = true;
		}

		if ( IsMissionHost() && m_HasDoor )
		{
			if (selection == (m_CurrentBuild + "_door"))
				SetAnimationPhase( m_CurrentBuild + "_door_rotate", 1 );

			m_IsOpened = true;
		}

		if ( IsMissionHost() && m_HasGate )
		{
			if (selection == (m_CurrentBuild + "_gate_l"))
				SetAnimationPhase( m_CurrentBuild + "_gate_l_rotate", 1 );
			if (selection == (m_CurrentBuild + "_gate_r"))
				SetAnimationPhase( m_CurrentBuild + "_gate_r_rotate", 1 );

			m_IsOpened = true;
		}
		
		super.Open( selection );
	}
	
	override void Close( string selection ) 
	{	
		if ( GetGame().IsServer() && m_HasWindow )
		{
			if (selection == (m_CurrentBuild + "_window_ll"))
				SetAnimationPhase( m_CurrentBuild + "_window_ll_rotate", 0 );
			if (selection == (m_CurrentBuild + "_window_lr"))
				SetAnimationPhase( m_CurrentBuild + "_window_lr_rotate", 0 );	
			if (selection == (m_CurrentBuild + "_window_rl"))
				SetAnimationPhase( m_CurrentBuild+ "_window_rl_rotate", 0 );	
			if (selection == (m_CurrentBuild + "_window_rr"))
				SetAnimationPhase( m_CurrentBuild + "_window_rr_rotate", 0 );

			m_IsOpened = false;
			m_IsOpened = m_IsOpened || GetAnimationPhase( m_CurrentBuild + "_window_ll_rotate" ) < 0.5;
			m_IsOpened = m_IsOpened || GetAnimationPhase( m_CurrentBuild + "_window_lr_rotate" ) < 0.5;
			m_IsOpened = m_IsOpened || GetAnimationPhase( m_CurrentBuild + "_window_rl_rotate" ) < 0.5;
			m_IsOpened = m_IsOpened || GetAnimationPhase( m_CurrentBuild + "_window_rr_rotate" ) < 0.5;
		}

		if ( IsMissionHost() && m_HasDoor )
		{
			if (selection == (m_CurrentBuild + "_door"))
				SetAnimationPhase( m_CurrentBuild + "_door_rotate", 0 );

			m_IsOpened = GetAnimationPhase( m_CurrentBuild + "_door_rotate" ) < 0.5;
		}

		if ( IsMissionHost() && m_HasGate )
		{
			if (selection == (m_CurrentBuild + "_gate_l"))
				SetAnimationPhase( m_CurrentBuild + "_gate_l_rotate", 0 );
			if (selection == (m_CurrentBuild + "_gate_r"))
				SetAnimationPhase( m_CurrentBuild + "_gate_r_rotate", 0 );

			m_IsOpened = GetAnimationPhase( m_CurrentBuild + "_gate_l_rotate" ) < 0.5 && GetAnimationPhase( m_CurrentBuild + "_gate_r_rotate" ) < 0.5;
		}
		
		super.Close( selection );
	}

	override void EEKilled( Object killer )
	{
		if ( !killer.IsInherited( CarScript ) )
		{
			super.EEKilled( killer );
		
			this.Delete();
		}
	}
}