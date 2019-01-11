// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceAgePlayerController.h"
#include "PrimaryPlayerShip.h"
#include "Engine.h"

ASpaceAgePlayerController::ASpaceAgePlayerController() : Super() 
{
	this->PrimaryActorTick.bCanEverTick = true;
	this->SetActorTickEnabled(true);
	this->bEnableTouchEvents = true;
}

void ASpaceAgePlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Get touch data
	float touchX, touchY;
	bool isCurrentlyTouching = false;

	this->GetInputTouchState(ETouchIndex::Touch1, touchX, touchY, isCurrentlyTouching);

	// Should we start moving
	if (isCurrentlyTouching) {
		// Get the world coordinates from the screen location
		FVector worldTouchLocation;
		FVector worldTouchDirection;

		bool result = this->DeprojectScreenPositionToWorld(touchX, touchY, worldTouchLocation, worldTouchDirection);

		if (result && !worldTouchLocation.Equals(this->LastTouchWorldLocation)) {
			this->GetPawn()->SetActorLocation(this->CalculateMovement(worldTouchLocation), true, nullptr, ETeleportType::None);
			this->LastTouchWorldLocation = worldTouchLocation;
		}
	}
}

bool ASpaceAgePlayerController::InputTouch(
	uint32 Handle,
	ETouchType::Type Type,
	const FVector2D & TouchLocation,
	float Force,
	FDateTime DeviceTimestamp,
	uint32 TouchpadIndex)
{
	bool result = Super::InputTouch(
		Handle,
		Type,
		TouchLocation,
		Force,
		DeviceTimestamp,
		TouchpadIndex);

	switch (Type) {
		case ETouchType::Began:
		{
			// Get the world coordinates from the screen location
			FVector worldLocation;
			FVector worldDirection;

			bool result = this->DeprojectScreenPositionToWorld(TouchLocation.X, TouchLocation.Y, worldLocation, worldDirection);

			if (result) {
				this->LastTouchWorldLocation = worldLocation;
			}
			break;
		}
		default:
		{
			break;
		}
	}

	return result;
}

FVector ASpaceAgePlayerController::CalculateMovement(FVector WorldTouchLocation)
{
	// Get the change vector
	FVector movementDifference = WorldTouchLocation - this->LastTouchWorldLocation;

	// We don't want to teleport to touch so we have to translate the location based on the ship's location
	FVector shipLocation = this->GetPawn()->GetActorLocation();
	
	// Calculate the final location
	FVector finalLocation = shipLocation + movementDifference;

	// Force Z to 0
	finalLocation.Z = 0.0f;

	return finalLocation;
}
