// Fill out your copyright notice in the Description page of Project Settings.

#include "UpgradeAI.h"
#include "Engine.h"

void AUpgradeAI::Tick(float DeltaTime)
{
	AEnemyAIBase::Tick(DeltaTime);

	// We want to move every tick
	this->GetShip()->MoveHorizontal(this->MovementVector.Y);
}

void AUpgradeAI::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);

	InPawn->OnEndPlay.AddDynamic(this, &AUpgradeAI::OnShipEndPlay);
}

void AUpgradeAI::OnShipEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason)
{
	if (EndPlayReason == EEndPlayReason::Type::Destroyed) {
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, "lkjalksdjflkjasdlkfj");
		this->Fire();
	}
}

void AUpgradeAI::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	if (EndPlayReason == EEndPlayReason::Type::Destroyed) {
		this->Fire();
	}

	Super::EndPlay(EndPlayReason);
}