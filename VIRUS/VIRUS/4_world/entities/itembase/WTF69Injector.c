class WTF69VirusInjector: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionInjectWTF69Target);
		AddAction(ActionInjectWTF69Self);
	}
};
