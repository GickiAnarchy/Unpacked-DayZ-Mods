modded class ModItemRegisterCallbacks
{
    override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        pType.AddItemInHandsProfileIK("OP_SleepingBagCamo", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/tent_medium_packed.anm");
        pType.AddItemInHandsProfileIK("OP_SleepingBagBlue", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/tent_medium_packed.anm");
        pType.AddItemInHandsProfileIK("OP_SleepingBagGrey", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/tent_medium_packed.anm");
        pType.AddItemInHandsProfileIK("GardenpotEmpty", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior,      "dz/anims/anm/player/ik/two_handed/BatteryCar.anm");
        super.RegisterTwoHanded(pType, pBehavior);
    }

    override void RegisterHeavy(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        pType.AddItemInHandsProfileIK("OP_Charc_BBQ", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,   "dz/anims/anm/player/ik/heavy/55galDrum.anm"); 
        pType.AddItemInHandsProfileIK("BarrelFrame", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,    "dz/anims/anm/player/ik/heavy/55galDrum.anm");  
        pType.AddItemInHandsProfileIK("Locker", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,         "dz/anims/anm/player/ik/heavy/55galDrum.anm"); 
        pType.AddItemInHandsProfileIK("Waterbarrel", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,    "dz/anims/anm/player/ik/vehicles/hatchback/hatchback_wheel.anm");
        pType.AddItemInHandsProfileIK("GardenboxEmpty", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior, "dz/anims/anm/player/ik/heavy/wooden_crate.anm");
        pType.AddItemInHandsProfileIK("WoodStorage", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,    "dz/anims/anm/player/ik/heavy/55galDrum.anm");
        pType.AddItemInHandsProfileIK("OP_Worktable", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,   "dz/anims/anm/player/ik/heavy/55galDrum.anm");
        pType.AddItemInHandsProfileIK("OP_ImpTent", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,      "dz/anims/anm/player/ik/heavy/tent_party_packed.anm");
        pType.AddItemInHandsProfileIK("OP_BannerMount", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,  "dz/anims/anm/player/ik/heavy/tent_large.anm");    
        pType.AddItemInHandsProfileIK("Waterbarrelcomplete", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,  "dz/anims/anm/player/ik/heavy/55galDrum.anm");  
        super.RegisterHeavy(pType, pBehavior);
    }

    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        pType.AddItemInHandsProfileIK("OP_ShedKit", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/fence_kit_folded.anm");
        super.RegisterOneHanded(pType, pBehavior);
    }
}