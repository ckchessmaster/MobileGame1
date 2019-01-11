// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SpaceAgeGameMode.h"
#include "SpaceAgeCharacter.h"
#include "Engine.h"

ASpaceAgeGameMode::ASpaceAgeGameMode() : Super()
{
	// Set default pawn class to our character
	DefaultPawnClass = ASpaceAgeCharacter::StaticClass();
	
	this->PrimaryActorTick.bCanEverTick = true;
	this->SetActorTickEnabled(true);
}

void ASpaceAgeGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Load and spawn the first wave
	this->LoadNextWave();
	this->NextWave->SpawnWave();
	this->CurrentWave = this->NextWave;

	// Load up the next wave
	this->LoadNextWave();
}

void ASpaceAgeGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Should we move to the next wave?
	if (this->CurrentWave->GetRemainingShips() <= 0) {
		
		if (this->NextWave != nullptr) {
			this->NextWave->SpawnWave();
			this->CurrentWave = this->NextWave;
			this->LoadNextWave();
		}
		else {
			this->Win();
		}
	}
}

void ASpaceAgeGameMode::LoadNextWave()
{
	// Make sure there is another wave to spawn otherwise the game is over
	if (this->Waves.Num() > 0) {
		this->NextWave = NewObject<UShipPlacementGrid>(this, this->Waves[0]);
		this->NextWave->SetWorld(this->GetWorld());
		this->NextWave->OnShipDestroyedEvent.AddDynamic(this, &ASpaceAgeGameMode::OnEnemyShipDestroyed);
		this->Waves.RemoveAt(0);
	}
	else {
		this->NextWave = nullptr;
	}
}

void ASpaceAgeGameMode::OnEnemyShipDestroyed(AShip* destroyedShip)
{
	//this->CurrentWave->SetRemainingShips(this->CurrentWave->GetRemainingShips() - 1);
}

void ASpaceAgeGameMode::Win()
{
	// Pause the game
	APlayerController* player = this->GetWorld()->GetFirstPlayerController();
	player->SetPause(true);

	// Call blueprint event
	this->OnWin();
}

void ASpaceAgeGameMode::GameOver()
{
	// Pause the game
	APlayerController* player = this->GetWorld()->GetFirstPlayerController();
	player->SetPause(true);

	// Call blueprint event
	this->OnGameOver();
}