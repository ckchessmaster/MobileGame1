// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAIHomingOmnidirectional.h"
#include "Engine/BlockingVolume.h"

void AEnemyAIHomingOmnidirectional::BeginPlay()
{
	Super::BeginPlay();

	// Start moving up or down
	switch (FMath::RandRange(0, 1))
	{
	case 0:
		this->MovementVector = FVector2D(1, 0);
		break;
	case 1:
		this->MovementVector = FVector2D(-1, 0);
		break;
	}
}

void AEnemyAIHomingOmnidirectional::OnShipHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	// If we hit the top or bottom of the screen reverse direction
	if (Cast<ABlockingVolume>(OtherActor) != nullptr && OtherActor != this->LastActorHit)
	{
		this->MovementVector.X *= -1;
		this->LastActorHit = OtherActor;
	}
}
