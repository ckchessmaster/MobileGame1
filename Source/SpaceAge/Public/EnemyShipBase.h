// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ship.h"
#include "EnemyShipBase.generated.h"

/**
 * 
 */
UCLASS()
class SPACEAGE_API AEnemyShipBase : public AShip
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere)
	int ShipStrength;

public:
	AEnemyShipBase();

	int GetShipStrength() { return this->ShipStrength; }
};
