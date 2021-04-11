// Copyright Epic Games, Inc. All Rights Reserved.

#include "AllGASGameMode.h"
#include "AllGASCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAllGASGameMode::AAllGASGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
