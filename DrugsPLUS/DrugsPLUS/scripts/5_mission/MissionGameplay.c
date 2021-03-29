modded class MissionGameplay extends MissionBase
{
	protected bool dp_isModdedMissionInitialized = false;

	override void OnInit()
	{
		super.OnInit();
		if(!dp_isModdedMissionInitialized) {
			GetRPCManager().AddRPC( "DP_scripts", "DPCONFIGRESPONSE", this, SingeplayerExecutionType.Client );
			dp_isModdedMissionInitialized = true;
		}
	}

	override void OnMissionStart()
	{
		super.OnMissionStart();
		GetRPCManager().SendRPC("DP_scripts", "DPCLIENTCONFIGREQUEST", null, true);//Sends the remote a request to get the config.
	}

	/* RPC HANDLING OF CLIENT */ 
	void DPCONFIGRESPONSE(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target) {

		if(type == CallType.Client) 
		{
			Param1 <ref DrugsPLUSConfigManager> data;
        	if ( !ctx.Read( data ) ) return;
			g_ClientDrugsPLUSConfig = data.param1; //Update our referenz in Gamemodule.
			Print("[DP] Sucessfully recieved config from remote!");
		}
	}
}