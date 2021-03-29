/**
 * Land_House_2W03.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class Land_House_2W03 extends BuildingSuper
{
	override bool HasInterior()
	{
		return true;
	}
	
	override void SpawnInterior()
	{
		//if ( Math.RandomFloatInclusive(0, 1) <= Math.RandomFloatInclusive(0, 1) )
		//{
			SpawnInteriorObject( "bldr_almara", "-2.350000 -5.550217 3.705331", "0.000000 0.000000 0.000000" );
		//} else {
		//	SpawnInteriorObject( "bldr_almara_open", "-2.300000 -5.550201 3.655330", "0.000000 0.000000 0.000000" );
		//}
		SpawnInteriorObject( "ExpansionPropPetCarrier", "-2.561551 -3.150002 3.687111", "11.000006 0.000000 0.000000", -1 );
		SpawnInteriorObject( "bldr_couch_dz", "-1.365873 -5.531960 1.799571", "87.000000 0.000000 0.000000", -1 );
		SpawnInteriorObject( "bldr_luxury_lamp", "0.247552 -2.749863 -0.720000", "179.990005 0.000000 0.000000" );
		SpawnInteriorObject( "bldr_switch_lights", "-0.846532 -4.181877 -0.865000", "-90.000000 0.000000 0.000000" );
		SpawnInteriorObject( "bldr_box_c_multi", "-5.029331 -0.751373 5.036469", "90.000038 0.000000 0.000000", -1 );
		SpawnInteriorObject( "bldr_picture_a_03", "-1.602190 0.198685 6.860000", "179.990005 0.000000 0.000000" );
		SpawnInteriorObject( "ExpansionPropChair1", "-1.619051 -0.140999 3.680000", "90.000000 0.000000 18.000006" );
		SpawnInteriorObject( "bldr_postel_manz_kov", "-9.091600 -0.901382 2.782772", "90.000000 0.000000 0.000000" );
		SpawnInteriorObject( "bldr_kitchen_unit_a_dz", "-1.600000 -0.830002 0.939972", "90.000015 0.000000 0.000000" );
		SpawnInteriorObject( "bldr_case_sink_a", "-1.667372 -0.701370 2.017788", "0.000000 0.000000 0.000000" );
		SpawnInteriorObject( "bldr_sofa_leather_old", "-4.686828 -0.355003 -0.062829", "-95.000023 0.000000 0.000000" );
		SpawnInteriorObject( "bldr_table_drawer", "-7.113824 -0.773003 -0.048342", "93.000031 0.000000 0.000000" );
		SpawnInteriorObject( "bldr_tv_a", "-7.156184 -0.086998 -0.040952", "-89.000000 0.000000 0.000000" );
		SpawnInteriorObject( "bldr_carpet_2_dz", "-5.945701 -0.673897 -0.092583", "166.999924 0.000000 0.000000", 0.75 );
		SpawnInteriorObject( "bldr_radio_b", "-7.687294 0.014999 4.315191", "178.000000 0.000000 0.000000" );
		SpawnInteriorObject( "bldr_switch_lights", "-3.722701 0.598709 3.170000", "90.000000 0.000000 0.000000" );
		SpawnInteriorObject( "bldr_washing_machine", "-3.180309 -0.799927 -0.686822", "179.000000 0.000000 0.000000" );
		SpawnInteriorObject( "ExpansionPropBin", "-3.877486 -0.559998 -0.675407", "85.000008 0.000000 0.000000" );

		//if ( Math.RandomFloatInclusive(0, 1) <= Math.RandomFloatInclusive(0, 1) )
		//{
			SpawnInteriorObject( "bldr_plnt_c_leafs_spread", "-1.565978 -5.525002 -0.178666", "0.000000 -0.000009 0.000000" );
			SpawnInteriorObject( "bldr_plnt_c_leafs_spread", "-2.320718 -5.525002 -0.312360", "131.009598 0.000000 0.000000" );
			SpawnInteriorObject( "bldr_plnt_c_leafs_spread", "-3.040701 -5.525002 -0.133488", "91.791710 0.000000 0.000000" );
			SpawnInteriorObject( "bldr_plnt_c_leafs_spread", "-3.278727 -5.525002 0.685549", "62.000072 -0.000009 0.000000" );
			SpawnInteriorObject( "bldr_plnt_c_leafs_spread", "0.398501 -0.724991 6.328323", "0.000000 0.000000 0.000000" );
			SpawnInteriorObject( "bldr_plnt_c_leafs_spread", "-0.609372 -0.724998 6.083379", "153.000046 0.000000 0.000000" );
			SpawnInteriorObject( "bldr_plnt_c_leafs_spread", "-1.951498 -0.724991 6.477738", "-136.972046 0.000000 0.000000" );
			SpawnInteriorObject( "bldr_plnt_c_leafs_spread", "-3.224883 -0.724998 6.271838", "-45.963326 1.679372 1.252985" );
			SpawnInteriorObject( "bldr_plnt_c_leafs_spread", "-4.533145 -0.724403 6.260506", "0.036726 1.679372 1.252985" );
			SpawnInteriorObject( "bldr_plnt_c_leafs_spread", "-7.162193 -0.724991 -0.382077", "0.000000 0.000000 0.000000" );
			SpawnInteriorObject( "bldr_plnt_c_leafs_spread", "-8.149429 -0.724991 -0.311638", "51.054951 0.000000 0.000000" );
		//}
	}

	override bool HasIvys()
	{
		return true;
	}
	
	override void SpawnIvys()
	{
		SpawnInteriorIvy( "bldr_plnt_ivy_N", "9.795703 2.300140 -1.724508", "0.000000 -87.000038 0.000000" );
		SpawnInteriorIvy( "bldr_plnt_ivy_T", "9.088506 1.550095 -1.624508", "-90.000015 0.000000 -90.000038" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_J", "8.145607 -0.900055 -1.524508", "-178.999924 0.000000 -23.000006" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_C", "8.783590 -5.100067 -1.524508", "-179.999985 0.000000 0.000000" );
		SpawnInteriorIvy( "bldr_plnt_ivy_O", "8.518077 -3.900238 -1.574508", "91.999969 -89.000046 89.999992" );
		SpawnInteriorIvy( "bldr_plnt_ivy_I", "3.332874 -5.250320 -1.624500", "179.999985 -89.000046 179.999985" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_B", "3.363040 -4.800293 -1.524508", "179.999985 0.000000 -68.999992" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_C", "3.517540 -5.350327 -1.524508", "-179.999985 0.000000 -71.000038" );
		SpawnInteriorIvy( "bldr_plnt_ivy_special_A", "1.127489 -0.850052 -1.424819", "90.000038 0.000000 0.000000" );
		SpawnInteriorIvy( "bldr_plnt_ivy_M", "-1.204145 2.150131 -1.674819", "-0.000005 -87.000038 -0.000005" );
		SpawnInteriorIvy( "bldr_plnt_ivy_R", "1.587622 1.200073 -1.624508", "1.999994 -89.000046 -0.000005" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_G", "1.928850 -0.250015 -1.524508", "0.000000 0.000000 91.000038" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_F", "1.997854 -0.700043 -1.520000", "0.000000 0.000000 85.000008" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_C", "1.302991 -0.850052 -1.524819", "-179.999985 0.000000 81.999992" );
		SpawnInteriorIvy( "bldr_plnt_ivy_roof_A", "-2.522586 2.550156 -2.112922", "-0.000009 -89.000046 -0.000009" );
		SpawnInteriorIvy( "bldr_plnt_ivy_B", "0.046462 -2.669823 -2.351164", "-80.000008 19.000000 179.999985" );
		SpawnInteriorIvy( "bldr_plnt_ivy_N", "-9.843571 -5.350327 -1.674509", "-0.000005 87.000038 -179.999985" );
		SpawnInteriorIvy( "bldr_plnt_ivy_special_A", "-8.209624 1.350082 -1.474819", "90.000000 10.000000 2.000000" );
		SpawnInteriorIvy( "bldr_plnt_ivy_L", "-5.444373 1.900116 -1.624818", "-0.000005 -89.000046 -0.000005" );
		SpawnInteriorIvy( "bldr_plnt_ivy_M", "0.313056 6.050369 2.703959", "179.999985 -50.000015 179.999985" );
		SpawnInteriorIvy( "bldr_plnt_ivy_I", "-3.856619 6.049042 2.718060", "-57.999981 21.999994 149.000076" );
		SpawnInteriorIvy( "bldr_plnt_ivy_L", "4.453686 5.399963 1.863604", "-130.000031 -26.999983 149.999985" );
		SpawnInteriorIvy( "bldr_plnt_ivy_R", "5.098592 4.355782 0.495181", "-97.000137 -6.000000 146.000000" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_G", "-9.392963 -2.550156 -1.510000", "0.024030 0.000000 6.000008" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_C", "-9.229526 -5.000305 -1.500000", "-179.999985 0.000000 -6.000001" );
		SpawnInteriorIvy( "bldr_plnt_ivy_H", "-4.918296 -1.869080 -1.600403", "-90.000038 41.999996 90.000000" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_C", "-6.095337 -6.450394 -1.500000", "-179.999985 0.000000 0.000000" );
		SpawnInteriorIvy( "bldr_plnt_ivy_N", "10.074900 -5.800354 -1.514679", "-89.999992 88.000015 179.999985" );
		SpawnInteriorIvy( "bldr_plnt_ivy_M", "10.024900 2.050125 1.754317", "-90.000015 -82.999992 -0.000009" );
		SpawnInteriorIvy( "bldr_plnt_ivy_R", "9.974899 -1.500092 2.436103", "179.999985 0.000000 90.000038" );
		SpawnInteriorIvy( "bldr_plnt_ivy_H", "10.024899 -4.200256 6.014517", "179.999985 -21.999985 89.999969" );
		SpawnInteriorIvy( "bldr_plnt_ivy_M", "9.974899 -5.350327 2.969738", "-89.999969 86.000015 179.999985" );
		SpawnInteriorIvy( "bldr_plnt_ivy_G", "10.074898 -1.450089 4.006066", "0.000000 0.000000 90.000000" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_C", "9.940000 -5.950363 -0.680727", "-89.999969 -0.200000 5.000001" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_B", "9.910000 -0.900055 1.689043", "90.000038 0.000000 23.000013" );
		SpawnInteriorIvy( "bldr_plnt_ivy_H", "5.391165 5.209961 3.048910", "0.000000 -1.000000 -148.938400" );
		SpawnInteriorIvy( "bldr_plnt_ivy_M", "5.901872 4.825554 4.534941", "-52.000008 -34.999992 -153.000031" );
		SpawnInteriorIvy( "bldr_plnt_ivy_M", "0.954117 6.061150 3.084268", "0.000000 -49.000008 -179.999985" );
		SpawnInteriorIvy( "bldr_plnt_ivy_H", "-4.964212 4.776634 4.773229", "25.000116 -37.000008 166.000015" );
		SpawnInteriorIvy( "bldr_plnt_ivy_K", "-2.570354 6.069839 3.129530", "0.000000 -39.999985 0.000000" );
		SpawnInteriorIvy( "bldr_plnt_ivy_G", "-6.322302 4.677834 3.045574", "17.000011 15.000002 -26.774605" );
		SpawnInteriorIvy( "bldr_plnt_ivy_N", "-9.965102 2.300140 -1.498841", "-90.000122 -89.000046 179.999985" );
		SpawnInteriorIvy( "bldr_plnt_ivy_N", "-9.965102 -5.600342 -1.459938", "2.000000 0.000000 90.000000" );
		SpawnInteriorIvy( "bldr_plnt_ivy_N", "-10.015102 -1.550095 1.361202", "90.000000 -89.000046 -0.000009" );
		SpawnInteriorIvy( "bldr_plnt_ivy_R", "-9.965102 -1.550095 3.414384", "0.000000 0.000000 93.000031" );
		SpawnInteriorIvy( "bldr_plnt_ivy_special_A", "-9.815101 1.300079 2.120183", "-179.999985 10.000000 2.000000" );
		SpawnInteriorIvy( "bldr_plnt_ivy_K", "-9.965101 2.250137 5.537392", "89.999954 -83.000015 -0.000009" );
		SpawnInteriorIvy( "bldr_plnt_ivy_F", "-9.915102 -4.250259 5.862661", "179.999985 11.000000 -89.999954" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_C", "-9.815102 -2.700165 6.556256", "-90.000000 0.000000 0.000000" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_C", "-9.815102 -5.450027 5.816029", "-90.000000 0.000000 -7.000006" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_C", "-9.815102 -1.350082 3.921703", "90.000000 0.000000 89.000046" );
		SpawnInteriorIvy( "bldr_plnt_ivy_N", "-9.838178 2.250137 7.475183", "1.000000 -89.000046 179.999954" );
		SpawnInteriorIvy( "bldr_plnt_ivy_M", "-2.696145 2.100128 7.419182", "179.999985 -89.000046 -0.000036" );
		SpawnInteriorIvy( "bldr_plnt_ivy_special_A", "-2.296325 -0.800049 7.219182", "-90.000000 0.000000 0.000000" );
		SpawnInteriorIvy( "bldr_plnt_ivy_special_B", "-5.582883 0.200012 7.369182", "-90.000000 0.000000 0.000000" );
		SpawnInteriorIvy( "bldr_plnt_ivy_special_B", "-1.385958 -2.700165 7.225182", "-90.000015 0.000000 0.000000" );
		SpawnInteriorIvy( "bldr_plnt_ivy_H", "1.108575 1.312096 7.459309", "-89.999969 -61.000015 -89.999992" );
		SpawnInteriorIvy( "bldr_plnt_ivy_M", "2.161586 -1.750107 7.469100", "179.999985 -89.000046 0.000009" );
		SpawnInteriorIvy( "bldr_plnt_ivy_R", "3.989918 -1.400085 7.375182", "90.000000 0.000000 90.000000" );
		SpawnInteriorIvy( "bldr_plnt_ivy_F", "9.227154 0.550034 7.425182", "90.000000 0.000000 90.000000" );
		SpawnInteriorIvy( "bldr_plnt_ivy_N", "9.889800 -5.450333 7.375182", "-1.000000 89.000046 -0.000009" );
		SpawnInteriorIvy( "bldr_plnt_ivy_T", "-1.331300 0.250015 -1.874819", "0.000000 -37.999996 -90.000000" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_C", "9.198196 -5.150314 7.299000", "0.000000 0.000000 0.000000" );
		SpawnInteriorIvy( "bldr_plnt_ivy_I", "-4.389064 -5.450333 7.375181", "-179.999985 -89.000046 -0.000005" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_G", "-9.257981 0.900055 7.369182", "-175.999969 0.000000 -179.999985" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_I", "6.174156 -4.150253 7.325182", "0.000000 0.000000 -19.000006" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_H", "1.483491 -3.199890 7.320000", "0.000000 0.000000 24.000019" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_D", "-1.482187 -1.700104 7.319181", "0.000000 0.000000 89.000038" );
		SpawnInteriorIvy( "bldr_plnt_ivy_dry_B", "-8.966343 -5.600342 7.325182", "0.000000 0.000000 0.000000" );
	}

}