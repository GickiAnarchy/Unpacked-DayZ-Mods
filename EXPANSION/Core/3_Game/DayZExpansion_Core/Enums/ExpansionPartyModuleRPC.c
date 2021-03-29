/**
 * ExpansionPartyModuleRPC.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

enum ExpansionPartyModuleRPC
{
	INVALID = 20020,
	Create,
	Dissolve,
	Leave,
	RemovePlayer,
	UpdateClient,

	CreateMarker,
	UpdateMarker,
	UpdatePositionMarker,
	DeleteMarker,
	
	PromotePlayer,
	DemotePlayer,

	InvitePlayer,
	DeclineInvite,
	AcceptInvite,
	
	SyncPlayersInvites,

	UpdateQuickMarker,
	
	COUNT
};