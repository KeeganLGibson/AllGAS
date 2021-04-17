//	All GAS and no brakes @ Play by Play 2021
//
//  File Name   :   AGBaseAttributeSet.h
//  Description :   Base attriubute set for characters in All GAS and no brakes
//

#pragma once

// Library Includes
#include "AttributeSet.h"

// Local Includes

// This Includes
#include "AGBaseAttributeSet.generated.h"

// Types
// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

// Constants

// Prototypes

UCLASS()
class UAGBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	/** Set default values. For example, Health should be set to a positive number */
	UAGBaseAttributeSet();

	/**
	 *	Called just before any modification happens to an attribute. This is lower level than PreAttributeModify/PostAttribute modify.
	 *	There is no additional context provided here since anything can trigger this. Executed effects, duration based effects, effects being removed, immunity being applied, stacking rules changing, etc.
	 *	This function is meant to enforce things like "Health = Clamp(Health, 0, MaxHealth)" and NOT things like "trigger this extra thing if damage is applied, etc".
	 *
	 *	NewValue is a mutable reference so you are able to clamp the newly applied value as well.
	 */
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	/**
	 *	This is called just before any modification happens to an attribute's base value when an attribute aggregator exists.
	 *	This function should enforce clamping (presuming you wish to clamp the base value along with the final value in PreAttributeChange)
	 *	This function should NOT invoke gameplay related events or callbacks. Do those in PreAttributeChange() which will be called prior to the
	 *	final value of the attribute actually changing.
	 */
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;

public:
	/** This measures how much damage can be absorbed before dying. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAGBaseAttributeSet, Health);

	/** This this the total amount of health the character can have. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAGBaseAttributeSet, MaxHealth);

	/** This measures how many abilities can be activated. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAGBaseAttributeSet, Mana);

	/** This is the max amount of mana a character can have. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAGBaseAttributeSet, MaxMana);
};
