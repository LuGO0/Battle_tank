// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank_CPP.h"
#include"UObject/ConstructorHelpers.h"
#include"Components/StaticMeshComponent.h"
#include"Engine/EngineTypes.h"


// Sets default values
ATank_CPP::ATank_CPP()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ATank_CPP::Barrel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Barrel"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BarrelAsset(TEXT("StaticMesh'/Game/Custom_Assets/Tank_mesh/tank_fbx_Barrel.tank_fbx_Barrel'"));
	if (BarrelAsset.Object)
		Barrel->SetStaticMesh(BarrelAsset.Object);

	ATank_CPP::Track_01 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Track_01"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Track_01_Asset(TEXT("StaticMesh'/Game/Custom_Assets/Tank_mesh/tank_fbx_Track.tank_fbx_Track'"));
	if (Track_01_Asset.Object)
		Track_01->SetStaticMesh(Track_01_Asset.Object);


	ATank_CPP::Track_02 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Track_02"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Track_02_Asset(TEXT("StaticMesh'/Game/Custom_Assets/Tank_mesh/tank_fbx_Track.tank_fbx_Track'"));
	if (Track_02_Asset.Object)
		Track_02->SetStaticMesh(Track_02_Asset.Object);


	ATank_CPP::Turret = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> TurretAsset(TEXT("StaticMesh'/Game/Custom_Assets/Tank_mesh/tank_fbx_Turret.tank_fbx_Turret'"));
	if (TurretAsset.Object)
	Turret->SetStaticMesh(TurretAsset.Object);

	///adding tank body to the default pawn
	ATank_CPP::TankBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TankBody"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> TankBodyAsset(TEXT("StaticMesh'/Game/Custom_Assets/Tank_mesh/tank_fbx_Body.tank_fbx_Body'"));
	if (TankBodyAsset.Object)
	{
		ATank_CPP::TankBody->SetStaticMesh(TankBodyAsset.Object);
		ATank_CPP::Turret->AttachToComponent(TankBody, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false),TEXT("turret"));
		ATank_CPP::Barrel->AttachToComponent(Turret, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false), TEXT("barrel"));
		ATank_CPP::Track_01->AttachToComponent(TankBody, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false), TEXT("track_01"));
		ATank_CPP::Track_02->AttachToComponent(TankBody, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false), TEXT("track_02"));
	}
	
}

// Called when the game starts or when spawned
void ATank_CPP::BeginPlay()
{
	Super::BeginPlay();
	
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

}

