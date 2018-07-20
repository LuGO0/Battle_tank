// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "TankPlayerController_CPP.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController_CPP : public APlayerController
{
	GENERATED_BODY()
	
	public:
		virtual void BeginPlay() override;

		////it has to be public i dont know why
		UPROPERTY(EditAnywhere,BlueprintReadOnly)
		TSubclassOf<class UUserWidget> UIWidget;

		//object pointer used to stroe the instance of the above class
		UUserWidget* UserWidget;
		
};
