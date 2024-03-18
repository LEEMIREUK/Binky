// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Binky/EnumList.h"
#include "BinkyWidgetManager.generated.h"

/**
 * 
 */

class UBinkyUserWidget;

USTRUCT(BlueprintType)
struct BINKY_API FBinkyWidgetInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	EMouseFocusType MouseFocusType;

	UPROPERTY(BlueprintReadOnly)
	bool IsShowMouseCursor;

	UPROPERTY(BlueprintReadOnly)
	bool IsMousePositionToCenter;

	// If update widget, True is keep current MousePosition
	UPROPERTY(BlueprintReadOnly)
	bool IsKeepMousePosition;

	// When other widget focus, Hiding this widget
	UPROPERTY(BlueprintReadOnly)
	bool IsHideWidgetOtherFocusWidget;

	// When the widget is not on top, Can click and changed top.
	UPROPERTY(BlueprintReadOnly)
	bool IsClickableWidgetOtherFocusWidget;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UBinkyUserWidget> FocusWidget;
};

UCLASS()
class BINKY_API UBinkyWidgetManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	static UBinkyWidgetManager* GetBinkyWidgetManager(UObject* InWorldContextObject);
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

public:
	void UpdateFocusByWidgetList();
	void UpdateTopByWidgetList(UBinkyUserWidget* InWidget);

	void PushWidgetList(UBinkyUserWidget* InWidget);
	void PopWidgetList(UBinkyUserWidget* InWidget);

private:
	void PushWidgetData(const FBinkyWidgetInfo& InWidgetInfo);
	void PopWidgetData(const FBinkyWidgetInfo& InWidgetInfo);

	void SetInputModeWidget(FBinkyWidgetInfo& InWidgetInfo);

private:
	UPROPERTY()
	TArray<FBinkyWidgetInfo> CachedWidgetList;
};
