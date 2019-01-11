// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookActor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "AmmoBase.generated.h"

/**
 * 
 */
UCLASS()
class SPACEAGE_API AAmmoBase : public APaperFlipbookActor
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attack")
	class UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Collision")
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Collision")
	bool bAutoDestroyOnOverlap = true;

	UPROPERTY(EditAnywhere, Category = "Attack")
	float Damage = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Attack")
	float ProjectileSpeed = 500.0f;
	
public:

	AAmmoBase();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UProjectileMovementComponent* GetProjectileMovementComponent() { return this->ProjectileMovementComponent; }

	float GetProjectileSpeed() { return this->ProjectileSpeed; }
};
