/**
 * ExpansionSettingSerializationToggle.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionSettingSerializationToggle: ExpansionSettingSerializationBase
{
	bool m_TempValue;

	void SetTempValue( bool value )
	{
		m_TempValue = value;
		m_IsTempSet = true;
	}

	override void SetFromTemp()
	{
		super.SetFromTemp();
		
		SetValue( m_TempValue );
	}

	bool GetValue()
	{
		bool value;

		FindClassInstanceAndVariable();

		EnScript.GetClassVar( m_ActualInstance, m_ActualVariable, 0, value );
		
		return value;
	}

	void SetValue( bool value )
	{
		FindClassInstanceAndVariable();

		EnScript.SetClassVar( m_ActualInstance, m_ActualVariable, 0, value );
		
		GetGame().GameScript.Call( m_Instance, "OnSettingsUpdated", new Param2< typename, ExpansionSettingSerializationBase >( Type(), this ) );
	}
};