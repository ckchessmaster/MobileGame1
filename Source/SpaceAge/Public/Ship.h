// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "WeaponComponent.h"
#include "Ship.generated.h"

/**
 * This is the base class for all ships in the game.
 * Player and enemy ships should extend from this class.
 */
UCLASS()
class SPACEAGE_API AShip : public APaperCharacter
{
	GENERATED_BODY()
	
	

protected:

	UPROPERTY(EditAnywhere)
	class UWeaponComponent* WeaponComponent;

	// Used to scale input movement
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
	float MovementMultiplier = 1.0f;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Ship")
	int Health = 1;

public:

	AShip();

	virtual float TakeDamage(
		float DamageAmount, 
		struct FDamageEvent const& DamageEvent, 
		class AController* EventInstigator, 
		AActor* DamageCauser) override;

	/** Called for side to side input */
	virtual void MoveHorizontal(float value);

	/** Called for up and down input */
	virtual void MoveVertical(float value);

	UWeaponComponent* GetWeaponComponent() { return this->WeaponComponent; }
};
