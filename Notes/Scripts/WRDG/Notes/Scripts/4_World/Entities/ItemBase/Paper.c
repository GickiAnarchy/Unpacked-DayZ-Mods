modded class Paper
{
    override void SetActions()
	{
		super.SetActions();

		RemoveAction(ActionReadPaper);
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
}