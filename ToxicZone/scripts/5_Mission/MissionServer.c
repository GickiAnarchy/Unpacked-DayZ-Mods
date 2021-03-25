modded class MissionServer extends MissionBase
{
	ref TZToxicZone ToxicZone;
	ref array<ref TZDynToxicZone> DynToxicZone;
	ref TZCrateSystem CrateSystem;
	
	private int cpt1,cpt2;

	void MissionServer() {
		m_TZManager = NULL;
		GetTZManager();
	}
	
	void initDynToxicZone()
	{
		if(GetTZConfig().IsDynZoneActive == 0)return;
		DynToxicZone = new array<ref TZDynToxicZone>;
		int cpt=-1+GetTZConfig().DynToxicAreaLocation.Count();
		//GetTZLogger().LogInfo("DynToxicZoneActive - Yes - NbAreaActive:"+(cpt+1).ToString());
		for (int k=0;k<=cpt;k++)
		{
			if(GetTZConfig().DynToxicAreaLocation.Get(k).Chance > Math.RandomFloatInclusive(0,1))
			{
				GetTZLogger().LogInfo("DynToxicZone Spawned at X:"+GetTZConfig().DynToxicAreaLocation.Get(k).StartX.ToString() + " Y:" + GetTZConfig().DynToxicAreaLocation.Get(k).StartY);
				DynToxicZone.Insert(new ref TZDynToxicZone(GetTZConfig().DynToxicAreaLocation.Get(k)));
			}
		}
	}

	void ~MissionServer() {
	}

	override void OnInit()
	{
		super.OnInit();
		initCrateSystem();
		initToxicZone();		
		initDynToxicZone();
		
		cpt1=-1+GetTZConfig().ToxicAreaLocation.Count();
		cpt2=-1+GetTZConfig().DynToxicAreaLocation.Count();
	}
	
	void RefreshPlayerStatut()
	{
		
	}
	
	void initCrateSystem()
	{
		if(GetTZLootConfig().IsActive == 1 )
		{
			CrateSystem = new TZCrateSystem;
		}
	}
	
	void initToxicZone()
	{
		if(GetTZConfig().IsToxicZoneActive == 1){
			ToxicZone = new TZToxicZone;
		}
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player,identity);
		InitializeToxicConfigToPlayer(player);
		//CheckToxicZoneOnConnect(player);
	}

	override void InvokeOnDisconnect( PlayerBase player )
	{
		super.InvokeOnDisconnect(player);
		//CheckToxicZoneOnConnect(player);
	}
	
	void InitializeToxicConfigToPlayer(PlayerBase player)
	{
		//GetTZLogger().LogInfo("Pass Config to Player : IsCharcoalTabNeeded:"+GetTZConfig().IsCharcoalTabNeeded.ToString());
		player.IsCharcoalTabNeeded = GetTZConfig().IsCharcoalTabNeeded;
		player.ToxicBloodLoss = GetTZConfig().ToxicBloodLoss;
		//GetTZLogger().LogInfo("ToxicBloodLoss"+player.ToxicBloodLoss.ToString());
		player.GP5DamageGrenade = GetTZConfig().GP5DamageGrenade;
		//GetTZLogger().LogInfo("GP5DamageGrenade"+player.GP5DamageGrenade.ToString());
		player.NbSickGiven = GetTZConfig().NbSickGiven;
		//GetTZLogger().LogInfo("NbSickGiven/"+player.NbSickGiven.ToString());
		player.SetSuitsDamage(GetTZConfig().SuitsDamage);
		//GetTZLogger().LogInfo("SuitsDamage:"+player.SuitsDamage.ToString());
		player.NbSickGivenforToxicSmoke = GetTZConfig().NbSickGivenforToxicSmoke;
		//GetTZLogger().LogInfo("NbSickGivenforToxicSmoke:"+player.NbSickGivenforToxicSmoke.ToString());
		player.ConfigSuit();
	}
	
	
	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{		
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);
		
		GetGame().SelectPlayer(identity, m_player);
	
		m_player.IsInside.TZStatut=false;
		
		return m_player;
		//moduleDefaultCharacter.FileDelete(moduleDefaultCharacter.GetFileName());
	}

	/*void CheckToxicZoneOnConnect(PlayerBase player)
	{
		for (int k=0;k<=cpt1;k++)
		{
			ToxicZoneStatut(GetTZConfig().ToxicAreaLocation.Get(k).ToxicZoneStatut,player,GetTZConfig().ToxicAreaLocation.Get(k).IsOnlyGasMask);
		}
		for (int j=0;j<=cpt2;j++)
		{
			ToxicZoneStatut(GetTZConfig().DynToxicAreaLocation.Get(j).DynToxicZoneStatut,player,GetTZConfig().DynToxicAreaLocation.Get(j).IsOnlyGasMask);
		}
	}*/

	/*void ToxicZoneStatut(string Status,PlayerBase player,int isonlygasmask)
	{
		string ZoneCheck,GUID;
		GUID=player.GetIdentity().GetPlainId();
		GetTZLogger().LogInfo("GUID:"+ GUID.ToString());
		g_Game.GetProfileString(Status+ GUID, ZoneCheck);
		if (ZoneCheck == "true")
		{
			player.IsInside.TZStatut=true;
			player.IsOnlyGasMask=isonlygasmask;
			GetTZLogger().LogInfo("OnConnect: ToxicZone : " + Status + "IsInside=true");
			return;
		}
		else
		{
			GetTZLogger().LogInfo("OnConnect: ToxicZone : " + Status + "IsInside=false");
			g_Game.SetProfileString(Status+ GUID, "false");
		}
	}*/
}
