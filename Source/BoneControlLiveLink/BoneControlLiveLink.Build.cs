using UnrealBuildTool;

public class BoneControlLiveLink : ModuleRules
{
	public BoneControlLiveLink(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;


		PublicIncludePaths.AddRange(
			new string[]
			{
                "BoneControlLiveLink/Public"
            });

		PrivateIncludePaths.AddRange(
			new string[]
			{
                "BoneControlLiveLink/Private"
            });

		PublicDependencyModuleNames.AddRange(new string[] {
			"AIModule",/*
			"AnimGraph",*/
			"AnimGraphRuntime",
			/*"BlueprintGraph",
			*/"Core",
			"CoreUObject",
			"Engine",
			"Foliage",
			"GameplayTasks",
			"HeadMountedDisplay",
			"InputCore",
			"Json",
			"JsonUtilities",
			"Landscape",
			"LiveLink",
			"LiveLinkInterface",
			"Messaging",
			"Networking",
			"Slate",
			"SlateCore",
			"Sockets",
			/*"UnrealEd",*/
            /*"BoneControlLiveLinkEditor"
*/
        });


	}
}
