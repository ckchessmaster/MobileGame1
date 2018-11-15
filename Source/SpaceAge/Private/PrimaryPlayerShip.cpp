// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/PrimaryPlayerShip.h"

void APrimaryPlayerShip::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis("MoveHorizontal", this, &APrimaryPlayerShip::MoveHorizontal);
	PlayerInputComponent->BindAxis("MoveVertical", this, &APrimaryPlayerShip::MoveVertical);
}