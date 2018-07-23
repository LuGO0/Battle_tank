// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController_CPP.h"
#include "Blueprint/UserWidget.h"




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
}

ATank_CPP * ATankPlayerController_CPP::GetControlledTank() const
{/*
	return static_cast<ATank_CPP*>(GetPawn());*/
	// u could also have used the unreal templated cast function but that will do
	return nullptr;
}
