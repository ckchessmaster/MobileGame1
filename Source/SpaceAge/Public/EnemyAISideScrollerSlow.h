// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyAI001.h"
#include "EnemyAISideScrollerSlow.generated.h"

/**
 * 
 */
UCLASS()
class SPACEAGE_API AEnemyAISideScrollerSlow : public AEnemyAI001
{
	GENERATED_BODY()
	
	
protected:

	virtual void OnShipHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit) override;

public:

	virtual void BeginPlay() override;

};
