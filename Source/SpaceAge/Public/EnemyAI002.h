// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyAIBase.h"
#include "EnemyAI002.generated.h"

/**
 * 
 */
UCLASS()
class SPACEAGE_API AEnemyAI002 : public AEnemyAIBase
{
	GENERATED_BODY()

	AActor* RecentlyHitActor;

protected:
	FVector MovementVector;

	virtual void OnShipHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit) override;

	virtual void Fire() override;
	
public:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};
