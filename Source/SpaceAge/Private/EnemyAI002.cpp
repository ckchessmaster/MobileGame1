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
		this->MovementVector = FVector(1.0f, 1.0f, 0.0f);
		break;
	case 1:
		this->MovementVector = FVector(-1.0f, -1.0f, 0.0f);
		break;
	case 2:
		this->MovementVector = FVector(-1.0f, 1.0f, 0.0f);
		break;
	case 3:
		this->MovementVector = FVector(1.0f, -1.0f, 0.0f);
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
			this->MovementVector = FVector(1.0f, 1.0f, 0.0f);
			break;
		case 1:
			this->MovementVector = FVector(-1.0f, -1.0f, 0.0f);
			break;
		case 2:
			this->MovementVector = FVector(-1.0f, 1.0f, 0.0f);
			break;
		case 3:
			this->MovementVector = FVector(1.0f, -1.0f, 0.0f);
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
	// If we hit the edge of the screen change direction also make sure we are not stuck on an edge
	if (Cast<ABlockingVolume>(OtherActor) != nullptr && this->RecentlyHitActor != OtherActor)
	{
		this->MovementVector = FMath::GetReflectionVector(this->MovementVector, Hit.ImpactNormal);
		this->RecentlyHitActor = OtherActor;
	}
}

void AEnemyAI002::Fire()
{
	Super::Fire();
}
