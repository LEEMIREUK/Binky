// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BinkyGameInstance.generated.h"

/**
 * 
 */

class FBinkyInputProcessor;

UCLASS()
class BINKY_API UBinkyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UBinkyGameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual void Init() override;
	virtual void Shutdown() override;

public:
	TSharedPtr<FBinkyInputProcessor> InputProcessor;
};
