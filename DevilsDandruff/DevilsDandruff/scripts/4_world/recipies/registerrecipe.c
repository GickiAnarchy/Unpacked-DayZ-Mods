modded class PluginRecipesManager 
{
    override void RegisterRecipies()
    {
        super.RegisterRecipies();
        
        RegisterRecipe(new Craft_CocaineBrick);
		RegisterRecipe(new Craft_CocaineRocks);
    }
}