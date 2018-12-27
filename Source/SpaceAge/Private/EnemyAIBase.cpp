// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAIBase.h"
#include "EnemyShipBase.h"
#include "Engine.h"

void AEnemyAIBase::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);

	// Start listening to ships overlap events
	InPawn->OnActorHit.AddDynamic(this, &AEnemyAIBase::OnShipHit);
}

void AEnemyAIBase::OnShipHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
}

void AEnemyAIBase::Fire()
{
	this->GetShip()->GetWeaponComponent()->Fire(FVector2D(-1, 0), TEXT("Enemy"));
}

AShip* AEnemyAIBase::GetShip()
{
	if (this->Ship == nullptr) {
		this->Ship = Cast<AEnemyShipBase>(this->GetCharacter());
		return this->Ship;
	}
	else {
		return this->Ship;
	}
}
