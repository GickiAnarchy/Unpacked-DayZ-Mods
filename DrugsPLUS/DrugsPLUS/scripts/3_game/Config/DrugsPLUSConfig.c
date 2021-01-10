//preconfiguring the DrugsPLUS.json
class DrugsPLUSConfig
{
	int dp_configVersion;
	bool dp_removeAfterHarvest;	
	
	float coca_growtime;
	float coca_cropcount;
	float cocaSeed_count;
	
	void DrugsPLUSConfig() 
	{
		
		dp_configVersion		= 110;		
		coca_growtime 			= 8;
		coca_cropcount 			= 2;
		cocaSeed_count 			= 9;		
		dp_removeAfterHarvest 	= true;	
	};
};