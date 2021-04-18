//	All GAS and no brakes @ Play by Play 2021
//
//  File Name   :   AGPlayerState.cpp
//  Description :   Player state.
//

// This Includes
#include "AGNonPlayerCharacter.h"

// Library Includes
#include "AbilitySystemComponent.h"

// Local Includes
#include "AGBaseAttributeSet.h"

// Static Variables

// Static function prototypes

// Implementation

AAGNonPlayerCharacter::AAGNonPlayerCharacter()
{
	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystem"));
	AttributeSet = CreateDefaultSubobject<UAGBaseAttributeSet>(TEXT("AttributeSet"));
}

void AAGNonPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystem->SetAvatarActor(this);
}

UAbilitySystemComponent* AAGNonPlayerCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystem;
}
