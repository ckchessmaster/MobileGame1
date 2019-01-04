// Fill out your copyright notice in the Description page of Project Settings.

#include "AmmoBase.h"
#include "Engine.h"
#include "PrimaryPlayerShip.h"
#include "EnemyShipBase.h"
#include "PaperFlipbookComponent.h"

AAmmoBase::AAmmoBase() : Super()
{
	// Orient the sprite to the camera
	this->SetActorRotation(FRotator(0.0f, -90.0f, 90.0f));

	// Setup capsule component
	this->CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision Component"));
	CapsuleComponent->InitCapsuleSize(24.0f, 24.0f);
	CapsuleComponent->SetCollisionProfileName(TEXT("OverlapAll"));
	CapsuleComponent->CanCharacterStepUpOn = ECB_No;
	CapsuleComponent->SetShouldUpdatePhysicsVolume(false);
	CapsuleComponent->bCheckAsyncSceneOnMove = false;
	CapsuleComponent->SetCanEverAffectNavigation(false);
	this->RootComponent = this->CapsuleComponent;

	// Reatach the sprite component
	this->GetRenderComponent()->SetupAttachment(RootComponent);

	// Setup projectile component
	this->ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Component"));
	this->ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
}

void AAmmoBase::NotifyActorBeginOverlap(AActor* OtherActor) 
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (OtherActor->IsA<APrimaryPlayerShip>() && this->Tags.Contains(TEXT("Enemy"))) {
		OtherActor->TakeDamage(this->Damage, FDamageEvent(), nullptr, this);

		if (this->bAutoDestroyOnOverlap) {
			this->Destroy();
		}
	}
	else if (OtherActor->IsA<AEnemyShipBase>() && this->Tags.Contains(TEXT("Player"))) {
		OtherActor->TakeDamage(this->Damage, FDamageEvent(), nullptr, this);

		if (this->bAutoDestroyOnOverlap) {
			this->Destroy();
		}
	}
	else if (OtherActor->IsA<ABlockingVolume>() && !OtherActor->Tags.Contains("PlayerBlock") && this->bAutoDestroyOnOverlap) {
		this->Destroy();
	}
}
