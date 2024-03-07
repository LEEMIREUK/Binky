// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Framework/Application/IInputProcessor.h"

/**
 * 
 */
class BINKY_API FBinkyInputProcessor : public IInputProcessor
{
public:
	FBinkyInputProcessor() {};
	virtual ~FBinkyInputProcessor() {}

	virtual void Tick(const float DeltaTime, FSlateApplication& SlateApp, TSharedRef<ICursor> Cursor) override;
	virtual bool HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent) override;
	virtual bool HandleKeyUpEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent) override;

public:
	DECLARE_MULTICAST_DELEGATE(FOnInputKeyDownEvent);
	FOnInputKeyDownEvent OnInputKeyDownEvent;

private:
	UPROPERTY()
	TWeakObjectPtr<UObject> CachedWorldContextObject = nullptr;
};
