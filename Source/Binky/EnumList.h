// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnumList.generated.h"

/**
 * 
 */

UENUM()
enum class EMouseFocusType : uint8
{
	UIOnly = 0,
	UIandGameOnly = 1,
	GameOnly = 2
};
