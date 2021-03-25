class ToxicSmoke_ColorBase extends ToxicSmoke
{
	const string SOUND_SMOKE_START = "SmokegGrenades_RDG2_start_loop_SoundSet";
	const string SOUND_SMOKE_LOOP = "SmokegGrenades_RDG2_active_loop_SoundSet";
	const string SOUND_SMOKE_END = "SmokegGrenades_RDG2_end_loop_SoundSet";
	
	void ToxicSmoke_ColorBase()
	{
		SetAmmoType("");
		SetFuseDelay(2);
		SetParticlePosition("0 0.1 0");
		SetSoundSmokeStart(SOUND_SMOKE_START);
		SetSoundSmokeLoop(SOUND_SMOKE_LOOP);
		SetSoundSmokeEnd(SOUND_SMOKE_END);
	}
	
	void ~ToxicSmoke_ColorBase() {}
};

class ToxicSmoke_Green extends ToxicSmoke_ColorBase
{
	void ToxicSmoke_Green()
	{
		SetParticleSmokeStart(ParticleList.GRENADE_M18_GREEN_START);
		SetParticleSmokeLoop(ParticleList.GRENADE_M18_GREEN_LOOP);
		SetParticleSmokeEnd(ParticleList.GRENADE_M18_GREEN_END);
	}
}

class ToxicSmoke_Red extends ToxicSmoke_ColorBase
{
	void ToxicSmoke_Red()
	{
		SetParticleSmokeStart(ParticleList.GRENADE_M18_RED_START);
		SetParticleSmokeLoop(ParticleList.GRENADE_M18_RED_LOOP);
		SetParticleSmokeEnd(ParticleList.GRENADE_M18_RED_START);
	}
}
