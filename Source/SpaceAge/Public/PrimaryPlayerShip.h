// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ship.h"
#include "PrimaryPlayerShip.generated.h"

/**
 * 
 */
UCLASS()
class SPACEAGE_API APrimaryPlayerShip : public AShip
{
	GENERATED_BODY()
	
protected:

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);
	
};
