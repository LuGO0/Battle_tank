// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController_CPP.h"
#include "Tank_CPP.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "Classes/AIController.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Controller.h"
#include"Camera/PlayerCameraManager.h"


//////////////////////////  i learnt something of the design element of c++ that is chaining the bool functions to track down exceptions
///////////////////////////    couldve used exceptions as well


ATankPlayerController_CPP::ATankPlayerController_CPP()
{
	//constructor
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
			//UE_LOG(LogTemp, Warning, TEXT("uwidget found actually"));
		}
		//bShowMouseCursor = true;  it constrains me from looking 360 degree
	}

	ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("possesing an player TANK :%s"), *ControlledTank->GetName());
	}
	else return;
}

void ATankPlayerController_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimAtCrossHair();
}

ATank_CPP * ATankPlayerController_CPP::GetControlledTank() const
{
	// u could also have used the unreal templated cast function but that will do
	return static_cast<ATank_CPP*>(GetPawn());
	
}


void ATankPlayerController_CPP::AimAtCrossHair()
{
	if (!ControlledTank) { return; }
	
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		ControlledTank->DelegateToAimingComponent(HitLocation);

	}
	
	//get the world location of the line trace through the crosshair
	//most dii=fficult part tell the possessed tank to aim at this point and maybe move the barrel accordingly

}

bool ATankPlayerController_CPP::GetSightRayHitLocation(FVector& HitLocation) const
{
	

	//find the crossshair location
	int32 ViewportSizeX, ViewportSizeY;

	//getting the viewport size
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	float CrosshairXLocation = 0.5, CrosshairYLocation=0.333333;

	FVector2D CrosshairViewportLocation;

	CrosshairViewportLocation.X = ViewportSizeX * CrosshairXLocation;
	CrosshairViewportLocation.Y = ViewportSizeY * CrosshairYLocation;

	FVector CrosshairDirection;
	FVector CameraWorldLocation;
	
	if (GetCrossHairDirection(CrosshairViewportLocation, CrosshairDirection, CameraWorldLocation))
	{
		//line trace along that direction ,we see what we hit
		FHitResult HitResult;
		
		FVector StartLocation = PlayerCameraManager->GetCameraLocation();
		FVector EndLocation = StartLocation + (CrosshairDirection*LineTraceRange);
		if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
			//two defaulted params
			)
		{
			HitLocation = HitResult.Location;
			return true;
		}
		else
		{
			HitLocation = FVector(0);
			return true;
		}
	}
		else
		{
			return false;
		}
}

bool ATankPlayerController_CPP::GetCrossHairDirection(FVector2D& CrosshairViewportLocation_,FVector& CrosshairDirection_,FVector& CameraWorldLocation_) const
{
	return DeprojectScreenPositionToWorld(CrosshairViewportLocation_.X, CrosshairViewportLocation_.Y, CameraWorldLocation_, CrosshairDirection_);
	// Deprojecting the screen to the world
}