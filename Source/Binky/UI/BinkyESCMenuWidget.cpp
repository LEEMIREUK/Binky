// Fill out your copyright notice in the Description page of Project Settings.


#include "BinkyESCMenuWidget.h"

#include "Binky/Frameworks/BinkyPlayerController.h"

#include "Binky/Replay/BinkyReplayListWidget.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UBinkyESCMenuWidget::ReturnInGame()
{
	ABinkyPlayerController* binkyPlayerController = Cast<ABinkyPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (IsValid(binkyPlayerController))
	{
		binkyPlayerController->InputESCMenu();
	}
}

void UBinkyESCMenuWidget::ShowReplayList()
{
	if (!IsValid(ReplayListWidget))
	{
		ReplayListWidget = CreateWidget<UBinkyReplayListWidget>(this, ReplayListWidgetClass);
	}

	ReplayListWidget->AddToViewport();
}

void UBinkyESCMenuWidget::StopPlayInEditor()
{
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}
