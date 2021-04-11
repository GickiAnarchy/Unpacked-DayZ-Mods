modded class ActionConstructor
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);

        actions.Insert(ActionReadPaper);
        actions.Insert(ActionReadPaperTarget);
        actions.Insert(ActionWritePaper);
    }
}