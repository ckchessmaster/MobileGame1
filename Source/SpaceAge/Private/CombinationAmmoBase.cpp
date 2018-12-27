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
		for (const TPair<FVector2D, TSubclassOf<AAmmoBase>> ammoToSpawn : this->SubAmmoSpawnList) {
			FVector spawnLocation = this->GetActorLocation() + FVector(ammoToSpawn.Key, 0.0f);
			FRotator rotation(0.0f);
			FActorSpawnParameters spawnParameters;

			AAmmoBase* spawnedAmmo = Cast<AAmmoBase>(this->GetWorld()->SpawnActor(ammoToSpawn.Value, &spawnLocation, &rotation, spawnParameters));

			// Set the same velocity that this actor has
			spawnedAmmo->GetProjectileMovementComponent()->SetVelocityInLocalSpace(FVector(this->GetProjectileMovementComponent()->Velocity));

			// Add any flags that this actor may have
			for (const FName tag : this->Tags) {
				spawnedAmmo->Tags.Add(tag);
			}
		}

		// Once we have spawned our sub ammo we can just die
		this->Destroy();
	}
}
