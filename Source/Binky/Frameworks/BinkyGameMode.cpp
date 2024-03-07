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
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Binky/Blueprints/BP_Character"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/Binky/Blueprints/BP_PlayerController"));
	if (PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}

	GameStateClass = ABinkyGameState::StaticClass();
	ReplaySpectatorPlayerControllerClass = ABinkyReplayPlayerController::StaticClass();
	PlayerStateClass = ABinkyPlayerState::StaticClass();
}
