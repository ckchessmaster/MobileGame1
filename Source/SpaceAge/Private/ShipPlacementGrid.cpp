// Fill out your copyright notice in the Description page of Project Settings.

#include "ShipPlacementGrid.h"
#include "Engine.h"


void UShipPlacementGrid::SpawnWave()
{
	for (const TPair<FVector2D, TSubclassOf<AEnemyShipBase>> shipToSpawn : this->Grid) {
		if (shipToSpawn.Value != nullptr) {
			FVector2D mappedCoordiantes = this->MapCoordinates(shipToSpawn.Key);

			FVector spawnLocation(mappedCoordiantes.X, mappedCoordiantes.Y, 0.0f);
			FRotator rotation(0.0f);
			FActorSpawnParameters spawnParameters;

			AActor* spawnedShip = this->World->SpawnActor(shipToSpawn.Value, &spawnLocation, &rotation, spawnParameters);
			spawnedShip->OnDestroyed.AddDynamic(this, &UShipPlacementGrid::OnShipDestroyed);
			this->RemainingShips++;
		}
	}
}

FVector2D UShipPlacementGrid::MapCoordinates(const FVector2D coordinates)
{
	float mappedX = (coordinates.X * this->MappingFactor.X) + this->MapingOffset.X;
	float mappedY = (coordinates.Y * this->MappingFactor.Y) + this->MapingOffset.Y;

	return FVector2D(mappedX, mappedY);
}

void UShipPlacementGrid::OnShipDestroyed(AActor* DestroyedActor)
{
	this->RemainingShips--;
	//this->OnShipDestroyedEvent.Broadcast(Cast<AShip>(DestroyedActor));
}
