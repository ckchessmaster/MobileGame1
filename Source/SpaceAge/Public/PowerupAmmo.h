// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AmmoBase.h"
#include "PowerupAmmo.generated.h"

/**
 * 
 */
UCLASS()
class SPACEAGE_API APowerupAmmo : public AAmmoBase
{
	GENERATED_BODY()
	
public:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
};
