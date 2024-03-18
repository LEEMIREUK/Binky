// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Binky/EnumList.h"
#include "BinkyUserWidget.generated.h"

/**
 * 
 */

UCLASS()
class BINKY_API UBinkyUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

public:
	UPROPERTY(EditAnywhere)
	EMouseFocusType MouseFocusType;

	UPROPERTY(EditAnywhere)
	bool IsShowMouseCursor;

	UPROPERTY(EditAnywhere)
	bool IsMousePositionToCenter;

	UPROPERTY(EditAnywhere)
	bool IsKeepMousePosition;

	UPROPERTY(EditAnywhere)
	bool IsHideWidgetOtherFocusWidget;

	UPROPERTY(EditAnywhere)
	bool IsClickableWidgetOtherFocusWidget;

public:
	void Activate();
	void Deactivate();
};
