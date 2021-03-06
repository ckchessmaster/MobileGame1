// Fill out your copyright notice in the Description page of Project Settings.

#include "CombinationAmmoBase.h"

ACombinationAmmoBase::ACombinationAmmoBase() : Super()
{
	this->PrimaryActorTick.bCanEverTick = true;
	this->SetActorTickEnabled(true);
}

void ACombinationAmmoBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Make sure that an initial velocity has been set 
	if (this->GetProjectileMovementComponent()->Velocity != FVector(1.0f, 0.0f, 0.0f))
	{
		for (const FAmmoInfo ammoToSpawn : this->SubAmmoSpawnList) {
			FVector spawnLocation = this->GetActorLocation() + FVector(ammoToSpawn.OffsetLocation, 0.0f);
			FRotator rotation(0.0f);
			FActorSpawnParameters spawnParameters;
			spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			AAmmoBase* spawnedAmmo = Cast<AAmmoBase>(this->GetWorld()->SpawnActor(ammoToSpawn.AmmoType, &spawnLocation, &rotation, spawnParameters));

			if (spawnedAmmo != nullptr) {
				// Set the same velocity that this actor has
				spawnedAmmo->GetProjectileMovementComponent()->SetVelocityInLocalSpace(FVector(this->GetProjectileMovementComponent()->Velocity));

				// Add any flags that this actor may have
				for (const FName tag : this->Tags) {
					spawnedAmmo->Tags.Add(tag);
				}
			}
		}

		// Once we have spawned our sub ammo we can just die
		this->Destroy();
	}
}
