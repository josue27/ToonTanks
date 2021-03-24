// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"


void ATankGameModeBase::BeginPlay() 
{
    Super::BeginPlay();

    //Ger reference and game win/lose condition

}

void ATankGameModeBase::ActorDied(AActor* DeadActor) 
{
    //Check what type of Actor died if turret-> tally, if player go to lose condition
}

void ATankGameModeBase::HandleGameStart() 
{
    
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon) 
{
    
}



