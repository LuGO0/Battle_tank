// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController_CPP.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "Classes/AIController.h"



ATankPlayerController_CPP::ATankPlayerController_CPP()
{/*
	///TODO logic for spawning ll other tanks as AI tanks and hard code the tankAI controller_CPP here
	static ConstructorHelpers::FClassFinder<AAIController> AIController(TEXT("Class'/Script/BattleTank.TankAIController_CPP'"));
	if (AIController.Class)
	{
		GetPawn()->AIControllerClass = AIController.Class;
		GetPawn()->AutoPossessAI = EAutoPossessAI::PlacedInWorld;
	}
	else
		return;*/
}


void ATankPlayerController_CPP::BeginPlay()
{

	Super::BeginPlay();
	///I dont need constructor helpers as im not hard referencing assets but I will be assigning the refernce to the
	///UI widget property( which has been declared as UPROPERTY) in the blueprint class of TankPlayerController
	///Mind you the blueprint class will be setup as the default player controller

	if (UIWidget)
	{
		UserWidget = CreateWidget<UUserWidget>(this, UIWidget);

		if(UserWidget)
		{
			UserWidget->AddToViewport();
			UE_LOG(LogTemp, Warning, TEXT("uwidget found actually"));
		}
		//bShowMouseCursor = true;  it constrains me from looking 360 degree
	}

	ATank_CPP* ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("possesing an player tank"));
	}
	else return;
}

ATank_CPP * ATankPlayerController_CPP::GetControlledTank() const
{
	// u could also have used the unreal templated cast function but that will do
	return static_cast<ATank_CPP*>(GetPawn());
	
}
