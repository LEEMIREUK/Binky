// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Binky/UI/BinkyUserWidget.h"
#include "BinkyESCMenuWidget.generated.h"

/**
 * 
 */

 class UButton;
 class UBinkyReplayListWidget;

UCLASS()
class BINKY_API UBinkyESCMenuWidget : public UBinkyUserWidget
{
	GENERATED_BODY()
	
protected:
	//virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> Bind_Button_InGame;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> Bind_Button_Replay;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> Bind_Button_Exit;

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UBinkyReplayListWidget> ReplayListWidgetClass;

private:
	UPROPERTY()
	TObjectPtr<UBinkyReplayListWidget> ReplayListWidget;

public:
	UFUNCTION(BlueprintCallable)
	void ReturnInGame();

	UFUNCTION(BlueprintCallable)
	void ShowReplayList();

	UFUNCTION(BlueprintCallable)
	void StopPlayInEditor();
};
