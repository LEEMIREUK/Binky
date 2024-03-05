// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "NetworkReplayStreaming.h"
#include "BinkyReplaySubsystem.generated.h"

/**
 * 
 */

UCLASS()
class BINKY_API UBinkyReplaySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Replay)
	void StartRecordReplay(APlayerController* InPlayerController);

	UFUNCTION(BlueprintCallable, Category = Replay)
	void StopRecordReplay();

	UFUNCTION(BlueprintCallable, Category = Replay)
	void PlayReplay(class UBinkyReplayListEntry* InReplay);
};

UCLASS(BlueprintType)
class BINKY_API UBinkyReplayListEntry : public UObject
{
	GENERATED_BODY()

public:
	FNetworkReplayStreamInfo StreamInfo;

	UFUNCTION(BlueprintPure, Category = Replay)
	FString GetFriendlyName() const { return StreamInfo.FriendlyName; }

	UFUNCTION(BlueprintPure, Category = Replays)
	FDateTime GetTimestamp() const { return StreamInfo.Timestamp; }

	UFUNCTION(BlueprintPure, Category = Replays)
	FTimespan GetDuration() const { return FTimespan::FromMilliseconds(StreamInfo.LengthInMS); }

	UFUNCTION(BlueprintPure, Category = Replays)
	int32 GetNumViewers() const { return StreamInfo.NumViewers; }
};

UCLASS(BlueprintType)
class BINKY_API UBinkyReplayList: public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = Replay)
	TArray<TObjectPtr<UBinkyReplayListEntry>> ReplayList;
};
