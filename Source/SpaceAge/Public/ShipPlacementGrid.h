// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnemyShipBase.h"
#include "ShipPlacementGrid.generated.h"

USTRUCT()
struct FShipInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FVector2D SpawnLocation;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AEnemyShipBase> ShipType;
};

/**
 * 
 */
UCLASS(Blueprintable)
class SPACEAGE_API UShipPlacementGrid : public UObject
{
	GENERATED_BODY()
	
	
	
protected:

	UPROPERTY(EditAnywhere)
	TArray<FShipInfo> Grid;

	UPROPERTY(EditDefaultsOnly)
	FVector2D MappingFactor;

	UPROPERTY(EditDefaultsOnly)
	FVector2D MapingOffset;

	int RemainingShips;

	UWorld* World;

	FVector2D MapCoordinates(const FVector2D coordinates);

	UFUNCTION()
	virtual void OnShipDestroyed(AActor* DestroyedActor);

public:

	//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FShipDestroyedSignature, AShip*, DestroyedShip);
	//FShipDestroyedSignature OnShipDestroyedEvent;

	virtual void Init();

	UFUNCTION()
	virtual void SpawnWave();
	
	virtual void SetWorld(UWorld* world) { this->World = world; }

	int GetRemainingShips() { return this->RemainingShips; }
	void SetRemainingShips(int num) { this->RemainingShips = num; }
};
