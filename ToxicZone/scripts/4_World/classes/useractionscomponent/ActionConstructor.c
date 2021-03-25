modded class ActionConstructor
{
#ifndef OLD_ACTIONS
	bool ConstructActions( out array<ref ActionBase> actionsArray, out map<typename, ActionBase> actionNameActionMap )
	{
		TTypenameArray action_array_names = new TTypenameArray;
		RegisterActions(action_array_names);
		Sort(action_array_names,action_array_names.Count());
		
		actionsArray = new array<ref ActionBase>;
		actionNameActionMap = new map<typename, ActionBase>;
		ActionBase new_action;
		
		for(int i = 0; i < action_array_names.Count(); i++)
		{
			new_action = ActionBase.Cast(action_array_names[i].Spawn());
			if(new_action)
			{
				new_action.CreateConditionComponents();
				new_action.SetID(actionsArray.Count());
				actionsArray.Insert(new_action);
				actionNameActionMap.Insert(action_array_names[i], new_action);
			}
		}
		return true;
	}
	
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
	}
	
#else	
	override void ConstructActions(actions)
	{
		super.ConstructActions(out array<ref ActionBase> actions);
	}
#endif
};