// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AmmoBase.h"
#include "CombinationAmmoBase.generated.h"

USTRUCT()
struct FAmmoInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FVector2D OffsetLocation;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AAmmoBase> AmmoType;
};

/**
 * 
 */
UCLASS()
class SPACEAGE_API ACombinationAmmoBase : public AAmmoBase
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditAnywhere)
	TArray<FAmmoInfo> SubAmmoSpawnList;
	
public:

	ACombinationAmmoBase();

	virtual void Tick(float DeltaTime) override;

};
