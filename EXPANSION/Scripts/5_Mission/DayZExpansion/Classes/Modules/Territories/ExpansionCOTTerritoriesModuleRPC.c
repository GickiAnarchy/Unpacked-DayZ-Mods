/**
 * ExpansionCOTTerritoriesModuleRPC.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

enum ExpansionCOTTerritoriesModuleRPC
{
	INVALID = 20450,
	DeleteObject,
	RequestServerTerritories,
	SendServerTerritories,
	RequestTerritoryObjects,
	SendTerritoryObjects,
	TeleportToTerritory,
	RequestUpdateObjectData,
	SendObjectData,
	COUNT
}