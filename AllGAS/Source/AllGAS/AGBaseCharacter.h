//	All GAS and no brakes @ Play by Play 2021
//
//  File Name   :   AGBaseCharacter.h
//  Description :   Base common character between players and non player characters
//

#pragma once

// Library Includes
#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "AbilitySystemInterface.h"

// Local Includes

// This Includes
#include "AGBaseCharacter.generated.h"

// Types

// Constants

// Prototypes

UCLASS(config = Game, abstract)
class AAGBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:

	// IAbilitySystemInterface
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override {return nullptr;};
	// End of IAbilitySystemInterface
};