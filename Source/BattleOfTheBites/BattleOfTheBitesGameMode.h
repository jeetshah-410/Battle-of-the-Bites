// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BattleOfTheBitesGameMode.generated.h"

UCLASS(minimalapi)
class ABattleOfTheBitesGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABattleOfTheBitesGameMode();

	virtual void PawnKilled(APawn* PawnKilled);
};



