// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

void APawnTurret::BeginPlay() 
{
    Super::BeginPlay();
     GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
    //Buscamos al pawn del jugador
     PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this,0));
}

void APawnTurret::HandleDestruction() 
{
    Super::HandleDestruction();
    Destroy();
}

void APawnTurret::Tick(float DeltaTime) 
{
    Super::Tick(DeltaTime);
    if(!PlayerPawn || ReturnDistanceToPlayer() > FireRange)
    {
        return;
    }
     RotateTurretFunction(PlayerPawn->GetActorLocation());
}

void APawnTurret::CheckFireCondition() 
{
    //if player == null || is dead then bail
    if(!PlayerPawn)
    {
        return;
    }

    //if player is in range then fire!!
    if(ReturnDistanceToPlayer() <= FireRange)
    {
        Fire();
        UE_LOG(LogTemp,Warning,TEXT("Fire success"));

    }
   
}

float APawnTurret::ReturnDistanceToPlayer() 
{
    if(!PlayerPawn)//solo por precaucion
    {
        return 0;
    }

    
    return FVector::Dist(PlayerPawn->GetActorLocation(),GetActorLocation()); 
}
