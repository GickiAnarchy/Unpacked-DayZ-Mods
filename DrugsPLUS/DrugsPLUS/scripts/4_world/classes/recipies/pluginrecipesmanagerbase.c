modded class PluginRecipesManager 
{
	override void RegisterRecipies()
    {
        super.RegisterRecipies();
        RegisterRecipe(new DP_CraftCocaBag);
        RegisterRecipe(new DP_CraftCocaBrick);
    }
}