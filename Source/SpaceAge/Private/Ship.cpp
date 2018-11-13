// Fill out your copyright notice in the Description page of Project Settings.

#include "Ship.h"


void AShip::MoveHorizontal(float value) 
{
	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), value * this->MovementMultiplier);
}

void AShip::MoveVertical(float value)
{
	AddMovementInput(FVector(0.0f, 1.0f, 0.0f), value * this->MovementMultiplier);
}