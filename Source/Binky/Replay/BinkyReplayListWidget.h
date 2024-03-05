// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "BinkyReplayListWidget.generated.h"

/**
 * 
 */

 class INetworkReplayStreamer;
 class UBinkyReplayList;
 class UBinkyReplayListEntry;
 struct FEnumerateStreamsResult;

UCLASS()
class BINKY_API UBinkyReplayListWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UListView* Bind_ListView_ReplayList;

private:
	void ExecuteSearchReplayList();

	void OnEnumerateStreamsComplete(const FEnumerateStreamsResult& InCallback);

	void UpdateReplayList();

private:
	UPROPERTY() 
	TObjectPtr<UBinkyReplayList> ReplayList;

	TSharedPtr<INetworkReplayStreamer> ReplayStreamer;
};

UCLASS()
class BINKY_API UBinkyReplayListEntryWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	virtual void NativeOnListItemObjectSet(UObject* InListItemObject) override;

public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* Bind_Text_ReplayName;

public:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UBinkyReplayListEntry> ReplayListEntry;
};