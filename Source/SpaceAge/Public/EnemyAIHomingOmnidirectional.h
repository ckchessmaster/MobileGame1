// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnemyAISideScrollerHoming.h"
#include "CoreMinimal.h"
#include "EnemyAI001.h"
#include "EnemyAIHomingOmnidirectional.generated.h"

/**
 * 
 */
UCLASS()
class SPACEAGE_API AEnemyAIHomingOmnidirectional : public AEnemyAISideScrollerHoming
{
	GENERATED_BODY()

	AActor* LastActorHit;

protected:
	virtual void OnShipHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit) override;

public:
	virtual void BeginPlay() override;
	
};
