// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank_CPP.h"
#include "TankPlayerController_CPP.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController_CPP : public APlayerController
{
	GENERATED_BODY()
	
	public:
		///player controller constructor
		ATankPlayerController_CPP();

		///begin play method from player controllers parent
		virtual void BeginPlay() override;

		////it has to be public i dont know why
		UPROPERTY(EditAnywhere,BlueprintReadWrite)               // either include this class keyword so that the compiler knows that this is a class
		TSubclassOf<class UUserWidget> UIWidget;                //or include the header file which includes the declaration for this class
		                                                         //in this header file that is the file "Blueprint/UserWidget.h"                                                           
		//object pointer used to store the instance of the above class
		UUserWidget* UserWidget;

		//get the tank this tank player controller is posssessing
		ATank_CPP* GetControlledTank() const;
};
