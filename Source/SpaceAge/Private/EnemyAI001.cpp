// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAI001.h"
#include "EnemyShipBase.h"
#include "Engine/BlockingVolume.h"
#include "Engine.h"

void AEnemyAI001::BeginPlay()
{
	Super::BeginPlay();

	// Start moving left or right
	switch (FMath::RandRange(0, 1))
	{
	case 0:
		this->MovementVector = FVector2D(0, 1);
		break;
	case 1:
		this->MovementVector = FVector2D(0, -1);
		break;
	}
}

void AEnemyAI001::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AEnemyShipBase* ship = Cast<AEnemyShipBase>(this->GetCharacter());

	// We want to move every tick
	ship->MoveHorizontal(this->MovementVector.Y);

	// Determine if we should change direction
	if (FMath::RandRange(0, this->DirectionChangeFactor) == 1) 
	{
		this->MovementVector *= -1;
	}

	// Determine if we should fire
	if (FMath::RandRange(0, this->AttackFactor) == 1) 
	{
		this->Fire();
	}
}

void AEnemyAI001::OnShipHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	// If we hit the edge of the screen reverse direction
	if (Cast<ABlockingVolume>(OtherActor) != nullptr)
	{
		this->MovementVector *= -1;
	}
}

void AEnemyAI001::Fire()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, "Pew Pew");
}
