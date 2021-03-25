enum WTF69SymptomIDs
{
	SYMPTOM_BLOODVOMIT = 69,
	SYMPTOM_WTF69 = 68,
	
};

modded class SymptomManager
{
	override void Init()
	{
		super.Init();
		RegisterSymptom(new BloodVomitSymptom);
		RegisterSymptom(new WTF69Symptom);
		
		
	}
	
}