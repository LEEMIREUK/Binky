// Copyright Epic Games, Inc. All Rights Reserved.

#include "BinkyCharacter.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/Controller.h"

#include "Binky/Frameworks/BinkyPlayerController.h"
#include "Binky/Frameworks/BinkyPlayerState.h"

#include "Binky/Abilities/BinkyGameplayAbility.h"
#include "Binky/Abilities/BinkyAttributeSet.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ABinkyCharacter

ABinkyCharacter::ABinkyCharacter(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/) : Super(ObjectInitializer)
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	Attributes = CreateDefaultSubobject<UBinkyAttributeSet>("Attributes");
}

void ABinkyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ABinkyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (IsValid(AbilitySystemComponent))
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}

	InitializeAttributes();
	GiveDefaultAbilities();
}

void ABinkyCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	if (IsValid(AbilitySystemComponent))
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}

	InitializeAttributes();
}

void ABinkyCharacter::InitializeAttributes()
{
	if (IsValid(AbilitySystemComponent) && IsValid(DefaultAttributeEffect))
	{
		FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
		EffectContext.AddSourceObject(this);
		FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffect, 1, EffectContext);

		if (SpecHandle.IsValid())
		{
			FActiveGameplayEffectHandle GEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}
	}
}

void ABinkyCharacter::GiveDefaultAbilities()
{
	if (HasAuthority() && IsValid(AbilitySystemComponent))
	{
		for (TSubclassOf<UBinkyGameplayAbility>& StartupAbility : DefaultAbilities)
		{
			AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(StartupAbility.GetDefaultObject(), 1, 0));
		}
	}
}

ABinkyPlayerController* ABinkyCharacter::GetBinkyPlayerController() const
{
	return CastChecked<ABinkyPlayerController>(Controller, ECastCheckedType::NullAllowed);
}

ABinkyPlayerState* ABinkyCharacter::GetBinkyPlayerState() const
{
	return CastChecked<ABinkyPlayerState>(GetPlayerState(), ECastCheckedType::NullAllowed);
}

UAbilitySystemComponent* ABinkyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ABinkyCharacter::ESCMenu()
{
	ABinkyPlayerController* binkyPlayerController = GetBinkyPlayerController();
	if (IsValid(binkyPlayerController))
	{
		binkyPlayerController->InputESCMenu();
	}
}
