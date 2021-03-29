class DP_CocaBag extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionConsumeDrugs);
	};
	
	void MakeHigh(PlayerBase player)
	{
		if( player.GetModifiersManager().IsModifierActive(eModifiers.MDF_MORPHINE ) )//effectively resets the timer
		{
			player.GetModifiersManager().DeactivateModifier( eModifiers.MDF_MORPHINE, false );
		}
		player.GetModifiersManager().ActivateModifier( eModifiers.MDF_MORPHINE );
		
	}
}