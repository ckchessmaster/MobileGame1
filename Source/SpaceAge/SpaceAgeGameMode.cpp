// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SpaceAgeGameMode.h"
#include "SpaceAgeCharacter.h"

ASpaceAgeGameMode::ASpaceAgeGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = ASpaceAgeCharacter::StaticClass();	
}
