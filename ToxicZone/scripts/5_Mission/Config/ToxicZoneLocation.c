class ToxicZoneLocation
{
    string ToxicZoneStatut;
	string ContainerName;
    float X, Y, Radius;
	float X1,Y1,X2,Y2;
	int NumbCratePerTime;
	int  MaxLoot;
	bool IsSquareZone;
	bool IsLootActive;
	bool IsOnlyGasMask;
	ref array<ref CrateLocation> ToxicCratePosition;
	ref array<ref ParticleListe> ParticlesPosition;
	ref array<ref Creature> CreatureList;
    
    void ToxicZoneLocation(int maxloot, bool isquarezone,bool islootactive,bool isonlygasmask,string container_name, int ncpt, string toxiczonestatut, float x, float y, float radius,float x1, float y1, float x2, float y2)
	{
		MaxLoot=maxloot;
		IsOnlyGasMask=isonlygasmask;
		IsSquareZone=isquarezone;
		ContainerName=container_name;
		IsLootActive=islootactive;
		NumbCratePerTime=ncpt;
        ToxicZoneStatut = toxiczonestatut;
        X = x;
        Y = y;
		X1= x1;
		Y1=y1;
		X2=x2;
		Y2=y2;
        Radius = radius;
		ToxicCratePosition = new ref array<ref CrateLocation>;
		ParticlesPosition = new ref array<ref ParticleListe>;
		CreatureList = new ref array<ref Creature>;
    }
	
	void AddCratePosition(string name, vector pos, vector ori)
	{
		ToxicCratePosition.Insert(new ref CrateLocation(name,pos,ori));
	}
	
	void AddParticlePosition(string name, vector pos)
	{
		ParticlesPosition.Insert(new ref ParticleListe(name,pos));
	}
	
	void AddCreatureToList(string name, int max)
	{
		CreatureList.Insert(new ref Creature(name,max));
	}
}

class ParticleListe
{
	string NName;
	vector PPos;

	void ParticleListe(string name, vector pos)
	{
		NName=name;
		PPos=pos;
	}
}