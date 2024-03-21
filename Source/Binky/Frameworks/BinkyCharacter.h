// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "AbilitySystemInterface.h"
#include "BinkyCharacter.generated.h"

class UGameplayEffect;
class UBinkyGameplayAbility;
class UBinkyAttributeSet;
class UBinkyAbilitySystemComponent;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class ABinkyCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ABinkyCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual void BeginPlay();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	virtual void InitializeAttributes();
	virtual void GiveDefaultAbilities();

public:
	UFUNCTION(BlueprintCallable)
	class ABinkyPlayerController* GetBinkyPlayerController() const;

	UFUNCTION(BlueprintCallable)
	class ABinkyPlayerState* GetBinkyPlayerState() const;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBinkyAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<UBinkyAttributeSet> Attributes;

public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Attributes)
	TSubclassOf<UGameplayEffect> DefaultAttributeEffect;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Attributes)
	TArray<TSubclassOf<UBinkyGameplayAbility>> DefaultAbilities;

public:
	UBinkyAbilitySystemComponent* GetBinkyAbilitySystemComponent();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Attributes)
	int MaxHealth = 100;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Attributes)
	int MaxMana = 100;

protected:
	void ESCMenu();
};

