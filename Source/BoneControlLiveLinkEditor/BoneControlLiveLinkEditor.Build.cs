using UnrealBuildTool;

public class BoneControlLiveLinkEditor : ModuleRules
{
    public BoneControlLiveLinkEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PublicIncludePaths.AddRange(
           new string[]
           {
                "BoneControlLiveLinkEditor/Public"
           });

        PrivateIncludePaths.AddRange(
            new string[]
            {
                "BoneControlLiveLinkEditor/Private"
            });
        PublicDependencyModuleNames.AddRange(
           new string[]
           {
            "AIModule",
            "AnimGraph",
            "AnimGraphRuntime",
            "BlueprintGraph",
            "Core",
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
            "UnrealEd",
            "BoneControlLiveLink"

           });
     
    }
}