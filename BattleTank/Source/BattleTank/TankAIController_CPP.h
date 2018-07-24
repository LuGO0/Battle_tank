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

public:
		///begin play method from AI player controllers parent
		virtual void BeginPlay() override;


		//get the tank this tank player controller is posssessing
		ATank_CPP* GetControlledTank() const;
	
};
