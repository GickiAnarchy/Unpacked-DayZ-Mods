//preconfiguring the DrugsPLUS.json
class DrugsPLUSConfigManager
{
	int dp_configVersion;

	bool dp_removeAfterHarvest;	
	
	float coca_growtime;
	int coca_cropcount;
	int cocaSeed_count;

	float cocaineHueIntensity;
	int cocaineRadBlurXPower;
	int cocaineRadBlurYPower;
	int cocaineEffectTime;

	bool allowcokeenergybuff;
	bool allowunlimitedstamina;

	float vodkaHueIntensity;
	int vodkaRadBlurXPower;
	int vodkaRadBlurYPower;
	int vodkaEffectTime;

	int magicmushroomEffectTime;

	void DrugsPLUSConfigManager() 
	{
		
	};	
	
	void LoadDefaultSettings() 
	{
		
		dp_configVersion		= GetModVersion();	
		coca_growtime 		= 8;
		coca_cropcount 		= 2;
		cocaSeed_count 		= 9;		
		dp_removeAfterHarvest 	= true;	

		allowunlimitedstamina   = true;

		vodkaHueIntensity 	= 55.0;
        	vodkaRadBlurXPower 	= 3;
        	vodkaRadBlurYPower 	= 3;
        	vodkaEffectTime		= 120;

		cocaineHueIntensity 	= 70.0;
        	cocaineRadBlurXPower 	= 1;
		cocaineRadBlurYPower 	= 1;
		cocaineEffectTime	 	= 120;

		magicmushroomEffectTime	= 120;

		SaveConfig();

	};

	bool IsConfigOutdated() {
		if (this.dp_configVersion != GetModVersion())
			return true;
		return false;
	}

	protected int GetModVersion() { 
		string cfgversion = "CfgMods DrugsPLUS version";
		string ModVersion;
		float modFloat;	
		GetGame().ConfigGetText(cfgversion, ModVersion);
		//Print("[DP->] ModConfig entry found Mod Version is: " + ModVersion);
		modFloat  = ModVersion.ToFloat()*100;	
		return (int)modFloat;
	}

	void SaveOldConfig() {
		local const string cfgbkpPath = "$profile:DrugsPLUS/ConfigBackup";
		if (!FileExist(cfgbkpPath))
			MakeDirectory(cfgbkpPath);
		if (FileExist(m_DPConfigPath)) {
			CopyFile(m_DPConfigPath, cfgbkpPath + "/DrugsPLUSConfig_OLD_Version.json");
			DeleteFile(m_DPConfigPath);
		}
	}

	//this saves the config to the json file.
	protected void SaveConfig() {
		if (!FileExist(m_DPProfileDir + m_DPProfileFolder + "/"))
			MakeDirectory(m_DPProfileDir + m_DPProfileFolder + "/");
		JsonFileLoader<DrugsPLUSConfigManager>.JsonSaveFile(m_DPConfigPath, this);
	};

	//Dont use that to load the config!
	static ref DrugsPLUSConfigManager LoadConfig() {
	ref DrugsPLUSConfigManager settings = new DrugsPLUSConfigManager();
	if (!FileExist(m_DPProfileFolder))
		MakeDirectory(m_DPProfileFolder);
	if (FileExist(m_DPConfigPath))
	{
		JsonFileLoader<DrugsPLUSConfigManager>.JsonLoadFile(m_DPConfigPath, settings);
		if (settings.IsConfigOutdated())
		{
			settings.SaveOldConfig();
			settings.LoadDefaultSettings();
		}
	}
	else
	{
		settings.LoadDefaultSettings();
	}
	return settings;
    }
};

/* Global Getter for config */
static ref DrugsPLUSConfigManager g_DrugsPLUSConfig;
static ref DrugsPLUSConfigManager g_ClientDrugsPLUSConfig;
static ref DrugsPLUSConfigManager GetDPConfig()
{
	if (g_Game.IsServer() && !g_DrugsPLUSConfig) 
	{
		g_DrugsPLUSConfig = DrugsPLUSConfigManager.LoadConfig();
	}
	else if (g_Game.IsClient())
	{
		return g_ClientDrugsPLUSConfig; //GetsFilled on mission start with an RPC.
	}
	return g_DrugsPLUSConfig;
};