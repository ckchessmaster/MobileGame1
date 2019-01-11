// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SpaceAgePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SPACEAGE_API ASpaceAgePlayerController : public APlayerController
{
	GENERATED_BODY()

	FVector LastTouchWorldLocation;
	
	FVector CalculateMovement(const FVector WorldTouchLocation);

public:
	ASpaceAgePlayerController();
	
	virtual void Tick(float DeltaTime) override;

	virtual bool InputTouch(uint32 Handle,
		ETouchType::Type Type,
		const FVector2D & TouchLocation,
		float Force,
		FDateTime DeviceTimestamp,
		uint32 TouchpadIndex) override;
};
