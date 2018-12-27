// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AmmoBase.h"
#include "WeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACEAGE_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, Category = "Weapon")
	TSubclassOf<AAmmoBase> AmmoType;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	float AmmoVelocity = 100.0f;

public:	
	// Sets default values for this component's properties
	UWeaponComponent();
	
	virtual void Fire(FVector2D direction, FName owner);

	virtual void SetAmmoType(TSubclassOf<AAmmoBase> ammoType) { this->AmmoType = ammoType; }

	virtual TSubclassOf<AAmmoBase> GetAmmoType() { return this->AmmoType; }
};
