// Copyright 2024 Mischievous Game, Inc. All Rights Reserved.

using System;
using System.IO;

using UnrealBuildTool;

public class GKUI : ModuleRules
{
    public GKUI(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrecompileForTargets = PrecompileTargetsType.Any;

        PublicIncludePaths.Add(Path.Combine(ModuleDirectory));

        PublicDependencyModuleNames.AddRange(
            new string[] {
                "Core",
                "ModularGameplay",
                "GameFeatures"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[] {

            }
        );

        DynamicallyLoadedModuleNames.AddRange(
            new string[] {
            }
        );

        // Version Info
        // ------------
        // Automatically set by the CI
        string GKUI_TAG = "v0.0.0";
        string GKUI_HASH = "outoftree";
        string GKUI_DATE = "1900-01-01 00:00:00 -0000";

        PublicDefinitions.Add("GKUI_TAG=" + GKUI_TAG);
        PublicDefinitions.Add("GKUI_COMMIT=" + GKUI_HASH);
        PublicDefinitions.Add("GKUI_DATE=" + GKUI_DATE);
    }
}
