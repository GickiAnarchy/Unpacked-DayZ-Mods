modded class ActionConstructor 
{

    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);
        actions.Insert(ActionPackTentOP);  
    //    actions.Insert(ActionToggleTentOpenOP);
        
        actions.Insert(ActionDigDirtmound);
        actions.Insert(ActionRemoveDirtmound);

        actions.Insert(ActionNextOPLockDial);
        actions.Insert(ActionDialOPLock);
        actions.Insert(ActionDialOPLockOnLocker);
        actions.Insert(ActionNextOPLockDialOnLocker);
        actions.Insert(ActionDestroyOPLockOnLocker);
        actions.Insert(ActionCloseLocker);
        actions.Insert(ActionOpenLocker);
        actions.Insert(ActionDestroyGbaseOnLocker);

        actions.Insert(ActionDeployGardenpot);
        actions.Insert(ActionEmptyGardenpot);

        actions.Insert(ActionDaetatchWaterbarrel);  
        actions.Insert(ActionDrinkWaterbarrelcomplete);
        actions.Insert(ActionTogglePlaceWB); 

        actions.Insert(ActionOpenCharBBQ);
        actions.Insert(ActionCloseCharBBQ);
        actions.Insert(ActionExtinguishBBQ);
        actions.Insert(ActionPackBanner); 

        actions.Insert(ActionTurnOnLights);  
        actions.Insert(ActionTurnOffLights);

        actions.Insert(ActionDeployOPBI);
 //       actions.Insert(ActionDismantleRainCatcher);

        actions.Insert(ActionOpenShed);  
        actions.Insert(ActionCloseShed);
        actions.Insert(ActionDialOPLockOnShed);  
        actions.Insert(ActionNextOPLockDialOnShed);

    }
}
  /*     
//        actions.Insert(ActionRemoveDirtmound);
//        actions.Insert(ActionEmptyGardenbox);
 //       actions.Insert(ActionAttachToLocker); 
        actions.Insert(ActionDrinkWaterbarrelcomplete);
        actions.Insert(ActionAttachToLocker);
        actions.Insert(ActionEmptyGardenpot);
        actions.Insert(ActionNextDialOnLocker);
        actions.Insert(ActionPackTentNoDoorOP);*/


