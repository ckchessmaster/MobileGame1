// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAIBase.h"
#include "EnemyShipBase.h"
#include "Engine.h"

void AEnemyAIBase::BeginPlay()
{
	Super::BeginPlay();

	// Start listening to ships overlap events
	AEnemyShipBase* ship = Cast<AEnemyShipBase>(this->GetCharacter());
	ship->OnActorHit.AddDynamic(this, &AEnemyAIBase::OnShipHit);
}

void AEnemyAIBase::OnShipHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
}

void AEnemyAIBase::Fire()
{
	
}


