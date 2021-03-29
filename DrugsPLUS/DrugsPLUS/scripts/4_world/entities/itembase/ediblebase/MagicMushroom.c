modded class PsilocybeMushroom
{

	override void SetActions()
	{
		super.SetActions();
		RemoveAction(ActionForceFeed);
		RemoveAction(ActionEatSmall);
		AddAction(ActionConsumeDrugs);
	};

};