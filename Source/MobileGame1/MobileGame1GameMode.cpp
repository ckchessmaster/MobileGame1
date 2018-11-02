// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MobileGame1GameMode.h"
#include "MobileGame1Character.h"

AMobileGame1GameMode::AMobileGame1GameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = AMobileGame1Character::StaticClass();	
}
