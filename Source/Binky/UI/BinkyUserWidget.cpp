// Fill out your copyright notice in the Description page of Project Settings.


#include "BinkyUserWidget.h"

#include "Binky/UI/BinkyWidgetManager.h"

void UBinkyUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetIsFocusable(true);

	Activate();
}

void UBinkyUserWidget::NativeDestruct()
{
	Super::NativeDestruct();

	Deactivate();
}

FReply UBinkyUserWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	if (InKeyEvent.GetKey() == EKeys::Escape)
	{
		if (IsVisible())
		{
			RemoveFromParent();
			return FReply::Handled();
		}
	}
	return Super::NativeOnKeyDown(InGeometry, InKeyEvent);
}

void UBinkyUserWidget::Activate()
{
	UBinkyWidgetManager* widgetManager = UBinkyWidgetManager::GetBinkyWidgetManager(this);
	if (IsValid(widgetManager))
	{
		widgetManager->PushWidgetList(this);
	}
}

void UBinkyUserWidget::Deactivate()
{
	UBinkyWidgetManager* widgetManager = UBinkyWidgetManager::GetBinkyWidgetManager(this);
	if (IsValid(widgetManager))
	{
		widgetManager->PopWidgetList(this);
	}
}
