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

	int TicksSinceLastAttack = 0;
	
protected:

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<AAmmoBase>> WeaponUpgradeList;

	UPROPERTY(EditAnywhere)
	int TicksBetweenAttacks = 120;

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

public:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual float TakeDamage(
		float DamageAmount,
		struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator,
		AActor* DamageCauser) override;
	
	virtual void UpgradeAmmo();
};
