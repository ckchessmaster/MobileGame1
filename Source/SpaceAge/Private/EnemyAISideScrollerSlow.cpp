// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAISideScrollerSlow.h"
#include "Engine/BlockingVolume.h"
#include "Engine.h"

void AEnemyAISideScrollerSlow::BeginPlay()
{
	Super::BeginPlay();

	this->MovementVector.X = -1.0f;
}

void AEnemyAISideScrollerSlow::OnShipHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	AEnemyAIBase::OnShipHit(SelfActor, OtherActor, NormalImpulse, Hit);

	// If we hit the edge of the screen reverse direction (unless it's the middle barrier)
	if (Cast<ABlockingVolume>(OtherActor) != nullptr && !OtherActor->Tags.Contains(TEXT("Mid")))
	{
		this->MovementVector.Y *= -1;
	}
}