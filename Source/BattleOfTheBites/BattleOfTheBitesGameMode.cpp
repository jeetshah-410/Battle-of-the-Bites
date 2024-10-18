// Copyright Epic Games, Inc. All Rights Reserved.

#include "BattleOfTheBitesGameMode.h"
#include "BattleOfTheBitesCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABattleOfTheBitesGameMode::ABattleOfTheBitesGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ABattleOfTheBitesGameMode::PawnKilled(APawn* PawnKilled)
{
}
