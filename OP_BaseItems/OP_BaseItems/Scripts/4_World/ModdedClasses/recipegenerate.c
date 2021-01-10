modded class PluginRecipesManager 
{
    override void RegisterRecipies()
    {
        super.RegisterRecipies();
        RegisterRecipe(new CraftLocker);
      //RegisterRecipe(new CraftRainCatchKit);
        RegisterRecipe(new CraftShedKit);   
        RegisterRecipe(new LightBBQ);
        RegisterRecipe(new DeCraftWoodStorage);
        RegisterRecipe(new CraftWoodStorage);
        RegisterRecipe(new CraftBarrelframe);
        RegisterRecipe(new AttachWaterBarrel);
        RegisterRecipe(new CraftImpTentKit);
        RegisterRecipe(new CraftCamoEBanner);
        RegisterRecipe(new CraftCamoNBanner);
        RegisterRecipe(new CraftCamoWoodBanner);
        RegisterRecipe(new CraftCamoUCPBanner);
        RegisterRecipe(new CraftBannerMount);
        RegisterRecipe(new CraftGardenbox);              

    }       
}