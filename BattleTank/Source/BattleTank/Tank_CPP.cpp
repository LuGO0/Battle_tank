// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank_CPP.h"
#include "Components/StaticMeshComponent.h"
#include "Misc/App.h"
#include "Engine/World.h"
#include "Engine/EngineTypes.h"
#include "crtdbg.h"
#include "UObject/ConstructorHelpers.h"
#include"Classes/AIController.h"



///////// WARNING !!!!!!!!!!!!!!!! HARD CODED REFERENCE ;( !!!!!!!  i will take care of that from the next project :]



// Sets default values
ATank_CPP::ATank_CPP()
{
	//setting up the tank aiming component
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(TEXT("Aiming Component"));

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/////############################################################################////////////////
	//#######    above all these things here uobject finder is only returning a    ######////////////
	//###############     uclass so maybe uclass finder would have been a better choice #######//////
	
	
	//setting up AI debug macro
	static ConstructorHelpers::FClassFinder<AAIController> AIController(TEXT("Class'/Script/BattleTank.TankAIController_CPP'"));
	if (AIController.Class)
	{
		AIControllerClass = AIController.Class;
		AutoPossessAI = EAutoPossessAI::PlacedInWorld;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller asset problem"));
	}



	
	///getting a reference to the barrel asset
	ATank_CPP::Barrel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Barrel"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BarrelAsset(TEXT("StaticMesh'/Game/Custom_Assets/Tank_mesh/tank_fbx_Barrel.tank_fbx_Barrel'"));
	if (BarrelAsset.Object)
	{
			Barrel->SetStaticMesh(BarrelAsset.Object);
	}


	///getting a reference to the track asset
	ATank_CPP::Track_01 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Track_01"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Track_01_Asset(TEXT("StaticMesh'/Game/Custom_Assets/Tank_mesh/tank_fbx_Track.tank_fbx_Track'"));
	if (Track_01_Asset.Object)
	{
		Track_01->SetStaticMesh(Track_01_Asset.Object);
	}

	///getting a reference to the track asset
	ATank_CPP::Track_02 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Track_02"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Track_02_Asset(TEXT("StaticMesh'/Game/Custom_Assets/Tank_mesh/tank_fbx_Track.tank_fbx_Track'"));
	if (Track_02_Asset.Object)
	{
		Track_02->SetStaticMesh(Track_02_Asset.Object);
	}

	///getting a reference to the turret asset
	ATank_CPP::Turret = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> TurretAsset(TEXT("StaticMesh'/Game/Custom_Assets/Tank_mesh/tank_fbx_Turret.tank_fbx_Turret'"));
	if (TurretAsset.Object)
	{
		Turret->SetStaticMesh(TurretAsset.Object);
	}

	///creating a spring arm component
	ATank_CPP::SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("camera stick"));

	///creating a camera componennt
	ATank_CPP::Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("camera"));
	
	
	
	///adding tank body to the default pawn as the root component
	ATank_CPP::TankBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TankBody"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> TankBodyAsset(TEXT("StaticMesh'/Game/Custom_Assets/Tank_mesh/tank_fbx_Body.tank_fbx_Body'"));
	if (TankBodyAsset.Object)
	{
		//setting the root component
		ATank_CPP::TankBody->SetStaticMesh(TankBodyAsset.Object);
		RootComponent = TankBody;
		ATank_CPP::TankBody->SetSimulatePhysics(true);

		///attaching various static meshes to their respective sockets
		ATank_CPP::Turret->AttachToComponent(TankBody, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false),TEXT("turret"));
		ATank_CPP::Barrel->AttachToComponent(Turret, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false), TEXT("barrel"));
		ATank_CPP::Track_01->AttachToComponent(TankBody, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false), TEXT("track_01"));
		ATank_CPP::Track_02->AttachToComponent(TankBody, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false), TEXT("track_02"));
		

		///configuring the spring arm
		ATank_CPP::SpringArm->SetupAttachment(Turret);
		ATank_CPP::SpringArm->RelativeRotation = FRotator(-19.0f, 0, 0);
		ATank_CPP::SpringArm->TargetArmLength = 800.0f;
		ATank_CPP::SpringArm->bEnableCameraLag = true;
		ATank_CPP::SpringArm->CameraLagSpeed = 3.0f;


		//attaching camera to the spring arm
		ATank_CPP::Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	}
}
//constructors finally over


// Called when the game starts or when spawned
void ATank_CPP::BeginPlay()
{
	Super::BeginPlay();
	BarrelLocation = Barrel->GetComponentLocation();
	LaunchSpot = Barrel->GetSocketLocation(TEXT("LaunchSpot"));
}

// Called every frame
void ATank_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATank_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("AimAzimuth",this,&ATank_CPP::SetSpringArmAzimuthAngle);
	PlayerInputComponent->BindAxis("AimAltitude", this, &ATank_CPP::SetSpringArmAltitudeAngle);


}

///this is the delegate function which was bound to Aim Azimuth mind it it needs the function s signature to be exactly as this;
void ATank_CPP::SetSpringArmAzimuthAngle(float AxisValue)
{
	
	//_ASSERTE( GetInputAxisValue("AimAzimuth")==AxisValue);
	SpringArmRotation.X = AxisValue;
	FRotator SpringArmTickRotation = SpringArm->GetComponentRotation();
	SpringArmTickRotation.Yaw += SpringArmRotation.X;
	SpringArm->SetWorldRotation(SpringArmTickRotation);
	

	//TODO find a way to setup spring arms yaw according to the input
}

void ATank_CPP::SetSpringArmAltitudeAngle(float AxisValue)
{
	SpringArmRotation.Y = AxisValue;
	FRotator SpringArmTickRotation = SpringArm->GetComponentRotation();
	SpringArmTickRotation.Pitch += SpringArmRotation.Y;
	SpringArm->SetWorldRotation(SpringArmTickRotation);
	//TODO find a way to setup spring arm pitch according to the input axis values
}


void ATank_CPP::DelegateToAimingComponent(FVector HitLocation_)
{
	TankAimingComponent->AimAt(HitLocation_,this->LaunchSpeed);
}

UStaticMeshComponent* ATank_CPP::GetBarrelReference()
{
	return Barrel;
}
