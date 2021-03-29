/**
 * Hatchback_02.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class Hatchback_02
{
	override bool IsVitalCarBattery()
	{
		return true;
	}
	override string ExpansionGetWheelType(int slot_id)
	{
		return "Hatchback_02_Wheel";
	}
	override bool LeavingSeatDoesAttachment( int posIdx )
	{
		// @CAMINOonPC#6971 Never implemented this after being told to for the past 3 months
		return false;
	}
}