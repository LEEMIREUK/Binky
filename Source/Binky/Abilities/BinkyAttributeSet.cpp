// Fill out your copyright notice in the Description page of Project Settings.


#include "BinkyAttributeSet.h"

#include "Net/UnrealNetwork.h"

UBinkyAttributeSet::UBinkyAttributeSet()
{
}

void UBinkyAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UBinkyAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBinkyAttributeSet, Mana, COND_None, REPNOTIFY_Always);
}

void UBinkyAttributeSet::OnRep_Health(const FGameplayAttributeData OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBinkyAttributeSet, Health, OldHealth);
}

void UBinkyAttributeSet::OnRep_Mana(const FGameplayAttributeData OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBinkyAttributeSet, Mana, OldMana);

}
