// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController_CPP.h"
#include"Engine/World.h"



void  ATankAIController_CPP::BeginPlay()
{
	ATank_CPP* ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("yes im possesing an AI TANK :%s"),*ControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("no im not possesing an AI TANK"));
	}
	

	///logging if the AI got the sight of user tank or not
	ATank_CPP* PlayerControlledTank = GetPlayerControlledPawn();
	if (PlayerControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("yes tank :%s in sight"),*PlayerControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("no user tank not in sight"));
	}

}

ATank_CPP * ATankAIController_CPP::GetControlledTank() const
{
	return static_cast<ATank_CPP*>(GetPawn());
	// u could also have used the unreal templated cast function but that will do
}

ATank_CPP * ATankAIController_CPP::GetPlayerControlledPawn() const
{
	///get the tank palyercontrolled tank
	ATank_CPP* PlayerControlledTank = static_cast<ATank_CPP*>(GetWorld()->GetFirstPlayerController()->GetPawn());
	return PlayerControlledTank;
}
