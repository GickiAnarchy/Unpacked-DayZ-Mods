class CfgPatches
{
	class DP_scripts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"JM_CF_Scripts"
		};
	};
};
class CfgMods
{
	class DrugsPLUS
	{
		dir="DrugsPLUS";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="DrugsPLUS";
		credits="IceBlade";
		author="IceBlade";
		authorID="0";
		version="2.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"DrugsPLUS/scripts/3_game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"DrugsPLUS/scripts/4_world"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"DrugsPLUS/scripts/5_mission"
				};
			};
		};
	};
};

class CfgSoundShaders
{
    class Custom_SoundShader_Base
    {
        range = 30;
    };

    class LoudSniffing_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
        	{
        		"drugsPLUS\sounds\cocaine\longsniff.ogg", 
        		1
        	}
        };
        volume = 1;
    };

    class QuietSniffing_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
        	{
        		"drugsPLUS\sounds\cocaine\shortsniff.ogg", 
        		1
        	}
        };
        volume = 1;
    };

    class Eating_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "drugsPLUS\sounds\shroom\core\eating.ogg", 
                1
            }
        };
        volume = 1;
    };

    class FirstYawn_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "drugsPLUS\sounds\shroom\core\firstyawn.ogg", 
                1
            }
        };
        volume = 1;
    };

    class SecondYawn_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "drugsPLUS\sounds\shroom\core\secondyawn.ogg", 
                1
            }
        };
        volume = 1;
    };

    // Tripping sounds shrooms.
    class ScaryOne_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "drugsPLUS\sounds\shroom\scary\scaryone.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    class ScaryTwo_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "drugsPLUS\sounds\shroom\scary\scarytwo.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    class ScaryThree_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "drugsPLUS\sounds\shroom\scary\scarythree.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    class ScaryFour_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "drugsPLUS\sounds\shroom\scary\scaryfour.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    class ScaryFive_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "drugsPLUS\sounds\shroom\scary\scaryfive.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    class ScarySix_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "drugsPLUS\sounds\shroom\scary\scarysix.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    class ScarySeven_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "drugsPLUS\sounds\shroom\scary\scaryseven.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    // Random Sounds for Shrooms.
    class RandomOne_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "drugsPLUS\sounds\shroom\random\randomone.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    class RandomTwo_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "drugsPLUS\sounds\shroom\random\randomtwo.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    class RandomThree_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "drugsPLUS\sounds\shroom\random\randomthree.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    class RandomFour_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "dz\sounds\characters\voice\female\laugh_5.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    class RandomFive_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "dz\sounds\characters\voice\female\sneez_2.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    class RandomSix_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "dz\sounds\weapons\grenades\grenade\grenade_dist_explosion_02.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    class RandomSeven_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "dz\sounds\weapons\grenades\grenade\grenade_dist_explosion_02.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    class RandomEight_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "dz\sounds\weapons\firearms\m4a1\m4_dist_shot_02.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    // Ambients for shrooms.
    class AmbientOne_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "dz\sounds\environment\weather\thunders\thunderheavy_far_1.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    class AmbientTwo_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "dz\sounds\environment\weather\rains\rainlargeevergreen_3.ogg", 
                1
            }
        };
        volume = 0.1;
    };


    class AmbientThree_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "dz\sounds\environment\insects\flies.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    class AmbientFour_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "dz\sounds\ai\animals\wolf\howls\howls_1.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    class AmbientFive_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "dz\sounds\ai\animals\wolf\howls\howls_3.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    class AmbientSix_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "dz\sounds\ai\infected\voicefx\zmbm_fat_calltoarmsshort_2.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    // Heroin Sounds.
    class Syringe_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "drugsPLUS\sounds\heroin\syringe.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    // booze Sounds.
    class Burp_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "drugsPLUS\sounds\drinks\burp.ogg", 
                1
            }
        };
        volume = 0.1;
    };

    class Hiccup_SoundShader : Custom_SoundShader_Base
    {
        samples[] =
        {
            {
                "drugsPLUS\sounds\drinks\hiccup.ogg", 
                1
            }
        };
        volume = 0.1;
    };
};

class CfgSoundSets
{
    class Custom_SoundSet_Base
    {
        sound3DProcessingType = "character3DProcessingType";
        volumeCurve = "characterAttenuationCurve";
        spatial = 1;
        doppler = 0;
        loop = 0;
    };

    class LoudSniffing_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "LoudSniffing_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 1;
    };

    class QuietSniffing_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "QuietSniffing_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 1;
    };

    class Eating_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "Eating_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 1;
    };

    class FirstYawn_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "FirstYawn_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 1;
    };

    class SecondYawn_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "SecondYawn_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 1;
    };

    // Trip Sound Sets.
    class ScaryOne_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "ScaryOne_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    class ScaryTwo_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "ScaryTwo_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    class ScaryThree_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "ScaryThree_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    class ScaryFour_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "ScaryFour_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    class ScaryFive_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "ScaryFive_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    class ScarySix_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "ScarySix_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    class ScarySeven_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "ScarySeven_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    // Random sounds for shrooms.
    class RandomOne_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "RandomOne_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    class RandomTwo_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "RandomTwo_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    class RandomThree_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "RandomThree_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    class RandomFour_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "RandomFour_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    // Ambients for shrooms.
    class AmbientOne_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "AmbientOne_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    class AmbientTwo_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "AmbientTwo_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    class AmbientThree_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "AmbientThree_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    class AmbientFour_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "AmbientFour_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    class AmbientFive_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "AmbientFive_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    class AmbientSix_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "AmbientSix_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    class RandomFive_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "RandomFive_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    class RandomSix_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "RandomSix_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    class RandomSeven_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "RandomSeven_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    class RandomEight_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "RandomEight_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    // Heroin Sounds.
    class Syringe_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "Syringe_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    // booze Sounds.
    class Burp_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "Burp_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 0.1;
    };

    class Hiccup_SoundSet : Custom_SoundSet_Base
    {
        soundShaders[] =
        {
            "Hiccup_SoundShader"
        };
        
        frequencyRandomizer = 0;
        volumeRandomizer = 0;
        volume = 1;
    };
};