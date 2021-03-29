 /**
 * ExpansionActionDestroyFlag.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionActionDestroyFlagCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.BASEBUILDING_DECONSTRUCT_MEDIUM);
	}
};

class ExpansionActionDestroyFlag: ActionContinuousBase
{
	float m_DamageAmount;
	string m_SlotName;
	
	void ExpansionActionDestroyFlag()
	{
		m_CallbackClass = ExpansionActionDestroyFlagCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		
		m_DamageAmount = 2;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.BASEBUILDING );
	}
		
	override string GetText()
	{
		return "#destroy" + " " + "#STR_CfgVehicles_Flag_Base0";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( !GetExpansionSettings().GetBaseBuilding().SimpleTerritory || !GetExpansionSettings().GetBaseBuilding().AutomaticFlagOnCreation )
			return false;

		Object targetObject = target.GetObject();
		
		if ( targetObject && targetObject.CanUseConstruction() )
		{
			BaseBuildingBase base_building = BaseBuildingBase.Cast( targetObject );

			float state = base_building.GetAnimationPhase("flag_mast");

			//! If the flag exists, allow the destruction of it
			if ( base_building.FindAttachmentBySlotName( "Material_FPole_Flag" ) && state >= 0.01 )
			{
				return true;
			}
		}

		return false;
	}
		
	override void OnFinishProgressServer( ActionData action_data )
	{	
		BaseBuildingBase base_building = BaseBuildingBase.Cast( action_data.m_Target.GetObject() );
		Flag_Base flag = Flag_Base.Cast( base_building.FindAttachmentBySlotName( "Material_FPole_Flag" ) );
		
		if ( flag )
			flag.Delete();
		
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
}