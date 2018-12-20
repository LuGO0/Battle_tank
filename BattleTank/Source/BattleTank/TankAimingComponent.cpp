// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include"Tank_CPP.h"
#include "Components/StaticMeshComponent.h"
#include"Kismet/GameplayStatics.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation_, float LaunchSpeed)
{
	ATank_CPP* OwnedTank = static_cast<ATank_CPP*>(GetOwner());
	FVector BarrelLocation = OwnedTank->BarrelLocation;

	//i dont know why but it always shows no members available after get barrel ref but compiles correctly //gotcha it was because of it returned a ref to the usatic mesh component but in the tank aiming component we havent yet included the header file pertaining to ustatc mesh component so thats why intellisence wasnt showing up
	FVector StartLocation = OwnedTank->GetBarrelReference()->GetSocketLocation(TEXT("LaunchSpot"));

	FVector LaunchVelocity;
	

	if (UGameplayStatics::SuggestProjectileVelocity(

		this,
		 LaunchVelocity,
		StartLocation,
		HitLocation_,
		LaunchSpeed,
		false
	)
		)
	{
		//get safe normal does is it returns the unit vector for the input variable;
		FVector LaunchVelocityUnitVector = LaunchVelocity.GetSafeNormal();
		UE_LOG(LogTemp, Warning, TEXT("%s is aiming at : %s from %s at %f at unit vector %s"), *GetOwner()->GetName(), *(HitLocation_.ToString()), *StartLocation.ToString(), LaunchSpeed,*LaunchVelocityUnitVector.ToString());
	
		MoveBarrel();
	}
}

void UTankAimingComponent::MoveBarrel()
{
	//TODO pseudocode movebarrel
	//get the barrel ref
	//then rotate it along the pitch the desired amount ;
	//for that get the current pitch and the desired pitch and then move the desired amount
	//since yaw will be taken care of by the turret rotation;
}