// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GampeplayStatics.h"

APawnTurret::APawnTurret()
{

}

void APawnTurret::BeginPlay() 
{
    Super::BeginPlay();
     GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
}

void APawnTurret::Tick(float DeltaTime) 
{
    Super::Tick(DeltaTime);
}

void APawnTurret::CheckFireCondition() 
{
    //if player == null || is dead then bail

    //if player is in range then fire!!
    UE_LOG(LogTemp,Warning,TEXT("Fire"));
}



