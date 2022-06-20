// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RPGPlayground : ModuleRules
{
	public RPGPlayground(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "GameplayAbilities","GameplayTags" });
	}
}
