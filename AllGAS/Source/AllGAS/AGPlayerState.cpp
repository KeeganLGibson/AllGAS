//	All GAS and no brakes @ Play by Play 2021
//
//  File Name   :   AGPlayerState.cpp
//  Description :   Player state.
//

// This Includes
#include "AGPlayerState.h"

// Library Includes
#include "AbilitySystemComponent.h"

// Local Includes
#include "AGBaseAttributeSet.h"

// Static Variables

// Static function prototypes

// Implementation

AAGPlayerState::AAGPlayerState()
{
	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystem"));
	AttributeSet = CreateDefaultSubobject<UAGBaseAttributeSet>(TEXT("AttributeSet"));
}

UAbilitySystemComponent* AAGPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystem;
}
