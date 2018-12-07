// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SpaceAgeGameMode.h"
#include "SpaceAgeCharacter.h"

ASpaceAgeGameMode::ASpaceAgeGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = ASpaceAgeCharacter::StaticClass();
}

void ASpaceAgeGameMode::BeginPlay()
{
	Super::BeginPlay();

	this->InitialWave = NewObject<UShipPlacementGrid>(this, this->InitialWaveType);

	this->InitialWave->SetWorld(this->GetWorld());

	this->InitialWave->SpawnWave();
	this->CurrentWave = this->InitialWave;
	this->LoadNextWave();
}

void ASpaceAgeGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (this->CurrentWave->GetRemainingShips() <= 0) {
		this->NextWave->SpawnWave();
		this->CurrentWave = this->NextWave;
		this->LoadNextWave();
	}
}

void ASpaceAgeGameMode::LoadNextWave()
{
	// Set UWorld on object
}

void ASpaceAgeGameMode::OnEnemyShipDestroyed()
{
	this->CurrentWave->SetRemainingShips(this->CurrentWave->GetRemainingShips() - 1);
}