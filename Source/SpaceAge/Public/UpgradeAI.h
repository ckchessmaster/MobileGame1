// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyAI001.h"
#include "UpgradeAI.generated.h"

/**
 * 
 */
UCLASS()
class SPACEAGE_API AUpgradeAI : public AEnemyAI001
{
	GENERATED_BODY()

	// Just in case the ship is destroyed first we have this function
	UFUNCTION()
	void OnShipEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

public:

	virtual void Tick(float DeltaTime) override;
	
	virtual void Possess(APawn* InPawn) override;

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;
};
