/**
 * ExpansionRespawnHandlerModule.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

enum ExpansionRespawnHandlerModuleRPC
{
	INVALID = 20600,
	ShowSpawnMenu,
	SelectSpawn,
	CloseSpawnMenu,
	COUNT
}

class ExpansionRespawnHandlerModule: JMModuleBase
{
	// ------------------------------------------------------------
	// ExpansionRespawnHandlerModule IsServer
	// ------------------------------------------------------------	
	override bool IsServer()
	{
		return true;
	}
	
	// ------------------------------------------------------------
	// ExpansionRespawnHandlerModule IsClient
	// ------------------------------------------------------------
	override bool IsClient()
	{
		return true;
	}
	
	// ------------------------------------------------------------
	// ExpansionRespawnHandlerModule GetRPCMin
	// ------------------------------------------------------------	
	override int GetRPCMin()
	{
		return ExpansionRespawnHandlerModuleRPC.INVALID;
	}
	
	// ------------------------------------------------------------
	// ExpansionRespawnHandlerModule GetRPCMax
	// ------------------------------------------------------------
	override int GetRPCMax()
	{
		return ExpansionRespawnHandlerModuleRPC.COUNT;
	}
	
	// ------------------------------------------------------------
	// ExpansionRespawnHandlerModule OnRPC
	// ------------------------------------------------------------
	override void OnRPC( PlayerIdentity sender, Object target, int rpc_type, ref ParamsReadContext ctx )
	{
		switch ( rpc_type )
		{
		case ExpansionRespawnHandlerModuleRPC.ShowSpawnMenu:
			RPC_ShowSpawnMenu( sender, ctx );
			break;
		case ExpansionRespawnHandlerModuleRPC.SelectSpawn:
			RPC_SelectSpawn( sender, ctx );
			break;
		case ExpansionRespawnHandlerModuleRPC.CloseSpawnMenu:
			RPC_CloseSpawnMenu( sender, ctx );
			break;
		}
	}
	
	// ------------------------------------------------------------
	// ExpansionRespawnHandlerModule ShowSpawnSelection
	// Called on server
	// ------------------------------------------------------------
	void ShowSpawnSelection(PlayerIdentity sender)
	{
		Print("ExpansionRespawnHandlerModule::ShowSpawnSelection - Start");
		
		if ( !IsMissionHost() )
			return;
		
		ScriptRPC rpc = new ScriptRPC();
		rpc.Send( null, ExpansionRespawnHandlerModuleRPC.ShowSpawnMenu, true, sender );
		
		Print("ExpansionRespawnHandlerModule::ShowSpawnSelection - End");
	}
	
	// ------------------------------------------------------------
	// ExpansionRespawnHandlerModule RPC_ShowSpawnMenu
	// Called on client
	// ------------------------------------------------------------
	private void RPC_ShowSpawnMenu(PlayerIdentity sender, ref ParamsReadContext ctx)
	{	
		Print("ExpansionRespawnHandlerModule::RPC_ShowSpawnMenu - Start");
		
		if ( !IsMissionClient() )
			return;
		
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(Exec_ShowSpawnMenu, 1000, false);
		
		Print("ExpansionRespawnHandlerModule::RPC_ShowSpawnMenu - End");
	}
	
	// ------------------------------------------------------------
	// ExpansionRespawnHandlerModule Exec_ShowSpawnMenu
	// Called on client
	// ------------------------------------------------------------
	private void Exec_ShowSpawnMenu()
	{
		Print("ExpansionRespawnHandlerModule::Exec_ShowSpawnMenu - Start");
		
		if ( !IsMissionClient() )
			return;
		
		GetGame().GetUIManager().EnterScriptedMenu( MENU_EXPANSION_SPAWN_SELECTION_MENU, NULL );
		
		/*ExpansionSpawnSelectionMenu spawnSelectionMenu = ExpansionSpawnSelectionMenu.Cast( GetGame().GetUIManager().GetMenu() );
		if ( spawnSelectionMenu )
		{
			//spawnSelectionMenu.FillList();
			//GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove( Exec_ShowSpawnMenu );
		}*/
		
		Print("ExpansionRespawnHandlerModule::Exec_ShowSpawnMenu - End");
	}
	
	// ------------------------------------------------------------
	// ExpansionRespawnHandlerModule SelectSpawn
	// Called from client
	// ------------------------------------------------------------
	void SelectSpawn(vector spawnPoint)
	{
		Print("ExpansionRespawnHandlerModule::SelectSpawn - Start");
		
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write( spawnPoint );
		rpc.Send( null, ExpansionRespawnHandlerModuleRPC.SelectSpawn, true );
		
		Print("ExpansionRespawnHandlerModule::SelectSpawn - End");
	}
	
	// ------------------------------------------------------------
	// ExpansionRespawnHandlerModule RPC_SelectSpawn
	// Called on server
	// ------------------------------------------------------------
	private void RPC_SelectSpawn(PlayerIdentity sender, ref ParamsReadContext ctx)
	{	
		Print("ExpansionRespawnHandlerModule::RPC_SelectSpawn - Start");
		
		if ( !IsMissionHost() )
			return;
		
		if ( !sender )
			return;
		
		vector spawnPoint;
		if ( !ctx.Read( spawnPoint ) )
			return;
		
		Exec_SelectSpawn(sender, spawnPoint);
		
		Print("ExpansionRespawnHandlerModule::RPC_SelectSpawn - End");
	}
	
	// ------------------------------------------------------------
	// ExpansionRespawnHandlerModule Exec_SelectSpawn
	// Called on server
	// ------------------------------------------------------------
	private void Exec_SelectSpawn(PlayerIdentity sender, vector spawnPoint)
	{	
		Print("ExpansionRespawnHandlerModule::Exec_SelectSpawn - Start");
		
		PlayerBase player = GetPlayerObjectByIdentity( sender );
		if ( player )
		{
			player.SetPosition( spawnPoint );
			
			CloseSpawnMenu( sender );
		}
		
		Print("ExpansionRespawnHandlerModule::Exec_SelectSpawn - End");
	}
	
	// ------------------------------------------------------------
	// ExpansionRespawnHandlerModule CloseSpawnMenu
	// Called on server
	// ------------------------------------------------------------
	void CloseSpawnMenu(PlayerIdentity sender)
	{
		Print("ExpansionRespawnHandlerModule::CloseSpawnMenu - Start");
		
		if ( !IsMissionHost() )
			return;
		
		ScriptRPC rpc = new ScriptRPC();
		rpc.Send( null, ExpansionRespawnHandlerModuleRPC.CloseSpawnMenu, true, sender );
		
		Print("ExpansionRespawnHandlerModule::CloseSpawnMenu - End");
	}
	
	// ------------------------------------------------------------
	// ExpansionRespawnHandlerModule RPC_CloseSpawnMenu
	// Called on client
	// ------------------------------------------------------------
	private void RPC_CloseSpawnMenu(PlayerIdentity sender, ref ParamsReadContext ctx)
	{	
		Print("ExpansionRespawnHandlerModule::RPC_CloseSpawnMenu - Start");
		
		if ( !IsMissionClient() )
			return;
		
		Exec_CloseSpawnMenu();
		
		Print("ExpansionRespawnHandlerModule::RPC_CloseSpawnMenu - End");
	}
	
	// ------------------------------------------------------------
	// ExpansionRespawnHandlerModule Exec_CloseSpawnMenu
	// Called on client
	// ------------------------------------------------------------
	private void Exec_CloseSpawnMenu()
	{
		if ( !IsMissionClient() )
			return;
		
		ExpansionSpawnSelectionMenu spawnSelectionMenu = ExpansionSpawnSelectionMenu.Cast( GetGame().GetUIManager().GetMenu() );
		if ( spawnSelectionMenu )
		{
			GetGame().GetUIManager().CloseMenu( MENU_EXPANSION_SPAWN_SELECTION_MENU );
		}
	}
	
	// ------------------------------------------------------------
	// ExpansionRespawnHandlerModule SelectRandomSpawn
	// Called on client
	// ------------------------------------------------------------
	void SelectRandomSpawn()
	{
		if ( !IsMissionClient() )
			return;
		
		ref ExpansionSpawnLocation random_location = GetExpansionSettings().GetSpawn().SpawnLocations.GetRandomElement();
		
		SelectSpawn( random_location.Positions.GetRandomElement() );
	}
	
	// ------------------------------------------------------------
	// ExpansionRespawnHandlerModule SetExpansionStartingGear
	// ------------------------------------------------------------
	void SetExpansionStartingGear(PlayerBase player)
	{
		if ( !IsMissionHost() )
			return;
		
		int i;
		EntityAI gear_item;
		EntityAI itemTop;
		EntityAI itemPants;
		EntityAI itemBag;
		EntityAI itemVest;
		
		if ( GetExpansionSettings().GetSpawn() )
		{
			ExpansionStartingGear gear;
			if ( Class.CastTo(gear, GetExpansionSettings().GetSpawn().StartingGear) )
			{
				//! Add items to top/shirt/jacked
				if ( gear.UseUpperGear )
				{
					itemTop = player.FindAttachmentBySlotName("Body");					
					if ( itemTop )
					{
						for ( i = 0; i < gear.UpperGear.Count(); i++ )
						{
							itemTop.GetInventory().CreateInInventory( gear.UpperGear[i] );
						}
					}
				}
				
				//! Add items to pants
				if ( gear.UsePantsGear )
				{
					itemPants = player.FindAttachmentBySlotName("Legs");
					if ( itemPants )
					{					
						for ( i = 0; i < gear.PantsGear.Count(); i++ )
						{
							itemPants.GetInventory().CreateInInventory( gear.PantsGear[i] );
						}
					}
				}
				
				//! Add items to backpack
				if ( gear.UseBackpackGear )
				{
					itemBag = player.FindAttachmentBySlotName("Back");
					if ( itemBag )
					{	
						for ( i = 0; i < gear.BackpackGear.Count(); i++ )
						{
							gear_item = itemBag.GetInventory().CreateInInventory( gear.BackpackGear[i] );
						}
					}
				}
				
				//! Add items to vest
				if ( gear.UseVestGear )
				{
					itemVest = player.FindAttachmentBySlotName("Vest");
					if ( itemVest )
					{					
						for ( i = 0; i < gear.VestGear.Count(); i++ )
						{
							gear_item = itemVest.GetInventory().CreateInInventory( gear.VestGear[i] );
						}
					}
				}
				
				//! Add primary weapon and its attachments
				if ( gear.UsePrimaryWeapon )
				{
					EntityAI item_primaryWeapon = player.GetInventory().CreateAttachmentEx( gear.PrimaryWeapon, InventorySlots.SHOULDER );			
					if ( item_primaryWeapon && item_primaryWeapon.IsWeapon() )
					{
						for ( i = 0; i < gear.PrimaryWeaponAttachments.Count(); i++ )
						{
							gear_item = item_primaryWeapon.GetInventory().CreateAttachment( gear.PrimaryWeaponAttachments[i] );
							if (!gear_item)
							{
								Error2( "ExpansionRespawnHandlerModule::SetExpansionStartingGear", "Could not create attachment item " + gear.PrimaryWeaponAttachments[i] + " for weapon " + gear.PrimaryWeapon + ". Please make sure you spawn the attachments in the correct order and the item is a valid attachment for the weapon " + gear.PrimaryWeapon + "! For further information please visit the wiki page for the spawn settings: \nhttps:\/\/github.com/salutesh/DayZ-Expansion-Scripts/wiki/%5BServer-Hosting%5D-SpawnSettings\n");
								continue;
							}
						}
					}
				}
				
				//! Add secondary weapon and its attachments
				if ( gear.UseSecondaryWeapon )
				{
					EntityAI item_secondaryWeapon = player.GetInventory().CreateAttachmentEx( gear.SecondaryWeapon, InventorySlots.MELEE );
					if ( item_secondaryWeapon && item_secondaryWeapon.IsWeapon() )
					{
						for ( i = 0; i < gear.SecondaryWeaponAttachments.Count(); i++ )
						{
							gear_item = item_secondaryWeapon.GetInventory().CreateAttachment( gear.SecondaryWeaponAttachments[i] );
							if (!gear_item)
							{
								Error2( "ExpansionRespawnHandlerModule::SetExpansionStartingGear", "Could not create attachment item " + gear.SecondaryWeaponAttachments[i] + " for weapon " + gear.SecondaryWeapon + ". Please make sure you spawn the attachments in the correct order and the item is a valid attachment for the weapon " + gear.SecondaryWeapon + "! For further information please visit the wiki page for the spawn settings: \nhttps:\/\/github.com/salutesh/DayZ-Expansion-Scripts/wiki/%5BServer-Hosting%5D-SpawnSettings\n");
								continue;
							}
						}
					}
				}
				
				array< EntityAI > items = new array< EntityAI >;
				player.GetInventory().EnumerateInventory( InventoryTraversalType.PREORDER, items );
				for ( i = 0; i < items.Count(); i++ )
				{
					if ( gear.ApplyEnergySources && items[i].HasEnergyManager() )
						items[i].GetInventory().CreateAttachment( "Battery9V" );
					
					if ( gear.SetRandomHealth )
						SetRandomHealth( items[i] );
				}
			}
		}
	}
	
	// ------------------------------------------------------------
	// ExpansionRespawnHandlerModule ExpansionEquipCharacter
	// ------------------------------------------------------------
	void ExpansionEquipCharacter(PlayerBase player)
	{
		if ( !IsMissionHost() )
			return;
		
		ref array<EntityAI> clothingArray = new array<EntityAI>;
		
		ExpansionStartingClothing startingClothing;
		if (Class.CastTo(startingClothing, GetExpansionSettings().GetSpawn().StartingClothing))
		{
			EntityAI item_head = player.GetInventory().CreateAttachmentEx(startingClothing.Headgear.GetRandomElement(), InventorySlots.HEADGEAR);
			clothingArray.Insert(item_head);
			
			EntityAI item_eyewear = player.GetInventory().CreateAttachmentEx(startingClothing.Glasses.GetRandomElement(), InventorySlots.EYEWEAR);
			clothingArray.Insert(item_eyewear);
			
			EntityAI item_mask = player.GetInventory().CreateAttachmentEx(startingClothing.Masks.GetRandomElement(), InventorySlots.MASK);
			clothingArray.Insert(item_mask);
			
			EntityAI item_body = player.GetInventory().CreateAttachmentEx(startingClothing.Tops.GetRandomElement(), InventorySlots.BODY);
			clothingArray.Insert(item_body);
			
			EntityAI item_vest = player.GetInventory().CreateAttachmentEx(startingClothing.Vests.GetRandomElement(), InventorySlots.VEST);
			clothingArray.Insert(item_vest);
			
			EntityAI item_gloves = player.GetInventory().CreateAttachmentEx(startingClothing.Gloves.GetRandomElement(), InventorySlots.GLOVES);
			clothingArray.Insert(item_gloves);
			
			EntityAI item_legs = player.GetInventory().CreateAttachmentEx(startingClothing.Pants.GetRandomElement(), InventorySlots.LEGS);
			clothingArray.Insert(item_legs);
			
			EntityAI item_hips = player.GetInventory().CreateAttachmentEx(startingClothing.Belts.GetRandomElement(), InventorySlots.HIPS);
			clothingArray.Insert(item_hips);
			
			EntityAI item_feet = player.GetInventory().CreateAttachmentEx(startingClothing.Shoes.GetRandomElement(), InventorySlots.FEET);
			clothingArray.Insert(item_feet);
			
			EntityAI item_arm = player.GetInventory().CreateAttachmentEx(startingClothing.Armbands.GetRandomElement(), InventorySlots.ARMBAND);
			clothingArray.Insert(item_arm);
			
			EntityAI item_back = player.GetInventory().CreateAttachmentEx(startingClothing.Backpacks.GetRandomElement(), InventorySlots.BACK);
			clothingArray.Insert(item_back);
			
			if (GetExpansionSettings().GetSpawn().StartingClothing.SetRandomHealth)
			{
				for (int i = 0; i < clothingArray.Count(); i++ )
				{
					SetRandomHealth(clothingArray[i]);
				}
			}
			
			SetExpansionStartingGear(player);
		}
	}
	
	// ------------------------------------------------------------
	// ExpansionRespawnHandlerModule SetRandomHealth
	// ------------------------------------------------------------
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			int rndHlt = Math.RandomInt(55,100);
			itemEnt.SetHealth("","",rndHlt);
		}
	}
}