// Fill out your copyright notice in the Description page of Project Settings.


#include "BinkyGameState.h"
#include "Net/UnrealNetwork.h"

ABinkyGameState::ABinkyGameState(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void ABinkyGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(ABinkyGameState, RecorderPlayerState, COND_ReplayOnly);
}

void ABinkyGameState::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ABinkyGameState::SetRecorderPlayerState(class APlayerState* InPlayerState)
{
	if (RecorderPlayerState == nullptr)
	{
		RecorderPlayerState = InPlayerState;
		OnRep_ChagnedRecorderPlayerState();
	}
}

void ABinkyGameState::OnRep_ChagnedRecorderPlayerState()
{
	OnRecorderPlayerStateChangedEvent.Broadcast(RecorderPlayerState);
}
