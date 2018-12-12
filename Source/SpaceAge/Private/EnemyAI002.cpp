// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAI002.h"
#include "EnemyShipBase.h"
#include "Engine/BlockingVolume.h"

void AEnemyAI002::BeginPlay()
{
	Super::BeginPlay();

	// Start moving left or right
	switch (FMath::RandRange(0, 3))
	{
	case 0:
		this->MovementVector = FVector2D(1, 1);
		break;
	case 1:
		this->MovementVector = FVector2D(-1, -1);
		break;
	case 2:
		this->MovementVector = FVector2D(-1, 1);
		break;
	case 3:
		this->MovementVector = FVector2D(1, -1);
		break;
	}
}

void AEnemyAI002::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// We want to move every tick
	this->GetShip()->Move(this->MovementVector);

	// Determine if we should change direction
	if (FMath::RandRange(0, this->DirectionChangeFactor) == 1)
	{
		switch (FMath::RandRange(0, 3))
		{
		case 0:
			this->MovementVector = FVector2D(1, 1);
			break;
		case 1:
			this->MovementVector = FVector2D(-1, -1);
			break;
		case 2:
			this->MovementVector = FVector2D(-1, 1);
			break;
		case 3:
			this->MovementVector = FVector2D(1, -1);
			break;
		}
	}

	// Determine if we should fire
	if (FMath::RandRange(0, this->AttackFactor) == 1)
	{
		this->Fire();
	}
}

void AEnemyAI002::OnShipHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	// TODO: make us go towards the center of the screen on hit
	// If we hit the edge of the screen reverse direction
	if (Cast<ABlockingVolume>(OtherActor) != nullptr)
	{
		switch (FMath::RandRange(0, 3))
		{
		case 0:
			if (!this->MovementVector.Equals(FVector2D(1, 1))) {
				this->MovementVector = FVector2D(1, 1);
				break;
			}
		case 1:
			if (!this->MovementVector.Equals(FVector2D(-1, -1))) {
				this->MovementVector = FVector2D(-1, -1);
				break;
			}
		case 2:
			if (!this->MovementVector.Equals(FVector2D(-1, 1))) {
				this->MovementVector = FVector2D(-1, 1);
				break;
			}
		case 3:
			if (!this->MovementVector.Equals(FVector2D(1, -1))) {
				this->MovementVector = FVector2D(1, -1);
				break;
			}
		default:
			this->MovementVector = FVector2D(1, 1);
		}
	}
}

void AEnemyAI002::Fire()
{
	Super::Fire();
}
