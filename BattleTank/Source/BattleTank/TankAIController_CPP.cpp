// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController_CPP.h"



void  ATankAIController_CPP::BeginPlay()
{
	ATank_CPP* ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("yes im possesing an AI TANK"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("no im not possesing an AI TANK"));
	}
	
}

ATank_CPP * ATankAIController_CPP::GetControlledTank() const
{
	return static_cast<ATank_CPP*>(GetPawn());
	// u could also have used the unreal templated cast function but that will do
}
