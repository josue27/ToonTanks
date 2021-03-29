// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTank.generated.h"

class USpringArmComponent;
class UCameraComponent;
UCLASS()
class TOONTANKS_API APawnTank : public APawnBase
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components",meta=(AllowPrivateAccess = "true"))	
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components",meta=(AllowPrivateAccess = "true"))
	UCameraComponent* Camera;
	
	FVector MoveDirection;
	FQuat RotationDirection;
	UPROPERTY(EditAnyWhere,Category="Settings")
	float MoveSpeed = 100.0f;
	UPROPERTY(EditAnyWhere,Category="Settings")
	float RotateSpeed = 100.0f;
	APlayerController* PlayerControllerRef;

	void CalculateMoveInpunt(float Value);
	void CalculateRotateInput(float Value);

	void Move();
	void Rotate();

	bool bIsPlayerAlive = true;
public:
	APawnTank();

		// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void HandleDestruction() override;

	bool GetIsPlayerAlive();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



};
