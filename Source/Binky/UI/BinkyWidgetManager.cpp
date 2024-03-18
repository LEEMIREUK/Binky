// Fill out your copyright notice in the Description page of Project Settings.


#include "BinkyWidgetManager.h"

#include "Binky/UI/BinkyUserWidget.h"

#include "Binky/Frameworks/BinkyPlayerController.h"

#include "Kismet/GameplayStatics.h"

UBinkyWidgetManager* UBinkyWidgetManager::GetBinkyWidgetManager(UObject* InWorldContextObject)
{
	if (IsValid(InWorldContextObject))
	{
		UWorld* world = InWorldContextObject->GetWorld();
		if (IsValid(world))
		{
			return world->GetSubsystem<UBinkyWidgetManager>();
		}
	}
	return nullptr;
}

void UBinkyWidgetManager::Initialize(FSubsystemCollectionBase& Collection)
{
	if (!CachedWidgetList.IsEmpty())
	{
		CachedWidgetList.Empty();
	}
}

void UBinkyWidgetManager::Deinitialize()
{
	if (!CachedWidgetList.IsEmpty())
	{
		CachedWidgetList.Empty();
	}
}

void UBinkyWidgetManager::UpdateFocusByWidgetList()
{
	if (CachedWidgetList.Num() > 0)
	{
		FBinkyWidgetInfo info = CachedWidgetList.Last();
		SetInputModeWidget(info);
	}
	else
	{
		ABinkyPlayerController* binkyPlayerController = Cast<ABinkyPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
		if (IsValid(binkyPlayerController))
		{
			int32 viewportSizeX;
			int32 viewportSizeY;
			binkyPlayerController->GetViewportSize(viewportSizeX, viewportSizeY);

			binkyPlayerController->SetMouseLocation(viewportSizeX / 2, viewportSizeY / 2);

			binkyPlayerController->SetShowMouseCursor(false);

			FInputModeGameOnly InputMode;
			binkyPlayerController->SetInputMode(InputMode);

		}
	}
}

void UBinkyWidgetManager::UpdateTopByWidgetList(UBinkyUserWidget* InWidget)
{
	if (IsValid(InWidget))
	{
		
	}
}

void UBinkyWidgetManager::PushWidgetList(UBinkyUserWidget* InWidget)
{
	if (IsValid(InWidget))
	{
		FBinkyWidgetInfo info;
		info.MouseFocusType = InWidget->MouseFocusType;
		info.IsShowMouseCursor = InWidget->IsShowMouseCursor;
		info.IsMousePositionToCenter = InWidget->IsMousePositionToCenter;
		info.IsKeepMousePosition = InWidget->IsKeepMousePosition;
		info.IsHideWidgetOtherFocusWidget = InWidget->IsHideWidgetOtherFocusWidget;
		info.IsClickableWidgetOtherFocusWidget = InWidget->IsClickableWidgetOtherFocusWidget;
		info.FocusWidget = InWidget;
		
		PushWidgetData(info);
	}
}

void UBinkyWidgetManager::PopWidgetList(UBinkyUserWidget* InWidget)
{
	if (IsValid(InWidget))
	{
		FBinkyWidgetInfo info;

		for (const FBinkyWidgetInfo& v : CachedWidgetList)
		{
			if (IsValid(v.FocusWidget) && (v.FocusWidget == InWidget))
			{
				info = v;
				break;
			}
		}

		PopWidgetData(info);
	}
}

void UBinkyWidgetManager::PushWidgetData(const FBinkyWidgetInfo& InWidgetInfo)
{
	if (CachedWidgetList.Num() > 0)
	{
		FBinkyWidgetInfo& info = CachedWidgetList.Last();
		if (info.IsHideWidgetOtherFocusWidget)
		{
			info.FocusWidget->SetVisibility(ESlateVisibility::Collapsed);
		}
	}

	CachedWidgetList.Push(InWidgetInfo);
	UpdateFocusByWidgetList();
}

void UBinkyWidgetManager::PopWidgetData(const FBinkyWidgetInfo& InWidgetInfo)
{
	if (CachedWidgetList.Num() > 0)
	{
		const FBinkyWidgetInfo& info = CachedWidgetList.Last();
		if (IsValid(info.FocusWidget) && IsValid(InWidgetInfo.FocusWidget))
		{
			if (info.FocusWidget == InWidgetInfo.FocusWidget)
			{
				CachedWidgetList.Pop(true);

			}
			else
			{
				for (int32 i = CachedWidgetList.Num() - 1; i >= 0; --i)
				{
					const FBinkyWidgetInfo* infoPtr = &CachedWidgetList[i];

					if (infoPtr->FocusWidget == InWidgetInfo.FocusWidget)
					{
						CachedWidgetList.RemoveAt(i);
						break;
					}
				}
			}

			UpdateFocusByWidgetList();
		}
	}
}

void UBinkyWidgetManager::SetInputModeWidget(FBinkyWidgetInfo& InWidgetInfo)
{
	UWorld* world = IsValid(InWidgetInfo.FocusWidget) ? InWidgetInfo.FocusWidget->GetWorld() : this->GetWorld();
	if (IsValid(world))
	{
		if (IsValid(InWidgetInfo.FocusWidget))
		{
			ABinkyPlayerController* binkyPlayerController = Cast<ABinkyPlayerController>(UGameplayStatics::GetPlayerController(world, 0));
			if (IsValid(binkyPlayerController))
			{
				if (InWidgetInfo.IsMousePositionToCenter)
				{
					int32 viewportSizeX;
					int32 viewportSizeY;
					binkyPlayerController->GetViewportSize(viewportSizeX, viewportSizeY);

					binkyPlayerController->SetMouseLocation(viewportSizeX / 2, viewportSizeY / 2);

					if (InWidgetInfo.IsKeepMousePosition)
					{
						CachedWidgetList.Last().IsMousePositionToCenter = false;
					}
				}

				if (InWidgetInfo.IsHideWidgetOtherFocusWidget)
				{
					InWidgetInfo.FocusWidget->SetVisibility(ESlateVisibility::Visible);
				}

				binkyPlayerController->SetShowMouseCursor(InWidgetInfo.IsShowMouseCursor);

				switch (InWidgetInfo.MouseFocusType)
				{
				case EMouseFocusType::UIOnly:
				{
					FInputModeUIOnly InputMode;
					InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
					InputMode.SetWidgetToFocus(InWidgetInfo.FocusWidget->TakeWidget());
					binkyPlayerController->SetInputMode(InputMode);
					break;
				}
				case EMouseFocusType::UIandGameOnly:
				{
					FInputModeGameAndUI InputMode;
					InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
					InputMode.SetWidgetToFocus(InWidgetInfo.FocusWidget->TakeWidget());
					binkyPlayerController->SetInputMode(InputMode);
					break;
				}
				case EMouseFocusType::GameOnly:
				{
					FInputModeGameOnly InputMode;
					binkyPlayerController->SetInputMode(InputMode);
					break;
				}
				}
			}
		}
	}
}
