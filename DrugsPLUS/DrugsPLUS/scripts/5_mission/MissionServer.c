modded class MissionServer
{
	private string DP_CONFIG_FILE =  "$profile:DrugsPLUS.json";
	ref DrugsPLUSConfig DP_config;	
	private int DP_modVersion = 110;

	void MissionServer()
	{
		string DP_fileName;
		FileAttr DP_fileAttr;
		FindFileHandle DP_configFile = FindFile(DP_CONFIG_FILE, DP_fileName, DP_fileAttr, 0);
		
		if(!DP_CONFIG_FILE){
			DP_config = new DrugsPLUSConfig();
			GetDayZGame().SetDrugsPLUSConfig(DP_config);
			JsonFileLoader<DrugsPLUSConfig>.JsonSaveFile(DP_CONFIG_FILE, DP_config);
			Print("[DP] Creating new DrugsPlus Config File");
		}else{
			//load current config file
			DP_config = new DrugsPLUSConfig();
			JsonFileLoader<DrugsPLUSConfig>.JsonLoadFile(DP_CONFIG_FILE, DP_config);
			if(DP_config.dp_configVersion == DP_modVersion) {
				GetDayZGame().SetDrugsPLUSConfig(DP_config);
				Print("[DP] Load Existing DrugsPlus Config File");
			} else {					
				DeleteFile("$profile:DrugsPLUS_old.json");
				CopyFile(DP_CONFIG_FILE, "$profile:DrugsPLUS_old.json");
				DeleteFile(DP_CONFIG_FILE);
				DP_config = new DrugsPLUSConfig();
				GetDayZGame().SetDrugsPLUSConfig(DP_config);
				JsonFileLoader<DrugsPLUSConfig>.JsonSaveFile(DP_CONFIG_FILE, DP_config);
				Print("[DP] Copy old DrugsPlus Config File");
			}
		}
	}		
}