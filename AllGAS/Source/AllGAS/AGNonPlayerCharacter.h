//	All GAS and no brakes @ Play by Play 2021
//
//  File Name   :   AGNonPlayerCharacter.h
//  Description :   Base attriubute set for characters in All GAS and no brakes
//

#pragma once

// Library Includes
#include "CoreMinimal.h"

#include "AbilitySystemInterface.h"

// Local Includes
#include "AGBaseCharacter.h"

// This Includes
#include "AGNonPlayerCharacter.generated.h"

// Types

// Constants

// Prototypes

UCLASS(config = Game, abstract)
class AAGNonPlayerCharacter : public AAGBaseCharacter
{
	GENERATED_BODY()
public:
	AAGNonPlayerCharacter();

	// IAbilitySystemInterface
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	// End of IAbilitySystemInterface

protected:

private:

public:

protected:
	/* Component interface to the ability system */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UAbilitySystemComponent* AbilitySystem = nullptr;

	/* Character Attributes */
	UPROPERTY()
	class UAGBaseAttributeSet* AttributeSet = nullptr;
};