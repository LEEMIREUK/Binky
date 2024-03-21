// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BinkyAttributeSet.generated.h"

/**
 * 
 */
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class BINKY_API UBinkyAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UBinkyAttributeSet();

protected:
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

public:
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = Attributes)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UBinkyAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = Attributes)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UBinkyAttributeSet, Mana);

	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData OldHealth);

	UFUNCTION()
	virtual void OnRep_Mana(const FGameplayAttributeData OldMana);
};
