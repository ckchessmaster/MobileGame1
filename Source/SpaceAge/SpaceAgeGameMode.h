// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Public/ShipPlacementGrid.h"
#include "SpaceAgeGameMode.generated.h"

/**
 * The GameMode defines the game being played. It governs the game rules, scoring, what actors
 * are allowed to exist in this game type, and who may enter the game.
 *
 * This game mode just sets the default pawn to be the MyCharacter asset, which is a subclass of SpaceAgeCharacter
 */
UCLASS(minimalapi)
class ASpaceAgeGameMode : public AGameModeBase
{
	GENERATED_BODY()

	UShipPlacementGrid* NextWave;
	UShipPlacementGrid* CurrentWave;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UShipPlacementGrid> InitialWaveType;

	UShipPlacementGrid* InitialWave;

	// Lets try and make this async/not in the main thread at some point
	void LoadNextWave();

public:
	ASpaceAgeGameMode();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void OnEnemyShipDestroyed();
};
