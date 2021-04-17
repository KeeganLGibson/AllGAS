//	All GAS and no brakes @ Play by Play 2021
//
//  File Name   :   AGBaseAttributeSet.cpp
//  Description :   Base attriubute set for characters in All GAS and no brakes
//

// This Includes
#include "AGBaseAttributeSet.h"

// Library Includes

// Local Includes

// Static Variables

// Static function prototypes

// Implementation

UAGBaseAttributeSet::UAGBaseAttributeSet()
{
	Health = 500.0f;
	MaxHealth = 500.0f;
	Mana = 500.0f;
	MaxMana = 500.0f;
}

void UAGBaseAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0, GetMaxHealth());
	}
	else if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0, GetMaxMana());
	}
}

void UAGBaseAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0, GetMaxHealth());
	}
	else if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0, GetMaxMana());
	}
}
