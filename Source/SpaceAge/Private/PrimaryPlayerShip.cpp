// Fill out your copyright notice in the Description page of Project Settings.

#include "PrimaryPlayerShip.h"
#include "SpaceAgeGameMode.h"
#include "Engine.h"

void APrimaryPlayerShip::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis("MoveHorizontal", this, &APrimaryPlayerShip::MoveHorizontal);
	PlayerInputComponent->BindAxis("MoveVertical", this, &APrimaryPlayerShip::MoveVertical);
}

void APrimaryPlayerShip::BeginPlay()
{
	Super::BeginPlay();

	if (this->WeaponUpgradeList.Num() > 0) {
		this->WeaponComponent->SetAmmoType(this->WeaponUpgradeList[0]);
	}
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

float APrimaryPlayerShip::TakeDamage(
	float DamageAmount,
	struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator,
	AActor* DamageCauser)
{
	APaperCharacter::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	this->Health -= DamageAmount;

	// If we are dead then the game ends
	if (this->Health <= 0) {
		this->SetActorHiddenInGame(true);

		// Do destroy animation here

		this->GetWorld()->GetAuthGameMode<ASpaceAgeGameMode>()->GameOver();

		return DamageAmount;
	}

	// Downgrade our ammo
	if (int weaponIndex = this->WeaponUpgradeList.IndexOfByKey(this->WeaponComponent->GetAmmoType()) != 0) {
		this->WeaponComponent->SetAmmoType(this->WeaponUpgradeList[weaponIndex - 1]);
	}

	return DamageAmount;
}

void APrimaryPlayerShip::UpgradeAmmo()
{
	int weaponIndex = this->WeaponUpgradeList.IndexOfByKey(this->WeaponComponent->GetAmmoType());
	
	// Only upgrade if there is another weapon to choose from
	if (this->WeaponUpgradeList.Num() > weaponIndex + 1) {
		this->WeaponComponent->SetAmmoType(this->WeaponUpgradeList[weaponIndex + 1]);
	}

	this->Health++;
}