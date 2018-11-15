// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/Ship.h"
#include "GameFramework/CharacterMovementComponent.h"

AShip::AShip()
{
	// Ships should stop as soon as input ends
	UCharacterMovementComponent* movementComponent = (UCharacterMovementComponent*)this->GetMovementComponent();
	movementComponent->bUseSeparateBrakingFriction = true;
	movementComponent->BrakingFriction = 1000.0f;

	// Orient the sprite to the camera
	this->bUseControllerRotationPitch = false;
	this->bUseControllerRotationRoll = false;
	this->bUseControllerRotationYaw = false;
	this->SetActorRotation(FRotator(0.0f, -90.0f, 90.0f));
}

void AShip::MoveHorizontal(float value) 
{
	AddMovementInput(FVector(0.0f, 1.0f, 0.0f), value * this->MovementMultiplier);
}

void AShip::MoveVertical(float value)
{
	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), value * this->MovementMultiplier);
}