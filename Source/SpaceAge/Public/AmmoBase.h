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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bAutoDestroyOnOverlap = true;
	
public:

	AAmmoBase();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UProjectileMovementComponent* GetProjectileMovementComponent() { return this->ProjectileMovementComponent; }
};
