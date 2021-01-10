modded class ConstructionActionData
{
	OPLock			 			m_OPLock;
	int 						m_OPDialIndex;


	
	OPLock GetOPLock()
	{
		return m_OPLock;
	}
	void SetOPLock( OPLock op_lock )
	{
		m_OPLock = OPLock.Cast( op_lock );
	}
	
	string OPGetDialNumberText()
	{
		string dial_text;
		
		if ( m_OPLock )
		{
			string combination_text = m_OPLock.GetCombination().ToString();
			
			//insert zeros to dials with 0 value
			int length_diff = m_OPLock.GetLockDigits() - combination_text.Length();
			for ( int i = 0; i < length_diff; ++i )
			{
				combination_text = "0" + combination_text;
			}
			
			//assemble the whole combination with selected part
			for ( int j = 0; j < m_OPLock.GetLockDigits(); ++j )
			{
				if ( j == m_OPLock.GetDialIndex() )
				{
					dial_text += string.Format( "[%1]", combination_text.Get( j ) );
				}
				else
				{
					dial_text += string.Format( " %1 ", combination_text.Get( j ) );
				}
			}
		}

		return dial_text;
	}
}