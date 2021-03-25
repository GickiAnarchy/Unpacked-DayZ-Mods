class TZToxicZone extends TZManager
{
	private string GUID;
	private House m_Particle;
	private int m_CheckScheduler;
	
	void TZToxicZone()
	{
		if ( GetGame().IsServer() ) {	
			GetTZLogger().LogInfo("TZToxicZone - Started !");
			StartParticleEffect();
			GetGame().GetMission().MissionScript.Call( this, "CheckScheduler", null );
		}
	}
	
	void StartParticleEffect()
	{
		for( int i=0;i<GetTZConfig().ToxicAreaLocation.Count();i++)
		{
			ToxicZoneLocation ToxArea = GetTZConfig().ToxicAreaLocation.Get(i);
				
			for (int k=0;k<ToxArea.ParticlesPosition.Count();k++)
			{
				m_Particle = House.Cast(GetGame().CreateObject(ToxArea.ParticlesPosition.Get(k).NName,ToxArea.ParticlesPosition.Get(k).PPos));
			}
		}
	}
	
	void CheckScheduler()
	{
		m_CheckScheduler = GetTZConfig().CheckNBC;
		while(1)
		{
			array<Man> m_Players = new array<Man>;
			GetGame().GetPlayers(m_Players);
			for(int i = 0; i < m_Players.Count(); i++)
			{
				PlayerBase player;
				Class.CastTo(player, m_Players.Get(i));
				for (int k=0;k<GetTZConfig().ToxicAreaLocation.Count();k++)
				{
					private ToxicZoneLocation m_ActiveToxicAreaLocation = GetTZConfig().ToxicAreaLocation.Get(k);
					if( m_ActiveToxicAreaLocation.IsSquareZone == 0){
						ToxicZoneRound(m_ActiveToxicAreaLocation.IsOnlyGasMask,m_ActiveToxicAreaLocation.X,m_ActiveToxicAreaLocation.Y,m_ActiveToxicAreaLocation.Radius,m_ActiveToxicAreaLocation.ToxicZoneStatut,player);
					}
					else{	
						ToxicZoneSquare(m_ActiveToxicAreaLocation.IsOnlyGasMask,m_ActiveToxicAreaLocation.X1,m_ActiveToxicAreaLocation.Y1,m_ActiveToxicAreaLocation.X2,m_ActiveToxicAreaLocation.Y2,m_ActiveToxicAreaLocation.ToxicZoneStatut,player);
					}
				}
			}
			Sleep(m_CheckScheduler);
		}
	}

	void ToxicZoneRound(bool isonlygasmask,float m_X, float m_Y, float Zone_Radius,string Status,PlayerBase player)
	{
		string ZoneCheck;
		vector pos = player.GetPosition();
		float distance_squared = Math.Pow(m_X-pos[0], 2) + Math.Pow(m_Y-pos[2], 2);
		if ( distance_squared <= Math.Pow(Zone_Radius, 2) )
		{
			if (player.IsInside.TZName==Status && player.IsInside.TZStatut) //Already in zone
			{
				//GetTZLogger().LogInfo("IF1:" + player.IsInside.TZName + player.IsInside.TZStatut.ToString());
				//GetTZLogger().LogInfo("player.IsUnprotected:" + player.IsUnprotected.ToString());
				player.IsProtected();
				return;
			}
			else
			{
				//GetTZLogger().LogInfo("ELSE1:" + player.IsInside.TZName + player.IsInside.TZStatut.ToString());
				player.IsInside.TZName=Status;
				player.IsInside.TZStatut=true;
				player.IsOnlyGasMask=isonlygasmask;
				if(player.IsIrradied==true)return;
				player.NBCSuits();
				if(GetTZConfig().IsMsgActive==0)return;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Toxic Zone", GetTZConfig().MsgEnterZone, "ToxicZone/images/radiation.paa");
			}
		}
		else if ( distance_squared > Math.Pow(Zone_Radius, 2) )
		{
			if (player.IsInside.TZName==Status && player.IsInside.TZStatut)
			{
				//GetTZLogger().LogInfo("IF2:" + player.IsInside.TZName + player.IsInside.TZStatut.ToString());
				player.IsInside.TZStatut=false;
				player.IsInside.TZName="";
				if(GetTZConfig().IsMsgActive==0)return;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Toxic Zone", GetTZConfig().MsgExitZone, "ToxicZone/images/radiation.paa");
			}
			else
			{
				//GetTZLogger().LogInfo("ELSE2:" + player.IsInside.TZName + player.IsInside.TZStatut.ToString());
				return;
			}
		}
	}
	
	void ToxicZoneSquare(bool isonlygasmask,float m_X1, float m_Y1, float m_X2, float m_Y2,string Status,PlayerBase player)
	{
		string ZoneCheck;
		vector pos = player.GetPosition();
		if ( (pos[0]>m_X1 && pos[0]<m_X2) && (pos[2]>m_Y1 && pos[2]<m_Y2) )
		{
			if (player.IsInside.TZName==Status && player.IsInside.TZStatut) //Already in zone
			{
				//GetTZLogger().LogInfo("IF1:" + player.IsInside.TZName + player.IsInside.TZStatut.ToString());
				player.IsProtected();
				return;
			}
			else
			{
				//GetTZLogger().LogInfo("ELSE1:" + player.IsInside.TZName + player.IsInside.TZStatut.ToString());
				player.IsInside.TZName=Status;
				player.IsInside.TZStatut=true;
				player.IsOnlyGasMask=isonlygasmask;
				if(player.IsIrradied==true)return;
				player.NBCSuits();
				if(GetTZConfig().IsMsgActive==0)return;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Toxic Zone", GetTZConfig().MsgEnterZone, "ToxicZone/images/radiation.paa");
			}
		}
		else
		{
			if (player.IsInside.TZName==Status && player.IsInside.TZStatut)
			{
				//GetTZLogger().LogInfo("IF2:" + player.IsInside.TZName + player.IsInside.TZStatut.ToString());
				player.IsInside.TZStatut=false;
				player.IsInside.TZName="";
				if(GetTZConfig().IsMsgActive==0)return;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Toxic Zone", GetTZConfig().MsgExitZone, "ToxicZone/images/radiation.paa");
			}
			else
			{
				//GetTZLogger().LogInfo("ELSE2:" + player.IsInside.TZName + player.IsInside.TZStatut.ToString());
				return;
			}
		}
	}
}