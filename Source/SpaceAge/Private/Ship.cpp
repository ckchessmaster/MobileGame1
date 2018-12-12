// Fill out your copyright notice in the Description page of Project Settings.

#include "Ship.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

AShip::AShip() : Super()
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

	// Setup collision
	this->GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);

	// Setup weapon component
	WeaponComponent = CreateDefaultSubobject<UWeaponComponent>(TEXT("Weapon"));

	// Misc.
	this->bCanBeDamaged = true;
}

float AShip::TakeDamage(
	float DamageAmount, 
	struct FDamageEvent const& DamageEvent, 
	class AController* EventInstigator, 
	AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	this->Health -= DamageAmount;

	if (this->Health <= 0) {
		this->Destroy();
	}

	return DamageAmount;
}

void AShip::MoveHorizontal(float value) 
{
	AddMovementInput(FVector(0.0f, 1.0f, 0.0f), value * this->MovementMultiplier);
}

void AShip::MoveVertical(float value)
{
	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), value * this->MovementMultiplier);
}

void AShip::Move(FVector2D value)
{
	AddMovementInput(FVector(value.X, value.Y, 0.0f), this->MovementMultiplier);
}

