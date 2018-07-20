// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGameModeBase.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/blueprint.h"

ABattleTankGameModeBase::ABattleTankGameModeBase()
{
	static ConstructorHelpers::FClassFinder<APawn> Pawn(TEXT("Class'/Script/BattleTank.Tank_CPP'"));

	if (Pawn.Class)
	{
		DefaultPawnClass = Pawn.Class;
	}

	else;

	/////
	// tank plyer controller has been setup in bluprint to the bluprint version of the tank player conrtroller
		
}




