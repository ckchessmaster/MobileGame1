// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Ship.h"
#include "EnemyAIBase.generated.h"

/**
 * 
 */
UCLASS()
class SPACEAGE_API AEnemyAIBase : public AAIController
{
	GENERATED_BODY()

	AShip* Ship;
	
protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon")
	int AttackFactor = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
	int DirectionChangeFactor = 1.0f;

	UFUNCTION()
	virtual void OnShipHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	virtual void Fire();

	AShip* GetShip();

public:

	virtual void Possess(APawn* InPawn) override;
	
};
