// Fill out your copyright notice in the Description page of Project Settings.


#include "BinkyPlayerController.h"

#include "Binky/Frameworks/BinkyGameState.h"
#include "Binky/Frameworks/BinkyPlayerState.h"
#include "Binky/Frameworks/BinkyGameInstance.h"

#include "Binky/Replay/BinkyReplaySubsystem.h"

#include "Binky/UI/BinkyESCMenuWidget.h"
#include "Binky/UI/BinkyWidgetManager.h"

#include "Binky/Tool/BinkyInputProcessor.h"

#include "ReplaySubsystem.h"

ABinkyPlayerController::ABinkyPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void ABinkyPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ABinkyPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void ABinkyPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void ABinkyPlayerController::OnUnPossess()
{
	Super::OnUnPossess();
}

ABinkyPlayerState* ABinkyPlayerController::GetBinkyPlayerState() const
{
	return CastChecked<ABinkyPlayerState>(PlayerState, ECastCheckedType::NullAllowed);
}

void ABinkyPlayerController::InputESCMenu()
{
	if (!IsValid(ESCMenuWidget.Get()))
	{
		ESCMenuWidget = CreateWidget<UBinkyESCMenuWidget>(this, ESCMenuWidgetClass);
	}

	if (IsValid(ESCMenuWidget.Get()))
	{
		if (!ESCMenuWidget->IsVisible())
		{
			ESCMenuWidget->AddToViewport();
		}
	}
}

void ABinkyPlayerController::StartToRecordReplay()
{
	if (GetWorld()->IsNetMode(NM_DedicatedServer))
	{
		if (IsStartRecordReplay())
		{
			UBinkyReplaySubsystem* binkyReplaySubSystem = GetGameInstance()->GetSubsystem<UBinkyReplaySubsystem>();
			if (IsValid(binkyReplaySubSystem))
			{
				ABinkyGameState* binkyGameState = Cast<ABinkyGameState>(GetWorld()->GetGameState());
				if (IsValid(binkyGameState))
				{
					binkyGameState->SetRecorderPlayerState(PlayerState);

					binkyReplaySubSystem->StartRecordReplay(this);
				}
			}
		}
	}
}

void ABinkyPlayerController::StopToRecordReplay()
{
	if (GetWorld()->IsNetMode(NM_DedicatedServer))
	{
		UBinkyReplaySubsystem* binkyReplaySubSystem = GetGameInstance()->GetSubsystem<UBinkyReplaySubsystem>();
		if (IsValid(binkyReplaySubSystem))
		{
			binkyReplaySubSystem->StopRecordReplay();
		}
	}
}

bool ABinkyPlayerController::IsStartRecordReplay()
{
	UReplaySubsystem* replaySubSystem = GetGameInstance()->GetSubsystem<UReplaySubsystem>();
	if(IsValid(replaySubSystem))
	{
		if (replaySubSystem->IsRecording() || replaySubSystem->IsPlaying())
		{
			return false;
		}
	}
	return true;
}

void ABinkyReplayPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (!IsValid(TargetPlayerState))
	{
		ABinkyGameState* binkyGameState = Cast<ABinkyGameState>(GetWorld()->GetGameState());
		if (IsValid(binkyGameState))
		{
			if (!binkyGameState->OnRecorderPlayerStateChangedEvent.IsBoundToObject(this))
			{
				binkyGameState->OnRecorderPlayerStateChangedEvent.AddUObject(this, &ABinkyReplayPlayerController::UpdateRecorderPlayerState);
			}

			if (IsValid(binkyGameState->GetRecorderPlayerState()))
			{
				UpdateRecorderPlayerState(binkyGameState->GetRecorderPlayerState());
			}
		}
	}
}

void ABinkyReplayPlayerController::SmoothTargetViewRotation(APawn* TargetPawn, float DeltaSeconds)
{
	Super::SmoothTargetViewRotation(TargetPawn, DeltaSeconds);
}

void ABinkyReplayPlayerController::UpdateRecorderPlayerState(class APlayerState* InRecorderPlayerState)
{
	if (IsValid(InRecorderPlayerState))
	{
		TargetPlayerState = InRecorderPlayerState;

		InRecorderPlayerState->OnPawnSet.AddUniqueDynamic(this, &ABinkyReplayPlayerController::OnTargetPlayerStateChanged);
		OnTargetPlayerStateChanged(InRecorderPlayerState, InRecorderPlayerState->GetPawn(), nullptr);
	}
}

void ABinkyReplayPlayerController::OnTargetPlayerStateChanged(class APlayerState* InPlayerState, APawn* InNewPlayerPawn, APawn* InOldPlayerPawn)
{
	if (InPlayerState == TargetPlayerState)
	{
		SetViewTarget(InNewPlayerPawn);
	}
}
