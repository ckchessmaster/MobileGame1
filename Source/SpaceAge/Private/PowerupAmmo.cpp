// Fill out your copyright notice in the Description page of Project Settings.

#include "PowerupAmmo.h"
#include "PrimaryPlayerShip.h"

void APowerupAmmo::NotifyActorBeginOverlap(AActor* OtherActor)
{
	APaperFlipbookActor::NotifyActorBeginOverlap(OtherActor);

	APrimaryPlayerShip* playerShip = Cast<APrimaryPlayerShip>(OtherActor);

	if (playerShip != nullptr) {
		playerShip->UpgradeAmmo();
		this->Destroy();
	}
}

