// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponComponent.h"
#include "Engine.h"


// Sets default values for this component's properties
UWeaponComponent::UWeaponComponent() : Super()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

void UWeaponComponent::Fire(FVector2D direction, FName owner)
{
	FVector parentLocation = this->GetOwner()->GetActorLocation();
	FVector location(parentLocation.X, parentLocation.Y, -10.f);
	FRotator rotation(0.0f);
	FActorSpawnParameters spawnParameters;
	AAmmoBase* ammo = Cast<AAmmoBase>(GetWorld()->SpawnActor(this->AmmoType, &location, &rotation, spawnParameters));
	
	if (ammo != nullptr) {
		ammo->GetProjectileMovementComponent()->SetVelocityInLocalSpace(FVector(direction.X * ammo->GetProjectileSpeed(), direction.Y * ammo->GetProjectileSpeed(), 0.0f));
		ammo->Tags.Add(owner);
	}
}

