modded class MissionServer
{
	protected ref DrugsPLUSConfigManager dp_currentcfg;

	override void OnInit()
	{
		super.OnInit();
		if(!dp_currentcfg)
			dp_currentcfg = GetDPConfig();//Server creates default config for the mod on the startup!
		if(dp_currentcfg)
			Print("[DP] Config Sucessfully loaded!");
		else
			Print("[DP] Internal Serverconfig Load failed!");
		
		GetRPCManager().AddRPC( "DP_scripts", "DPCLIENTCONFIGREQUEST", this, SingeplayerExecutionType.Both );
	}

	/* RPC HANDLING SERVERSIDE */
	void DPCLIENTCONFIGREQUEST(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target) {

		if(type == CallType.Server) {
			GetRPCManager().SendRPC("DP_scripts", "DPCONFIGRESPONSE", new Param1< ref DrugsPLUSConfigManager >( dp_currentcfg ), true, sender);
			Print("[DP] -> Sucessfully sent: " + sender.GetName() + " DP Plus Config!");
		}
	}
}