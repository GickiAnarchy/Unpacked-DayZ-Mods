/**
 * ExpansionBikeController.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

/**@class		ExpansionBikeController
 * @brief		Handles input controls for bikes
 */
class ExpansionBikeController: ExpansionVehicleController
{
	private int m_Gear;

	private float m_Forward;
	private float m_Backward;

	private float m_Gentle;
	private float m_Turbo;

	private float m_TurnLeft;
	private float m_TurnRight;

	private ExpansionVehicleBikeBase m_Bike;

	void ExpansionBikeController( EntityAI vehicle )
	{
		Class.CastTo( m_Bike, vehicle );
	}
	
	void SetGear( int gear )
	{
		m_Gear = gear;
	}

	int GetGear()
	{
		return m_Gear;
	}

	void SetForward( float forward, float backward, float gentle = 0, float turbo = 0 )
	{
		m_Forward = forward;
		m_Backward = backward;
		m_Gentle = gentle;
		m_Turbo = turbo;
	}

	float GetForward()
	{
		return m_Forward;
	}

	float GetBackward()
	{
		return m_Backward;
	}

	float GetGentle()
	{
		return m_Gentle;
	}

	float GetTurbo()
	{
		return m_Turbo;
	}

	void SetTurn( float left, float right, float value )
	{
		m_TurnLeft = left;
		m_TurnRight = right;
	}

	float GetTurnLeft()
	{
		return m_TurnLeft;
	}

	float GetTurnRight()
	{
		return m_TurnRight;
	}

	protected override void OnUpdate()
	{
		super.OnUpdate();
		
		bool gear_up_press;
		bool gear_down_press;
		
		GetInputPress( "UAExpansionBikeGearUp", gear_up_press );
		GetInputPress( "UAExpansionBikeGearDown", gear_down_press );

		int gear = m_Gear;
		
		if ( gear_up_press )
			m_Gear += 1;
		if ( gear_down_press )
			m_Gear -= 1;
		
		if ( m_Gear < 0 )
			m_Gear = 0;
		else if ( m_Gear >= m_Bike.GetGearsCount() - 1 )
			m_Gear = m_Bike.GetGearsCount() - 1;

		if ( gear != m_Gear )
		{
			m_ECommand.SignalGearChange();
		}
		
		GetInputValue( "UAExpansionBikeMoveForward", m_Forward );
		GetInputValue( "UAExpansionBikeMoveBackward", m_Backward );
		GetInputValue( "UAExpansionBikeRotateLeft", m_TurnLeft );
		GetInputValue( "UAExpansionBikeRotateRight", m_TurnRight );
		GetInputValue( "UAExpansionBikeGentle", m_Gentle );
		GetInputValue( "UAExpansionBikeTurbo", m_Turbo );
	}

	protected override void OnReset()
	{
		super.OnReset();

		m_Gear = 1;
		m_Forward = 0;
		m_Backward = 0;
		m_TurnLeft = 0;
		m_TurnRight = 0;
		m_Gentle = 0;
		m_Turbo = 0;
	}

	protected override void OnNetworkSend( ref ParamsWriteContext ctx )
	{
		ctx.Write( m_Gear );

		ctx.Write( m_Forward );
		ctx.Write( m_Backward );

		ctx.Write( m_Gentle );
		ctx.Write( m_Turbo );

		ctx.Write( m_TurnLeft );
		ctx.Write( m_TurnRight );
	}

	protected override bool OnNetworkRecieve( ref ParamsReadContext ctx )
	{
		ctx.Read( m_Gear );

		ctx.Read( m_Forward );
		ctx.Read( m_Backward );
		
		ctx.Read( m_Gentle );
		ctx.Read( m_Turbo );

		ctx.Read( m_TurnLeft );
		ctx.Read( m_TurnRight );

		return true;
	}
}