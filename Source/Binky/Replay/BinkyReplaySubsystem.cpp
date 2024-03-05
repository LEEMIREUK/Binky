// Fill out your copyright notice in the Description page of Project Settings.


#include "BinkyReplaySubsystem.h"
#include "Binky/Frameworks/BinkyGameInstance.h"

void UBinkyReplaySubsystem::StartRecordReplay(APlayerController* InPlayerController)
{
	if (IsValid(InPlayerController))
	{
		UBinkyGameInstance* binkyGameInstance = GetWorld()->GetGameInstance<UBinkyGameInstance>();
		if (IsValid(binkyGameInstance))
		{
			FText friendlyName = FText::Format(FText::FromString(TEXT("Binky's Replay {0}")), FText::AsDateTime(FDateTime::UtcNow(), EDateTimeStyle::Short, EDateTimeStyle::Short));
			binkyGameInstance->StartRecordingReplay(FString(), friendlyName.ToString());
		}
	}
}

void UBinkyReplaySubsystem::StopRecordReplay()
{
	UBinkyGameInstance* binkyGameInstance = GetWorld()->GetGameInstance<UBinkyGameInstance>();
	if (IsValid(binkyGameInstance))
	{
		binkyGameInstance->StopRecordingReplay();
	}
}

void UBinkyReplaySubsystem::PlayReplay(class UBinkyReplayListEntry* InReplay)
{
	if (IsValid(InReplay))
	{
		UBinkyGameInstance* binkyGameInstance = GetWorld()->GetGameInstance<UBinkyGameInstance>();
		if (IsValid(binkyGameInstance))
		{
			FString demoName = InReplay->StreamInfo.Name;
			binkyGameInstance->PlayReplay(demoName);
		}
	}
}
