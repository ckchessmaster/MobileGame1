// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AmmoBase.h"
#include "CombinationAmmoBase.generated.h"

/**
 * 
 */
UCLASS()
class SPACEAGE_API ACombinationAmmoBase : public AAmmoBase
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditAnywhere)
	TMap<FVector2D, TSubclassOf<AAmmoBase>> SubAmmoSpawnList;
	
public:

	ACombinationAmmoBase();

	virtual void Tick(float DeltaTime) override;

};
