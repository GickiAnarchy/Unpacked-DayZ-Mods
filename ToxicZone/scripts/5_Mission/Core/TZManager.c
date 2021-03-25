class TZManager
{
	ref ToxicAreaSettings m_ActiveToxicAreaSettings;
	ref LootTZSettings m_ActiveLootSettings;

    void TZManager()
    {
		if (GetGame().IsServer())	{
			GetTZLogger().LogInfo("TZManager - Started !");
			m_ActiveToxicAreaSettings = ToxicAreaSettings.Load();
			m_ActiveLootSettings = LootTZSettings.Load();
		}
    }

	void ~TZManager()
    {

    }

}
