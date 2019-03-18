// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShipPlacementGrid.h"
#include "MyShipPlacementGridDynamic.generated.h"

/**
 * 
 */
UCLASS()
class SPACEAGE_API UMyShipPlacementGridDynamic : public UShipPlacementGrid
{
	GENERATED_BODY()

	int WavesSinceLastUpgrade = 0;
	int DifficultyRemaining;

protected:

	UPROPERTY(EditAnywhere)
	int BaseDifficulty;

	UPROPERTY(EditAnywhere)
	int RepeatsRemaining;

	UPROPERTY(EditAnywhere)
	int DifficultyIncrease;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<AEnemyShipBase>> AllowedShipTypes;
	
	virtual void OnShipDestroyed(AActor* DestroyedActor) override;

public:
	virtual void Init() override;

	virtual void SpawnWave() override;
	
	
};
