modded class ActionCollectSampleTarget
{
	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		#ifdef EXPANSIONEXPRINT
		EXPrint("ActionCollectSampleTarget::ActionCondition Start");
		#endif
		if (player)
		{
			if (player.IsInSafeZone())
			{
				#ifdef EXPANSIONEXPRINT
				EXPrint("ActionCollectSampleTarget::ActionCondition End");
				#endif

				return false;
			}
		}

		#ifdef EXPANSIONEXPRINT
		EXPrint("ActionCollectSampleTarget::ActionCondition End");
		#endif

		return super.ActionCondition(player, target, item);
	}
};