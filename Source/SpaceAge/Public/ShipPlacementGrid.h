// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnemyShipBase.h"
#include "ShipPlacementGrid.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class SPACEAGE_API UShipPlacementGrid : public UObject
{
	GENERATED_BODY()
	
	int RemainingShips;

	UWorld* World;

	FVector2D MapCoordinates(const FVector2D coordinates);
	
protected:

	UPROPERTY(EditDefaultsOnly)
	TMap<FVector2D, TSubclassOf<AEnemyShipBase>> Grid;

	UPROPERTY(EditDefaultsOnly)
	FVector2D MappingFactor;

	UPROPERTY(EditDefaultsOnly)
	FVector2D MapingOffset;

public:

	virtual void SpawnWave();
	
	virtual void SetWorld(UWorld* world) { this->World = world; }

	int GetRemainingShips() { return this->RemainingShips; }
	void SetRemainingShips(int num) { this->RemainingShips = num; }
};
