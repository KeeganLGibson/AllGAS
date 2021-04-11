//	All GAS and no brakes @ Play by Play 2021
//
//  File Name   :   GPlayerState.cpp
//  Description :   TODO:
//

#pragma once

// Library Includes
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"

// Local Includes

// This Includes
#include "AGPlayerState.generated.h"

// Types

// Constants

// Prototypes
UCLASS()
class AAGPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	// Member Functions
public:
	AAGPlayerState();

	// IAbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
	// End of IAbilitySystemInterface

protected:

private:

	// Member Variables
public:

protected:
	/* Component interface to the ability system */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UAbilitySystemComponent* AbilitySystem = nullptr;

	/* Character Attributes */
	UPROPERTY()
	class UAGBaseAttributeSet* AttributeSet = nullptr;

private:

};
