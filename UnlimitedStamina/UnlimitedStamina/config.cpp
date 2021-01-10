// #include "BIS_AddonInfo.hpp"
class CfgMods
{
	class UnlimitedStamina
	{
	    dir = "MOVUnlimitedStamina";
	    picture = "";
	    action = "";
	    hideName = 1;
	    hidePicture = 1;
	    name = "Unlimited Stamina";
	    credits = "CAMINOonPC";
	    author = "CAMINOonPC";
	    authorID = "0";
	    version = "1.0";
	    extra = 0;
	    type = "mod";

	    dependencies[] = {"World","Mission"};

	    class defs
	    {
	        class worldScriptModule
            {
                value = "";
                files[] = {"UnlimitedStamina/4_World"};
            };
			class missionScriptModule
			{
				value = "";
				files[] = {"UnlimitedStamina/5_Mission"};
			};
        };
    };
};
class CfgPatches
{
	class UnlimitedStaminaScipts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={};
	};
};