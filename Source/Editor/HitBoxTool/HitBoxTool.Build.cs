// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HitBoxTool : ModuleRules
{
    public HitBoxTool(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
            new string[] {
                "Core",
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
            }
        );

        PublicDependencyModuleNames.AddRange(
            new string[] {
                "UnrealEd",
                "ToolMenus",
                "Persona",
                "AdvancedPreviewScene",
            }
        );
    }
}
