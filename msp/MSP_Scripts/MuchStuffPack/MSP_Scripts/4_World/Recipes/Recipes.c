modded class PluginRecipesManager 
{
 	override void RegisterRecipies()
	{
		super.RegisterRecipies();		
				
		RegisterRecipe(new Msp_CraftItems(Msp_AppleCrate.GetRecipeValues()));
		RegisterRecipe(new Msp_CraftItems(Msp_AmericanAppleCrate.GetRecipeValues()));
		RegisterRecipe(new Msp_CraftItems(Msp_EmptyPlanterBox.GetRecipeValues()));
		RegisterRecipe(new Msp_CraftItems(Msp_EmptySquarePlanterBox.GetRecipeValues()));
		RegisterRecipe(new Msp_CraftItems(Msp_WaterBarrel_Stand.GetRecipeValues()));
		RegisterRecipe(new Msp_CraftItems(Msp_WaterBarrel_Valve.GetRecipeValues()));
		RegisterRecipe(new Msp_CraftItems(Msp_WaterBarrel_Stand_Darkwood.GetRecipeValues()));
		RegisterRecipe(new Msp_CraftItems(Msp_WaterBarrel_Valve_Darkwood.GetRecipeValues()));
		RegisterRecipe(new Msp_CraftItems(Msp_FireplaceRailing.GetRecipeValues()));
		
		//RegisterRecipe(new Msp_CraftItems(Msp_WaterBarrel.GetRecipeValues()));
		//RegisterRecipe(new Msp_CraftItems(Msp_WaterBarrel_Darkwood.GetRecipeValues()));
		//RegisterRecipe(new Msp_CraftItems(Msp_LargeAmmoBox.GetRecipeValues()));
	}
};