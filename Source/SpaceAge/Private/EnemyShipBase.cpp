// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyShipBase.h"

AEnemyShipBase::AEnemyShipBase() : Super()
{
	this->AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}