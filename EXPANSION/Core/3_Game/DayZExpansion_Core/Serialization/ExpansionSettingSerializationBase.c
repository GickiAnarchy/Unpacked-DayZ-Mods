/**
 * ExpansionSettingSerializationBase.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionSettingSerializationBase
{
	string m_Variable;
	string m_Name;

	string m_DetailLabel;
	string m_DetailContent;

	Class m_Instance;

	Class m_ActualInstance;
	string m_ActualVariable;

	Managed m_WidgetHandle;

	bool m_IsTempSet;

	void SetFromTemp()
	{
		ResetTemp();
	}

	void ResetTemp()
	{
		m_IsTempSet = false;
	}

	bool IsTempSet()
	{
		return m_IsTempSet;
	}

	protected bool FindClassInstanceAndVariable()
	{
		array<string> arr();
		m_Variable.Split( ".", arr );

		m_ActualInstance = m_Instance;

		for ( int i = 0; i < arr.Count() - 1; ++i )
		{
			EnScript.GetClassVar( m_ActualInstance, arr[i], 0, m_ActualInstance );

			if ( m_ActualInstance == NULL )
				return false;
		}

		m_ActualVariable = arr[arr.Count() - 1];

		return true;
	}
};