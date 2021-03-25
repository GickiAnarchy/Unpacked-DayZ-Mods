class LootConfig
{
	string LootName;
	float  ProbToSpawn;
	ref array<ref AttachmentConfig> AttachmentsToLoot;
	//AttachmentsToItem = NULL;
	
	
	void LootConfig(string lootname, float probtospawn)
	{
		LootName = lootname;
		ProbToSpawn = probtospawn;
		AttachmentsToLoot = new ref array< ref AttachmentConfig>;
	}
	
	void AddAttachmentsToItem(string name, float prob)
	{
		AttachmentsToLoot.Insert(new ref AttachmentConfig(name,prob));
	}
}

class AttachmentConfig
{
	string AttachName;
	float  ProbAttachToSpawn;
	
	void  AttachmentConfig(string attachname, float probattachtospawn)
	{
		AttachName = attachname;
		ProbAttachToSpawn = probattachtospawn;
	}
}

class ListLootConfig{
	string Name;
	ref array<ref LootConfig> Loots;
	
	void ListLootConfig(string name)
	{
		Loots= new ref array<ref LootConfig>;
		Name=name;
	}
	
	void AddLootConfig(string lootname, float probtospawn)
	{
		Loots.Insert(new ref LootConfig(lootname,probtospawn));
	}
}