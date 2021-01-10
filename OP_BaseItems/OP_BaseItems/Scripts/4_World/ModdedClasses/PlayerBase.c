modded class PlayerBase extends ManBase
{

	void SetActions(out TInputActionMap InputActionMap)
	{
        super.SetActions(InputActionMap);
        AddAction(ActionTurnOnLights, InputActionMap);
        AddAction(ActionTurnOffLights, InputActionMap);
    }
};
