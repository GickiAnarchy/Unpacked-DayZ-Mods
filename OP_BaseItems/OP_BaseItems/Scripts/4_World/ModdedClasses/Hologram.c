modded class Hologram
{
    protected bool              m_IsCollidingDirtmound;
    override string ProjectionBasedOnParent()
    {
        ItemBase item_in_hands = ItemBase.Cast( m_Player.GetHumanInventory().GetEntityInHands() );

        if ( item_in_hands && item_in_hands.CanMakeDirtmound() )
        {
            return "Dirtmound";
        }
        return super.ProjectionBasedOnParent();
    }
    
    override void EvaluateCollision(ItemBase action_item = null)
    {
        ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
        
        if (item_in_hands.IsInherited(Locker))
        {
            SetIsColliding(false);
            return;
        }

        if (item_in_hands.IsInherited(WoodStorage))
        {
            SetIsColliding(false);
            return;
        }

        if (item_in_hands.IsInherited(OP_Worktable))
        {
            SetIsColliding(false);
            return;
        }

        if (item_in_hands.IsInherited(Waterbarrelcomplete))
        {
            SetIsColliding(false);
            return;
        }

        if (item_in_hands.IsInherited(GardenboxEmpty))
        {
            SetIsColliding(false);
            return;
        }
        if (item_in_hands.IsInherited(OP_ImpTent))
        {
            SetIsColliding(false);
            return;
        }
        if (item_in_hands.IsInherited(OP_BannerMount))
        {
            SetIsColliding(false);
            return;
        }
        if (item_in_hands.IsInherited(OP_SleepingBagBlue))
        {
            SetIsColliding(false);
            return;
        }
        if (item_in_hands.IsInherited(OP_SleepingBagGrey))
        {
            SetIsColliding(false);
            return;
        }
        if (item_in_hands.IsInherited(OP_SleepingBagCamo))
        {
            SetIsColliding(false);
            return;
        }
        if (item_in_hands.IsInherited(OP_Charc_BBQ))
        {
            SetIsColliding(false);
            return;
        }
        if (item_in_hands.IsInherited( OP_ShedKit ) )
        {
            SetIsColliding(false);
            return;
        }/*
        if (item_in_hands.IsInherited( OP_RaincatcherKit ) )
        {
            SetIsColliding(false);
            return;
        }*/
        super.EvaluateCollision();
    }
}
