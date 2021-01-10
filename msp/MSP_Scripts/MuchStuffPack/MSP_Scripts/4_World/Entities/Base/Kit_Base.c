class Msp_Item : ItemBase
{
	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionFoldItem);
	}
};

class Msp_Kit : ItemBase
{
	void Msp_Kit()
	{
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
	}

	#ifdef DAYZ_1_09	
	override void OnPlacementComplete(Man player)
	{
		super.OnPlacementComplete(player);
		PlayerBase player_base = PlayerBase.Cast(player);
		vector position = player_base.GetLocalProjectionPosition();
		vector orientation = player_base.GetLocalProjectionOrientation();
	#else
	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);
	#endif

		if (GetGame().IsServer())
		{
			EntityAI kitItem = EntityAI.Cast(GetGame().CreateObjectEx(Get_ItemName(), position, ECE_PLACE_ON_SURFACE));
			kitItem.SetPosition(position);
			kitItem.SetOrientation(orientation);
		}

		SetIsPlaceSound(true);
	}

	override bool IsDeployable()
	{
		return true;
	}

	override string GetPlaceSoundset()
	{
		return "putDown_FenceKit_SoundSet";
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
};