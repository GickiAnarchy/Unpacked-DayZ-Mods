class ToxicM18SmokeGrenade_ColorBase extends ToxicSmoke
{
	const string SOUND_SMOKE_START = "SmokegGrenades_M18_start_loop_SoundSet";
	const string SOUND_SMOKE_LOOP = "SmokegGrenades_M18_active_loop_SoundSet";
	const string SOUND_SMOKE_END = "SmokegGrenades_M18_end_loop_SoundSet";

	void ToxicM18SmokeGrenade_ColorBase()
	{
		SetAmmoType("");
		SetFuseDelay(2);
		SetSoundSmokeStart(SOUND_SMOKE_START);
		SetSoundSmokeLoop(SOUND_SMOKE_LOOP);
		SetSoundSmokeEnd(SOUND_SMOKE_END);
	}
	
	void ~ToxicM18SmokeGrenade_ColorBase() {}
}

class ToxicM18SmokeGrenade_Red extends ToxicM18SmokeGrenade_ColorBase
{
	void ToxicM18SmokeGrenade_Red()
	{
		SetParticleSmokeStart(ParticleList.GRENADE_M18_RED_START);
		SetParticleSmokeLoop(ParticleList.GRENADE_M18_RED_LOOP);
		SetParticleSmokeEnd(ParticleList.GRENADE_M18_RED_END);
	}
}

class ToxicM18SmokeGrenade_Green extends ToxicM18SmokeGrenade_ColorBase
{
	void ToxicM18SmokeGrenade_Green()
	{
		SetParticleSmokeStart(ParticleList.GRENADE_M18_GREEN_START);
		SetParticleSmokeLoop(ParticleList.GRENADE_M18_GREEN_LOOP);
		SetParticleSmokeEnd(ParticleList.GRENADE_M18_GREEN_END);
	}
}

class ToxicM18SmokeGrenade_Purple extends ToxicM18SmokeGrenade_ColorBase
{
	void ToxicM18SmokeGrenade_Purple()
	{
		SetParticleSmokeStart(ParticleList.GRENADE_M18_PURPLE_START);
		SetParticleSmokeLoop(ParticleList.GRENADE_M18_PURPLE_LOOP);
		SetParticleSmokeEnd(ParticleList.GRENADE_M18_PURPLE_END);
	}
}

class ToxicM18SmokeGrenade_Yellow extends ToxicM18SmokeGrenade_ColorBase
{
	void ToxicM18SmokeGrenade_Yellow()
	{
		SetParticleSmokeStart(ParticleList.GRENADE_M18_YELLOW_START);
		SetParticleSmokeLoop(ParticleList.GRENADE_M18_YELLOW_LOOP);
		SetParticleSmokeEnd(ParticleList.GRENADE_M18_YELLOW_END);
	}
}

class ToxicM18SmokeGrenade_White extends ToxicM18SmokeGrenade_ColorBase
{
	void ToxicM18SmokeGrenade_White()
	{
		SetParticleSmokeStart(ParticleList.GRENADE_M18_WHITE_START);
		SetParticleSmokeLoop(ParticleList.GRENADE_M18_WHITE_LOOP);
		SetParticleSmokeEnd(ParticleList.GRENADE_M18_WHITE_END);
	}
}


