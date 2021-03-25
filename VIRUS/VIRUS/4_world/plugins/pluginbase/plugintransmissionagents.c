modded class PluginTransmissionAgents extends PluginBase
{
	//static ref map<int, ref AgentBase> m_AgentList =  new map<int, ref AgentBase>;
	//ref map<int, string> m_SimpleAgentList = new map<int, string>;
	//bool m_IsConstructed = false;
	
	void PluginTransmissionAgents()
	{
		//add new agents here
		m_AgentList.Insert(WTF69Agents.WTF69VIRUS, new WTF69VirusAgent);
			
	}


};