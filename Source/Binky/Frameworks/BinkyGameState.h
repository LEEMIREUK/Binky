// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "BinkyGameState.generated.h"

/**
 * 
 */
UCLASS()
class BINKY_API ABinkyGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ABinkyGameState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void Tick(float DeltaSeconds) override;

public:
	class APlayerState* GetRecorderPlayerState() const { return RecorderPlayerState; }
	void SetRecorderPlayerState(class APlayerState* InPlayerState);

	DECLARE_MULTICAST_DELEGATE_OneParam(FOnRecorderPlayerStateChanged, class APlayerState*);
	FOnRecorderPlayerStateChanged OnRecorderPlayerStateChangedEvent;

	UFUNCTION()
	void OnRep_ChagnedRecorderPlayerState();

private:
	UPROPERTY(Transient, ReplicatedUsing = OnRep_ChagnedRecorderPlayerState)
	TObjectPtr<class APlayerState> RecorderPlayerState;
};
