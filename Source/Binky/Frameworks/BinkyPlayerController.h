// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BinkyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BINKY_API ABinkyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ABinkyPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

public:
	UFUNCTION(BlueprintCallable)
	ABinkyPlayerState* GetBinkyPlayerState() const;

public:
	UFUNCTION(BlueprintCallable)
	void StartToRecordReplay();

	UFUNCTION(BlueprintCallable)
	void StopToRecordReplay();

	UFUNCTION(BlueprintCallable)
	bool IsStartRecordReplay();
};

UCLASS()
class BINKY_API ABinkyReplayPlayerController : public ABinkyPlayerController
{
	GENERATED_BODY()

protected:
	virtual void Tick(float DeltaSeconds) override;
	virtual void SmoothTargetViewRotation(class APawn* TargetPawn, float DeltaSeconds) override;

private:
	void UpdateRecorderPlayerState(class APlayerState* InRecorderPlayerState);

	UFUNCTION()
	void OnTargetPlayerStateChanged(class APlayerState* InPlayerState, class APawn* InNewPlayerPawn, class APawn* InOldPlayerPawn);

private:
	UPROPERTY(Transient)
	TObjectPtr<APlayerState> TargetPlayerState;
};
