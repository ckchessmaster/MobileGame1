// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAISideScrollerHoming.h"
#include "EngineUtils.h"
#include "PrimaryPlayerShip.h"
#include "Engine.h"

void AEnemyAISideScrollerHoming::BeginPlay()
{
	AEnemyAIBase::BeginPlay();
}

void AEnemyAISideScrollerHoming::Tick(float DeltaTime)
{
	AEnemyAIBase::Tick(DeltaTime);

	this->GetShip()->Move(FVector(this->MovementVector, 0.0f));

	// Determine if we should change direction
	this->MovementVector = this->FindMovementVector();

	// Determine if we should fire
	if (FMath::RandRange(0, this->AttackFactor) == 1)
	{
		this->Fire();
	}
}

FVector2D AEnemyAISideScrollerHoming::FindMovementVector()
{
	FVector playerLocation = this->GetPlayerShip()->GetActorLocation();
	FVector enemyLocation = this->GetPawn()->GetActorLocation();
	FVector2D newVector = this->MovementVector;


	if (playerLocation.Y > enemyLocation.Y)
	{
		newVector = FVector2D(newVector.X, 1);
	}
	else if (playerLocation.Y < enemyLocation.Y)
	{
		newVector = FVector2D(newVector.X, -1);
	}

	return newVector;
}

AActor* AEnemyAISideScrollerHoming::GetPlayerShip()
{
	if (this->PlayerShip == nullptr) 
	{
		for (TActorIterator<APrimaryPlayerShip> iterator(this->GetWorld()); iterator; ++iterator) 
		{
			this->PlayerShip = *iterator;
			break; // There should only be one player ships but break just to be safe
		}
	}

	return this->PlayerShip;
}