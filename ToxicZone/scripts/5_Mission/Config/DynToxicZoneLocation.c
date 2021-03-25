class DynToxicZoneLocation
{
    string DynToxicZoneStatut;
    float StartX, StartY, EndX, EndY, Radius;
	float Coeff,YtoOrigin,Chance;
	int Speed;
	int norme;
	bool IsOnlyGasMask;
	string ParticleName;
    
    void DynToxicZoneLocation(float chance,bool isonlygasmask,string particlename, string dyntoxiczonestatut, int speed, float startx, float starty, float endx, float endy, float radius)
	{
		Chance=chance;
		ParticleName=particlename;
		IsOnlyGasMask=isonlygasmask;
        DynToxicZoneStatut = dyntoxiczonestatut;
		Speed=speed;
        StartX = startx;
        StartY = starty;
		EndX = endx;
		EndY = endy;
        Radius = radius;
		Coeff=(EndY-StartY)/(EndX-StartX);
		YtoOrigin=StartY-Coeff*StartX;
		norme = DoNorm();
    }
	
	int DoNorm()
	{
		private int X,Y;
		if(StartX>EndX)
		{
			X=StartX-EndX;
		}else X=EndX-StartX;
		if(StartY>EndY)
		{
			X=StartY-EndY;
		}else Y=EndY-StartY;
		return Math.Sqrt(Math.Pow(X,2)+Math.Pow(Y,2));
	}
	
}