/**
 * ExpansionSettingSerializationInt.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionSettingSerializationInt: ExpansionSettingSerializationBase
{
	int m_TempValue;

	void SetTempValue( int value )
	{
		m_TempValue = value;
		m_IsTempSet = true;
	}

	override void SetFromTemp()
	{
		super.SetFromTemp();
		
		SetValue( m_TempValue );
	}

	int GetValue()
	{
		int value;

		FindClassInstanceAndVariable();

		EnScript.GetClassVar( m_ActualInstance, m_ActualVariable, 0, value );

		return value;
	}

	void SetValue( int value )
	{
		FindClassInstanceAndVariable();

		EnScript.SetClassVar( m_ActualInstance, m_ActualVariable, 0, value );
		
		GetGame().GameScript.Call( m_Instance, "OnSettingsUpdated", new Param2< typename, ExpansionSettingSerializationBase >( Type(), this ) );
	}
};