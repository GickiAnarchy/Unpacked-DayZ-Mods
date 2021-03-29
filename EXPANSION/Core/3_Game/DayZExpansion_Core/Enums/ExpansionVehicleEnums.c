/**
 * ExpansionVehicleRPC.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

enum ExpansionVehicleNetworkMode
{
	SERVER_ONLY,
	PREDICTION,
	CLIENT,
	COUNT
};

enum ExpansionVehicleRPC
{
	INVALID = 20140,
	CrewSync,
	CrewSyncInit,
	RequestCrewSync,
	ClientSync,
	ControllerSync,
	PlayLockSound,
	COUNT
};