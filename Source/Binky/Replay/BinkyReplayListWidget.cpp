// Fill out your copyright notice in the Description page of Project Settings.


#include "BinkyReplayListWidget.h"

#include "Binky/Replay/BinkyReplaySubsystem.h"

#include "NetworkReplayStreaming.h"
#include "Components/ListView.h"
#include "Components/TextBlock.h"

void UBinkyReplayListWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ExecuteSearchReplayList();
}

void UBinkyReplayListWidget::ExecuteSearchReplayList()
{
	ReplayStreamer = FNetworkReplayStreaming::Get().GetFactory().CreateReplayStreamer();

	ReplayList = NewObject<UBinkyReplayList>();
	if (ReplayStreamer.IsValid())
	{
		FNetworkReplayVersion replayVersion = FNetworkVersion::GetReplayVersion();
		ReplayStreamer->EnumerateStreams(replayVersion, INDEX_NONE, FString(), TArray<FString>(), FEnumerateStreamsCallback::CreateUObject(this, &UBinkyReplayListWidget::OnEnumerateStreamsComplete));
	}
	else
	{
		UpdateReplayList();
	}
}

void UBinkyReplayListWidget::OnEnumerateStreamsComplete(const FEnumerateStreamsResult& InCallback)
{
	for(const FNetworkReplayStreamInfo& info : InCallback.FoundStreams)
	{
		UBinkyReplayListEntry* replayEntry = NewObject<UBinkyReplayListEntry>(ReplayList);
		replayEntry->StreamInfo = info;
		ReplayList->ReplayList.Add(replayEntry);
	}

	Algo::SortBy(ReplayList->ReplayList, [](const TObjectPtr<UBinkyReplayListEntry>& Data) { return Data->StreamInfo.Timestamp.GetTicks(); }, TGreater<>());

	UpdateReplayList();
}

void UBinkyReplayListWidget::UpdateReplayList()
{
	Bind_ListView_ReplayList->SetListItems(ReplayList->ReplayList);
}

void UBinkyReplayListEntryWidget::NativeOnListItemObjectSet(UObject* InListItemObject)
{
	UBinkyReplayListEntry* replayListEntry = Cast<UBinkyReplayListEntry>(InListItemObject);
	UBinkyReplayListEntry* replayListEntry22 = NewObject<UBinkyReplayListEntry>(InListItemObject);

	if (IsValid(replayListEntry))
	{
		FText replayName = FText::Format(FText::FromString(TEXT("{0} {1}")), FText::FromString(replayListEntry->GetFriendlyName()), FText::AsTimespan(replayListEntry->GetDuration()));
		Bind_Text_ReplayName->SetText(replayName);

		ReplayListEntry = replayListEntry;
	}
}
