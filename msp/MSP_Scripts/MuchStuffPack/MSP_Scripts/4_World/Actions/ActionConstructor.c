modded class ActionConstructor 
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);
        actions.Insert(ActionDismantleItem);
        actions.Insert(ActionCustomClose);
        actions.Insert(ActionCustomOpen);
        actions.Insert(ActionEmptyPlanter);
        actions.Insert(ActionFillPlanter);
        actions.Insert(ActionFoldItem);
        //actions.Insert(ActionUseMSPObject);
    }
};