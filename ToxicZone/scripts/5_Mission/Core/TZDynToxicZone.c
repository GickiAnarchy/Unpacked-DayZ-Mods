class TZDynToxicZone
{
	private string GUID;
	private string Coordinate;
	private vector SMOKE = "0 0 0";
	protected House m_DynParticle;
	private int m_CheckScheduler;
	private int RestartMZ=0;
	private float CooX;
	private float CooY;
	private ref DynToxicZoneLocation DynTZ;
	
	void TZDynToxicZone(ref DynToxicZoneLocation dyntz)
	{
		GetTZLogger().LogInfo("TZDynToxicZone - Started ! : ID:"+GetTZConfig().DynToxicAreaLocation.Count());
		DynTZ=dyntz;
		DefineRestartMZ();
		if ( GetGame().IsServer() ) {	
			StartParticleEffect();
			GetGame().GetMission().MissionScript.Call( this, "CheckScheduler", null );
			GetGame().GetMission().MissionScript.Call( this, "RestartDynTZ", null );
		}
	}                                                                                                                                                                                               
	
	void DefineRestartMZ()
	{
		RestartMZ=DynTZ.norme/((Math.Sqrt(Math.Pow(DynTZ.Speed,2)))/(GetTZConfig().CheckDynNBC/1000));
		GetTZLogger().LogInfo(DynTZ.DynToxicZoneStatut+"RestartMZ:"+RestartMZ.ToString());
	}
	
	void RestartDynTZ()
	{
		while(1){
		   CooX=DynTZ.StartX;
		   CooY=DynTZ.StartY;
		   Sleep(RestartMZ*1000);
		}
	}
	
	void StartParticleEffect()
	{
		SMOKE[0]=DynTZ.StartX;
		SMOKE[2]=DynTZ.StartY;
		SMOKE[1]=GetGame().SurfaceY( DynTZ.StartX, DynTZ.StartY );
		CooX=DynTZ.StartX;
		CooY=DynTZ.StartY;
		GetTZLogger().LogInfo("DynTZ.StartX"+SMOKE.ToString());
		m_DynParticle = House.Cast(GetGame().CreateObject(DynTZ.ParticleName,SMOKE));
	}
	
	void FunctionTrajectory()
	{
		CooY=DynTZ.Coeff*CooX+DynTZ.YtoOrigin;
		CooX+=DynTZ.Speed;
	}	

	private void SendMessageClient(PlayerBase player, string message)
	{
		Param1<string> m_MesParam = new Param1<string>(message);
		GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, m_MesParam, true, player.GetIdentity());
	}

	private void SendPosToAdmin(PlayerBase pl)
	{
		//Steam 64 UID
		int cpt=1-GetTZConfig().AdminUID.Count();
		for(int i=0;i<=cpt;i++)
		{
			if (GUID == GetTZConfig().AdminUID.Get(i))
			{
				Coordinate="Dyn.ToxicZone: X=" + CooX.ToString() + " Y=" + CooY.ToString();
				SendMessageClient(pl, Coordinate);
			}
		}
	}

	void MoveParticles(float X,float Y)
	{
		SMOKE[0]=X;
		SMOKE[2]=Y;
		SMOKE[1]=GetGame().SurfaceY( X, Y );
		m_DynParticle.SetPosition(SMOKE);
	}
	
	void CheckScheduler()
	{
		m_CheckScheduler = GetTZConfig().CheckDynNBC;

		while(1)
		{
			array<Man> m_Players = new array<Man>;
			GetGame().GetPlayers(m_Players);
			FunctionTrajectory();
			MoveParticles(CooX,CooY);
			for(int i = 0; i < m_Players.Count(); i++)
			{
				PlayerBase player;
				Class.CastTo(player, m_Players.Get(i));
				GUID = player.GetIdentity().GetPlainId();
				SendPosToAdmin(player);
				DynToxicZone(player);
			}
			Sleep(m_CheckScheduler);
		}
	}
	
	void DynToxicZone(PlayerBase player)
	{
		GetTZLogger().LogInfo("DynToxicZone - X: " + CooX.ToString() + " Y: " + CooY.ToString() + " Radius: " + DynTZ.Radius);
		string ZoneCheck;
		vector pos = player.GetPosition();
		float distance_squared = Math.Pow(CooX-pos[0], 2) + Math.Pow(CooY-pos[2], 2);
		if ( distance_squared <= Math.Pow(DynTZ.Radius, 2) )
		{
			if (player.IsInside.TZName==DynTZ.DynToxicZoneStatut && player.IsInside.TZStatut) //Already in zone
			{
				player.IsProtected();
				return;
			}
			else
			{
				player.IsInside.TZName=DynTZ.DynToxicZoneStatut;
				player.IsInside.TZStatut=true;
				player.IsOnlyGasMask=DynTZ.IsOnlyGasMask;
				if(player.IsIrradied==true)return;
				player.NBCSuits();
				if(GetTZConfig().IsMsgActive==0)return;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Toxic Zone", GetTZConfig().MsgEnterZone, "ToxicZone/images/radiation.paa");
			}
		}
		else if(distance_squared > Math.Pow(DynTZ.Radius, 2))
		{
			if (player.IsInside.TZName==DynTZ.DynToxicZoneStatut && player.IsInside.TZStatut)
			{
				player.IsInside.TZStatut=false;
				player.IsInside.TZName="";
				if(GetTZConfig().IsMsgActive==0)return;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Toxic Zone", GetTZConfig().MsgExitZone, "ToxicZone/images/radiation.paa");
			}
			else
			{
				return;
			}
		}
	}
}