// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGameModeBase.h"
#include"UObject/ConstructorHelpers.h"

ABattleTankGameModeBase::ABattleTankGameModeBase()
{
	static ConstructorHelpers::FClassFinder<APawn> Pawn(TEXT("Class'/Script/BattleTank.Tank_CPP'"));

	if (1)
	{
		DefaultPawnClass = Pawn.Class;
	}

	else;
		
}




