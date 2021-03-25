modded class PlayerBase extends ManBase
{
bool HasWTF69 = false;
 
ref Timer WTF69vignettetimer;   
ref Timer WTF69overlaytimer;   
ref Timer deathtimer;   
 



   
   /*
void WTF69vignette()
    {
   
    if(GetSingleAgentCount(WTF69Agents.WTF69VIRUS)>0)
            {
	 
			
            float Agents = GetSingleAgentCount(WTF69Agents.WTF69VIRUS);
            float dividedagents = Agents / 500;
            float clampedagents = Math.Clamp(dividedagents,0,0.8);
	  float Vignetteintensity = clampedagents;
           
      	  GetRPCManager().SendRPC( "28DayZLater", "WTF69RPC", new Param1< float >( Vignetteintensity ) );
	
           
            }
            else
                {
                Print("vignetteOFF");
                WTF69vignettetimer.Stop();
                   
                }
           
    }


		
     */  
	
	
	
	
	
	
	
/*
	void WTF69vignette()
	{
	
	if(GetSingleAgentCount(WTF69Agents.WTF69VIRUS)>0)
			{
			
			//int Agents = GetSingleAgentCount(WTF69Agents.WTF69VIRUS);
			//float clampedagents = Agents / 500;
			//PPEffects.SetVignette(clampedagents,1,0,0);
			SetSynchDirty();
			  float Agents = GetSingleAgentCount(WTF69Agents.WTF69VIRUS);
          		  float dividedagents = Agents / 500;
          		  float clampedagents = Math.Clamp(dividedagents,0,0.8);
			if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT) 
				{
			  CameraFuncs cam = new CameraFuncs();
         			  cam.changeVignette(dividedagents,1,0,0);
			  //Print("vignetteON"+ clampedagents);
				}
			}
			else
				{
				Print("vignetteOFF");
				WTF69vignettetimer.Stop();
					
				}
			
	}
	
void WTF69timer()
	{	
	
		WTF69overlaytimer = new Timer();
		WTF69overlaytimer.Run(0.1, this, "PlayerWTF69", NULL, true);
	}	
	
void PlayerWTF69()
	{
		SetSynchDirty();
	float max_blood = GetMaxHealth("GlobalHealth", "Blood") + 0.01;
	float playerblood = GetHealth("GlobalHealth", "Blood") / max_blood;
	float playerbloodoffset = playerblood - 1;
	if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT) 
		{
	CameraFuncs WTF69 = new CameraFuncs();
	WTF69.SetWTF69Overlay(0,0.4,0.9,playerbloodoffset);//0.7 orig alpha
		}
			//Print(playerbloodoffset);
		
		
		
	}
void PlayerWTF69Deactivate()
	{
		SetSynchDirty();
	WTF69overlaytimer.Stop();
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT) 
		{
	CameraFuncs WTF69Deactivate = new CameraFuncs();
	WTF69Deactivate.SetWTF69Overlay(0,0,0,0);
		}
	}
	
		

*/
 	override void SetActions() 
	{
		super.SetActions();
	
		AddAction(ActionAnalyseVirus);

	} 

	
override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{	
		if(source.IsZombie())
		{
			if(WTF69vignettetimer && WTF69vignettetimer.!IsRunning())
			{
			WTF69vignettetimer.Run(0.3, this ,"WTF69vignette",NULL ,true);
				//Print("vignettetimerrestart");
			}
			else
			{
			WTF69vignettetimer = new Timer();
			WTF69vignettetimer.Run(0.3, this ,"WTF69vignette",NULL ,true);
				//Print("vignettetimernew");
			}
			
				
				int randomint = Math.RandomInt(0,10);
					if(randomint < 2)
					{
					this.InsertAgent(WTF69Agents.WTF69VIRUS, 20);
					}
							
			}
		
		
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
	}
	

	////////////////////////////RPC/////////////////////////////////
	
	
	
	
}
