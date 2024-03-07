// Fill out your copyright notice in the Description page of Project Settings.


#include "BinkyInputProcessor.h"
#include "Binky/Frameworks/BinkyPlayerController.h"

#include "Kismet/GameplayStatics.h"

void FBinkyInputProcessor::Tick(const float DeltaTime, FSlateApplication& SlateApp, TSharedRef<ICursor> Cursor)
{
}

bool FBinkyInputProcessor::HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent)
{
	if (!CachedWorldContextObject.IsValid())
	{
		return false;
	}

	if (InKeyEvent.GetKey() == EKeys::Escape)
	{
		OnInputKeyDownEvent.Broadcast();
		//ABinkyPlayerController* binkyPlayerController = Cast<ABinkyPlayerController>(UGameplayStatics::GetPlayerController(CachedWorldContextObject.Get(), 0));
		//if (IsValid(binkyPlayerController))
		//{
		//	Delegate?
		//	
		//	binkyPlayerController->InputESCMenu();
		//}
		return true;
	}
	return false;
}

bool FBinkyInputProcessor::HandleKeyUpEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent)
{
	if (InKeyEvent.GetKey() == EKeys::Escape)
	{
		return true;
	}
	return false;
}
