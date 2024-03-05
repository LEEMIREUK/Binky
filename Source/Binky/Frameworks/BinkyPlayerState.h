// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "BinkyPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class BINKY_API ABinkyPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	ABinkyPlayerState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};
