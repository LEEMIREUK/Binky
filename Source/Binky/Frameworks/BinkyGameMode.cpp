// Copyright Epic Games, Inc. All Rights Reserved.

#include "BinkyGameMode.h"
#include "BinkyCharacter.h"
#include "BinkyPlayerController.h"
#include "BinkyPlayerState.h"
#include "BinkyGameState.h"

#include "UObject/ConstructorHelpers.h"

ABinkyGameMode::ABinkyGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	GameStateClass = ABinkyGameState::StaticClass();
	PlayerControllerClass = ABinkyPlayerController::StaticClass();
	ReplaySpectatorPlayerControllerClass = ABinkyReplayPlayerController::StaticClass();
	PlayerStateClass = ABinkyPlayerState::StaticClass();
}
