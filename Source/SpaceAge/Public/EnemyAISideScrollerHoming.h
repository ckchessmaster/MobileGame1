// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyAI001.h"
#include "EnemyAISideScrollerHoming.generated.h"

/**
 * 
 */
UCLASS()
class SPACEAGE_API AEnemyAISideScrollerHoming : public AEnemyAI001
{
	GENERATED_BODY()

	FVector2D FindMovementVector();

	AActor* PlayerShip;
	AActor* GetPlayerShip();
	
public:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
