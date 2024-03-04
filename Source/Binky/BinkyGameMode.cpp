// Copyright Epic Games, Inc. All Rights Reserved.

#include "BinkyGameMode.h"
#include "BinkyCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABinkyGameMode::ABinkyGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
