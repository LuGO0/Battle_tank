// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController_CPP.h"





void ATankPlayerController_CPP::BeginPlay()
{

	Super::BeginPlay();
	///I dont need constructor helpers as im not hard referencing assets but I will be assigning the refernce to the
	///UI widget property( which has been declared as UPROPERTY) in the blueprint class of TankPlayerController
	///Mind you the blueprint class will be setup as the default player controller

	if (UIWidget)
	{
		UserWidget = CreateWidget<UUserWidget>(this, UIWidget);

		if(1)
		{
			UserWidget->AddToViewport();
			UE_LOG(LogTemp, Warning, TEXT("uwidget found actually"));
		}
		//bShowMouseCursor = true;  it constrains me from looking 360 degree
	}

	
}






