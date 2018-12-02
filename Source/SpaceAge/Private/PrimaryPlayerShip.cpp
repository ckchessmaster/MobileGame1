// Fill out your copyright notice in the Description page of Project Settings.

#include "PrimaryPlayerShip.h"

void APrimaryPlayerShip::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis("MoveHorizontal", this, &APrimaryPlayerShip::MoveHorizontal);
	PlayerInputComponent->BindAxis("MoveVertical", this, &APrimaryPlayerShip::MoveVertical);
}

void APrimaryPlayerShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (this->TicksSinceLastAttack >= this->TicksBetweenAttacks) {
		this->GetWeaponComponent()->Fire(FVector2D(1.0f, 0.0f), TEXT("Player"));
		this->TicksSinceLastAttack = 0;
	}
	else {
		this->TicksSinceLastAttack++;
	}
}