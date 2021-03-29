/**
 * JMESPViewType.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class JMESPViewTypeContainer
{
	void JMESPViewTypeContainer()
	{
		Permission = "Item.Container";
		Localisation = "#STR_COT_ESP_MODULE_VIEW_TYPE_Containers";

		MetaType = JMESPMetaContainer;

		Colour = ARGB( 255, 200, 112, 255 );
	}
};