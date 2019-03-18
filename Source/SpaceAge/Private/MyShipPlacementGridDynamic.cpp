// Fill out your copyright notice in the Description page of Project Settings.

#include "MyShipPlacementGridDynamic.h"
//#include "CoreMinimal.h"

void UMyShipPlacementGridDynamic::OnShipDestroyed(AActor* DestroyedActor)
{
	Super::OnShipDestroyed(DestroyedActor);

	if (this->GetRemainingShips() <= this->RepeatsRemaining && this->RepeatsRemaining > 0)
	{
		this->RepeatsRemaining--;
		this->BaseDifficulty += this->DifficultyIncrease;
		this->DifficultyRemaining = this->BaseDifficulty;
		this->SpawnWave();
	}
}

void UMyShipPlacementGridDynamic::Init()
{
	this->DifficultyRemaining = this->BaseDifficulty;
}

void UMyShipPlacementGridDynamic::SpawnWave()
{
	// Set remaining ships higher that actual number so that gamemode doesn't skip us
	this->RemainingShips = this->RepeatsRemaining;



	while (this->DifficultyRemaining > 0) {
		TArray<TSubclassOf<AEnemyShipBase>> filteredShipTypes = TArray<TSubclassOf<AEnemyShipBase>>();
		for (int i = 0; i < this->AllowedShipTypes.Num(); i++)
		{
			if (this->AllowedShipTypes[i].GetDefaultObject()->GetShipStrength() <= this->DifficultyRemaining) {
				filteredShipTypes.Add(this->AllowedShipTypes[i]);
			}
		}

		FVector2D mappedLocation = this->MapCoordinates(FVector2D(FMath::RandRange(0.0f, 40.0f), FMath::RandRange(0.0f, 40.0f)));
		FVector spawnLocation(mappedLocation.X, mappedLocation.Y, 0.0f);

		FRotator rotation(0.0f);
		FActorSpawnParameters spawnParameters;

		TSubclassOf<AEnemyShipBase> shipTypeToSpawn = filteredShipTypes[FMath::RandRange(0, filteredShipTypes.Num() - 1)];
		
		AActor* spawnedShip = this->World->SpawnActor(
			shipTypeToSpawn,
			&spawnLocation,
			&rotation,
			spawnParameters);
		spawnedShip->OnDestroyed.AddDynamic(this, &UMyShipPlacementGridDynamic::OnShipDestroyed);

		this->RemainingShips++;
		this->DifficultyRemaining -= shipTypeToSpawn.GetDefaultObject()->GetShipStrength();
	}
}