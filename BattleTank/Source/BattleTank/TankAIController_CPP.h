// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include"Tank_CPP.h"
#include "TankAIController_CPP.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController_CPP : public AAIController
{
	GENERATED_BODY()

private:
		// AI tank(this)
		ATank_CPP * ControlledTank;
	
		//Player controller tank
		ATank_CPP* PlayerControlledTank;

		//Tick inheritance
		virtual void Tick(float DeltaSeconds) override;
public:
		///begin play method from AI player controllers parent
		virtual void BeginPlay() override;

		//get the tank this tank player controller is posssessing
		ATank_CPP* GetControlledTank() const;

		//get the tank player controller pawn  //actually this will be used for aiming at the player cotroller by the AI tanks
		ATank_CPP* GetPlayerControlledPawn() const;
};
