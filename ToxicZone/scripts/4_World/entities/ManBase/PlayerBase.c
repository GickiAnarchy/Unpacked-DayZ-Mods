class InsideTZ{
	
	string TZName;
	bool   TZStatut;
	
	void InsideTZ(){
		TZName="";
		TZStatut=false;
	}
	
}
modded class PlayerBase extends ManBase
{
	private ref array<string>m_SLOTS = {"Mask","Headgear","Body","Gloves","Legs","Feet"};
	private ref array<string>m_Suits = {"GP5GasMask","NBCHoodBase","NBCJacketBase","NBCGloves_ColorBase","NBCPantsBase","NBCBootsBase"};
	private ref array<int>m_Nbc_Health = {100,100,100,30,100,70};
	private ref array<float>SuitsDamage;
	private int cpt=0;
	bool IsOnlyGasMask;
	bool IsIrradied;
	bool IsCharcoalTabNeeded;
	bool IsGasMaskWorking;
	ref InsideTZ IsInside;
	bool IsUnprotected;
	int ToxicBloodLoss;
	int Slot_Count;
	int NbSickGiven;
	int NbSickGivenforToxicSmoke;
	int GP5DamageGrenade;
	//Particle m_ParticleOnPlayer;

	override void Init()
	{
		super.Init();
		IsUnprotected=false;
		IsIrradied=false;
		IsInside=new ref InsideTZ;
		SuitsDamage = new ref array<float>;
	}
	
	void ConfigSuit()
	{
		if (IsOnlyGasMask==1)
		{
			Slot_Count=0;
			//Print("Slot_Count=0");
		}
		else
		{
			Slot_Count=-1+m_SLOTS.Count();
			//Print("Slot_Count=-1+m_SLOTS.Count");
		}
	}

	void GiveRadiation()
	{
		GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
		InsertAgent(RadAgents.RADIATIONSICKNESS,NbSickGiven);
	}
	
	void GiveRadiationForToxicSmoke()
	{
		GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
		InsertAgent(RadAgents.RADIATIONSICKNESS,NbSickGivenforToxicSmoke);
	}

	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult,damageType,source,component,dmgZone,ammo,modelPos,speedCoef);
		if(IsInside.TZStatut==true && IsIrradied==false)
		{
			cpt+=1;
			if(cpt==5)
			{
				cpt=0;
				NBCSuitsLite();
			}
		}
	}
	
	void SetSuitsDamage(float damage)
	{
		for(int i=0;i<m_Nbc_Health.Count();i++)
		{
			SuitsDamage.Insert((m_Nbc_Health.Get(i)*damage)/100);
			//Print("NBC: "+ m_Nbc_Health.Get(i).ToString());
			//Print("damage: "+ damage.ToString());
			//Print("DamageFinal: "+ SuitsDamage.Get(i).ToString());
		}
	}

	void NBCSuits()
	{
		if (GetGame().IsServer())
		{
			ConfigSuit();
			for (int i = 0; i <= Slot_Count;i++)
			{
				EntityAI SuitsPart;
				SuitsPart = this.FindAttachmentBySlotName(m_SLOTS.Get(i));
				
				if (SuitsPart == NULL || SuitsPart.IsRuined() || !SuitsPart.IsKindOf(m_Suits.Get(i)))
				{
					IsUnprotected=true;
					GiveRadiation();
					return;
				}
				else
				{
					if (SuitsPart != NULL && !SuitsPart.IsRuined())
					{
						if(i!=0)
						{
							SuitsPart.AddHealth( "", "", -SuitsDamage.Get(i));
							//Print("i!=0 :"+i.ToString() +" :"+ SuitsDamage.Get(i).ToString());
							continue;
						}
						
						if(i == 0 && IsCharcoalTabNeeded && !SuitsPart.GetCompEM().IsWorking())
						{
							IsUnprotected=true;
							GiveRadiation();
							//Print("i==0 TRUE: IsCharcoalTabNeeded"+IsCharcoalTabNeeded.ToString() + "IsGasMaskWorking:" + IsGasMaskWorking.ToString());
							continue;
						}
						
						if(i==0 && !IsCharcoalTabNeeded)
						{
							SuitsPart.AddHealth( "", "", -SuitsDamage.Get(i));
							//Print("i!=0 :"+i.ToString() +" :"+ SuitsDamage.Get(i).ToString());
						}
					}
				}
			}
		}
	}
	
	/*void PlayParticleOnPlayer(){
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			if(IsInside){
				m_ParticleOnPlayer = Particle.PlayOnObject(ParticleList.TOXICZONE_GREENSMOKE, this);
			}
			else{
				if (m_ParticleOnPlayer)
				m_ParticleOnPlayer.Stop();
			}
		}
	}*/

	void NBCSuitsLite()
	{
		if (GetGame().IsServer())
		{
			ConfigSuit();
			for (int i = 0; i <= Slot_Count;i++)
			{
				EntityAI SuitsPart;
				SuitsPart = this.FindAttachmentBySlotName(m_SLOTS.Get(i));
				if (SuitsPart == NULL || SuitsPart.IsRuined() || !SuitsPart.IsKindOf(m_Suits.Get(i)))
				{
					IsUnprotected=true;
					//Print("GiveRadiation() NBCSuitsLite");
					GiveRadiation();
					return;
				}
				else
				{
					if (SuitsPart != NULL && !SuitsPart.IsRuined())
					{						
						if(i == 0 && IsCharcoalTabNeeded && !SuitsPart.GetCompEM().IsWorking())
						{
							IsUnprotected=true;
							GiveRadiation();
							//Print("i==0 TRUE: IsCharcoalTabNeeded"+IsCharcoalTabNeeded.ToString() + "IsGasMaskWorking:" + SuitsPart.GetCompEM().IsWorking().ToString());
							return;
						}
					}
				}
			}
			IsUnprotected=false;
		}
	}
	
	void IsProtected()
	{
		if (!IsUnprotected){
			return;
		}
		else{
			//Print("IsProtected()");
			NBCSuitsLite();
		}
	}
	
	void GasMaskCheck()
	{
		if (GetGame().IsServer())
		{
			EntityAI SuitsPart;
			SuitsPart = this.FindAttachmentBySlotName(m_SLOTS.Get(0));
			if (SuitsPart == NULL || SuitsPart.IsRuined() || !SuitsPart.IsKindOf(m_Suits.Get(0)))
			{
				GiveRadiationForToxicSmoke();
				return;
			}
			else
			{
				if (SuitsPart != NULL && !SuitsPart.IsRuined())
				{
					SuitsPart.AddHealth( "", "", -GP5DamageGrenade);
				}
			}
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		//Print("item:"+item.ToString()+"slot:"+slot_name);
		if(IsInside.TZStatut==true && IsIrradied==false)
		{
			NBCSuitsLite();
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		//Print("item:"+item.ToString()+"slot:"+slot_name);
		if(IsInside.TZStatut==true && IsIrradied==false)
		{
			NBCSuitsLite();
		}
	}

}
