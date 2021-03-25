class CrateLocation
{
    string Name;
    vector POS, ORI;
    
    void CrateLocation(string name, vector pos, vector ori)
	{
        Name = name;
        POS = pos;
        ORI = ori;
    }
}