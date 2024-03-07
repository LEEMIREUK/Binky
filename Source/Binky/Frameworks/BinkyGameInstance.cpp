// Fill out your copyright notice in the Description page of Project Settings.


#include "BinkyGameInstance.h"
#include "Binky/Tool/BinkyInputProcessor.h"

#include "Framework/Application/SlateApplication.h"

UBinkyGameInstance::UBinkyGameInstance(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/) : Super(ObjectInitializer)
{

}

void UBinkyGameInstance::Init()
{
	Super::Init();

	if (!GetWorld()->IsNetMode(NM_DedicatedServer))
	{
		InputProcessor = MakeShared<FBinkyInputProcessor>();
		FSlateApplication::Get().RegisterInputPreProcessor(InputProcessor, 0);
	}
}

void UBinkyGameInstance::Shutdown()
{
	if (!GetWorld()->IsNetMode(NM_DedicatedServer))
	{
		if (InputProcessor.IsValid())
		{
			FSlateApplication::Get().UnregisterInputPreProcessor(InputProcessor);
		}
	}

	Super::Shutdown();
}
