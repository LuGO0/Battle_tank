// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Tank_CPP.generated.h"


UCLASS()
class BATTLETANK_API ATank_CPP : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank_CPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//the scene root component of the default pawn
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* TankBody=nullptr;

	//static turret mesh
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Turret = nullptr;

	//static barrel mesh
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Barrel = nullptr;

	//static track mesh
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Track_01 = nullptr;

	//static track mesh
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Track_02 = nullptr;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArm = nullptr;

	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera = nullptr;

	UFUNCTION()
		void SetSpringArmAzimuthAngle(float AxisValue);
	
	//Spring arm 2D rotation
	FVector2D SpringArmRotation;

	UFUNCTION()
	void SetSpringArmAltitudeAngle(float AxisValue);
};
