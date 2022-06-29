// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSetBase.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffect.h"
#include "CharacterBase.h"


UAttributeSetBase::UAttributeSetBase()
	:Health(200.0f),
	MaxHealth(200.0f),
	Mana(100.0f),
	MaxMana(100.0f),
	Strength(250.0f),
	MaxStrength(250.0f)
{

}

//void UAttributeSetBase::PostGamePlayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
//{
//	if (Data.EvaluatedData.Attribute.GetUProperty()== FindFieldChecked<FProperty>(UAttributeSetBase::StaticClass(),GET_MEMBER_NAME_CHECKED(UAttributeSetBase,Health)))
//	{
//		UE_LOG(LogTemp, Warning, TEXT("Took some damage,now Health is : %f"), Health.GetCurrentValue());
//	}
//}

void UAttributeSetBase::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Health)))
	{
		Health.SetCurrentValue(FMath::Clamp(Health.GetCurrentValue(), 0.0f, MaxHealth.GetCurrentValue()));
		Health.SetBaseValue(FMath::Clamp(Health.GetBaseValue(), 0.0f, MaxHealth.GetCurrentValue()));
		//UE_LOG(LogTemp, Warning, TEXT("Took some damage,now Health is : %f"), Health.GetCurrentValue());
		OnHealthChange.Broadcast(Health.GetCurrentValue(), MaxHealth.GetCurrentValue());
		ACharacterBase* CharacterOwner = Cast<ACharacterBase>(GetOwningActor());

		if (Health.GetCurrentValue() == MaxHealth.GetCurrentValue())
		{
			if (CharacterOwner)
			{
				CharacterOwner->AddGameplayTag(CharacterOwner->FullHealthTag);
			}
		}
		else
		{
			if (CharacterOwner)
			{
				CharacterOwner->RemoveGameplayTag(CharacterOwner->FullHealthTag);
			}
		}
		
	}

	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Mana)))
	{
		Mana.SetCurrentValue(FMath::Clamp(Mana.GetCurrentValue(), 0.0f, MaxMana.GetCurrentValue()));
		Mana.SetBaseValue(FMath::Clamp(Mana.GetBaseValue(), 0.0f, MaxMana.GetCurrentValue()));
		
		OnManaChange.Broadcast(Mana.GetCurrentValue(), MaxMana.GetCurrentValue());
	}

	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Strength)))
	{
		Strength.SetCurrentValue(FMath::Clamp(Strength.GetCurrentValue(), 0.0f, MaxStrength.GetCurrentValue()));
		Strength.SetBaseValue(FMath::Clamp(Strength.GetBaseValue(), 0.0f, MaxStrength.GetCurrentValue()));
		
		OnHealthChange.Broadcast(Strength.GetCurrentValue(), MaxStrength.GetCurrentValue());
	}
}
