modded class ActionConstructor 
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);

        // Drug Actions.
        actions.Insert(ActionConsumeDrugs);
    }
}
