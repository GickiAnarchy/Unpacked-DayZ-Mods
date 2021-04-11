modded class PluginManager
{
    override void Init()
    {
        super.Init();

        RegisterPlugin("PluginNotesLog", false, true);
    }
}