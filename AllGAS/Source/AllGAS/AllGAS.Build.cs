// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AllGAS : ModuleRules
{
	public AllGAS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "GameplayAbilities", "GameplayTags", "GameplayTasks"});
	}
}
