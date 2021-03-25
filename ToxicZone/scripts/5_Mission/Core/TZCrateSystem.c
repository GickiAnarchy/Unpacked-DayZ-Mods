class TZCrateSystem
{
	private EntityAI m_Loot=NULL;
	private ref array<EntityAI> m_LootList;
	private ref array<Object> DeadWolfObjs;
	
	void TZCrateSystem()
	{
		GetTZLogger().LogInfo("[LOOTSYSTEM]:LootSpawner - Started !");
		m_LootList = new array<EntityAI>;
		DeadWolfObjs = new array<Object>;
		
		if ( GetGame().IsServer() ) {
			GetGame().GetMission().MissionScript.Call( this, "LootSpawner", null );
		}
	}
	
	void LootSpawner()
	{		
		while(1)
		{
			CheckDeadWolfStatus();
			CheckToxicChestListStatus();
			for( int i=0;i<GetTZConfig().ToxicAreaLocation.Count();i++)
			{
				if(GetTZConfig().ToxicAreaLocation.Get(i).IsLootActive != 1)continue;
				GetTZLogger().LogInfo(GetTZConfig().ToxicAreaLocation.Get(i).NumbCratePerTime.ToString());
				for(int j=0; j< GetTZConfig().ToxicAreaLocation.Get(i).NumbCratePerTime; j++)
				{
					int fin=-1+GetTZConfig().ToxicAreaLocation.Get(i).ToxicCratePosition.Count();
					int WhichZone=Math.RandomIntInclusive(0,fin);
					ref ToxicZoneLocation TZL = GetTZConfig().ToxicAreaLocation.Get(i);
					CreateEzDrop(TZL.MaxLoot,TZL.ContainerName,TZL.ToxicCratePosition.Get(WhichZone).POS, TZL.ToxicCratePosition.Get(WhichZone).ORI,TZL.ToxicCratePosition.Get(WhichZone).Name,i);
				}
			}
			Sleep(GetTZLootConfig().TimerLoot);
		}
	}

	void CreateEzDrop(int maxloot, string container_name,vector v, vector o, string name,int here)
	{
		int k,temp;
		if(v[1]==0)v[1]=GetGame().SurfaceY(v[0], v[2]);
		m_Loot = EntityAI.Cast(GetGame().CreateObject( container_name, v, false, true, true));
		m_Loot.SetOrientation(o);
		m_LootList.Insert(m_Loot);
		GetTZLogger().LogInfo("[LOOTSYSTEM]: ToxicChestSpawned:"+" CrateName: "+ name + "- Position: X:"+v[0].ToString()+" Y:"+v[1].ToString()+" Z:"+v[2].ToString());
		int count=-1+GetTZLootConfig().ListLoots.Count();
		for(int i=0; i<=count;i++)
		{
			if(GetTZLootConfig().ListLoots.Get(i).Name==name){
				k=i;
			}
		}
		for(int l=0;l<GetTZLootConfig().ListLoots.Get(k).Loots.Count();l++)
		{
			if(temp>=maxloot && maxloot!=-1)continue;
			if ( GetTZLootConfig().ListLoots.Get(k).Loots.Get(l).ProbToSpawn > Math.RandomFloatInclusive(0,1) )
			{
				if (GetTZLootConfig().ListLoots.Get(k).Loots.Get(l).AttachmentsToLoot.Count() == 0)
				{
					m_Loot.GetInventory().CreateInInventory(GetTZLootConfig().ListLoots.Get(k).Loots.Get(l).LootName);
					temp+=1;
					GetTZLogger().LogInfo(GetTZLootConfig().ListLoots.Get(k).Loots.Get(l).LootName);
					continue;
				}
				else
				{
					m_Loot.GetInventory().CreateInInventory(GetTZLootConfig().ListLoots.Get(k).Loots.Get(l).LootName);
					temp+=1;
					GetTZLogger().LogInfo(GetTZLootConfig().ListLoots.Get(k).Loots.Get(l).LootName);
					for( int parc=0; parc < GetTZLootConfig().ListLoots.Get(k).Loots.Get(l).AttachmentsToLoot.Count() ; parc++)
					{
						if ( GetTZLootConfig().ListLoots.Get(k).Loots.Get(l).AttachmentsToLoot.Get(parc).ProbAttachToSpawn > Math.RandomFloatInclusive(0,1) )
						{
							m_Loot.GetInventory().CreateInInventory(GetTZLootConfig().ListLoots.Get(k).Loots.Get(l).AttachmentsToLoot.Get(parc).AttachName);
							temp+=1;
							GetTZLogger().LogInfo(GetTZLootConfig().ListLoots.Get(k).Loots.Get(l).AttachmentsToLoot.Get(parc).AttachName);
						}
					}
				}
			}
		}
		for(int j=0;j<GetTZConfig().ToxicAreaLocation.Get(here).CreatureList.Count();j++)
		{
			int m_stop= -1 + GetTZConfig().ToxicAreaLocation.Get(here).CreatureList.Get(j).Max;
			GetTZLogger().LogInfo("[LOOTSYSTEM] Spawned: " + GetTZConfig().ToxicAreaLocation.Get(here).CreatureList.Get(j).CreatureName + "count: " + GetTZConfig().ToxicAreaLocation.Get(here).CreatureList.Get(j).Max.ToString());
			for(int m_k=0;m_k<=m_stop;m_k++)
			{
				vector offset = v;
				offset[0] = offset[0] + Math.RandomIntInclusive(-20,20);
				offset[2] = offset[2] + Math.RandomIntInclusive(-20,20);
				string creature = GetTZConfig().ToxicAreaLocation.Get(here).CreatureList.Get(j).CreatureName;
				Object Wolf=GetGame().CreateObject(creature, snapToGround(offset), false, true, true);
				DeadWolfObjs.Insert(Wolf);
			}
		}
	}

	void CheckDeadWolfStatus()
	{
		GetTZLogger().LogInfo("[LOOTSYSTEM]: [CreatureCleaner] !");
		if(DeadWolfObjs.Count() == 0){
			GetTZLogger().LogInfo("[LOOTSYSTEM]: Creature equal to 0!");
            return;
        }
		else
		{
			for(int i = 0; i < DeadWolfObjs.Count(); i++){
				if(DeadWolfObjs.Get(i)!=NULL){
					GetGame().ObjectDelete(DeadWolfObjs.Get(i));
					GetTZLogger().LogInfo("[LOOTSYSTEM]: Creature has been deleted!");
				}
			}
			DeadWolfObjs.Clear();
			return;
		}
		
	}
	
	void CheckToxicChestListStatus()
	{
		GetTZLogger().LogInfo("[LOOTSYSTEM]: [ToxicChestCleaner] !");
		if(m_LootList.Count() == 0){
			GetTZLogger().LogInfo("[LOOTSYSTEM]: ToxicChestList equal to 0!");
            return;
        }
		else
		{
			for(int i = 0; i < m_LootList.Count(); i++){
				if(m_LootList.Get(i)!=NULL){
					GetGame().ObjectDelete(m_LootList.Get(i));
					GetTZLogger().LogInfo("[LOOTSYSTEM]: ToxicChestList has been deleted!");
				}
			}
			m_LootList.Clear();
			return;
		}
		
	}

	private vector snapToGround(vector pos)
    {
        float pos_x = pos[0];
        float pos_z = pos[2];
        float pos_y = GetGame().SurfaceY( pos_x, pos_z );
        vector tmp_pos = Vector( pos_x, pos_y, pos_z );
        tmp_pos[1] = tmp_pos[1] + pos[1];

        return tmp_pos;
    }
}