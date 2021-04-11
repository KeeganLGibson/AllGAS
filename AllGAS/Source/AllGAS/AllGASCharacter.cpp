// Copyright Epic Games, Inc. All Rights Reserved.

#include "AllGASCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

#include "AGInput.h"
#include "AGBaseAttributeSet.h"
#include "AGPlayerState.h"

//////////////////////////////////////////////////////////////////////////
// AAllGASCharacter

AAllGASCharacter::AAllGASCharacter()
{
	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
}

//////////////////////////////////////////////////////////////////////////
// Input

void AAllGASCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction(GBA::Jump, IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(GBA::Jump, IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis(GBA::MoveForward, this, &AAllGASCharacter::MoveForward);
	PlayerInputComponent->BindAxis(GBA::MoveRight, this, &AAllGASCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis(GBA::Turn, this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(GBA::TurnRate, this, &AAllGASCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis(GBA::LookUp, this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(GBA::LookUpRate, this, &AAllGASCharacter::LookUpAtRate);
}

class UAbilitySystemComponent* AAllGASCharacter::GetAbilitySystemComponent() const
{
	return GetPlayerState<AAGPlayerState>()->GetAbilitySystemComponent();
}

void AAllGASCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AAllGASCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AAllGASCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AAllGASCharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
