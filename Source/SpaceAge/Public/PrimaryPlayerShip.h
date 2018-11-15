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
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface
	
};
