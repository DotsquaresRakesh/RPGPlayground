// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSetBase.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffect.h"


UAttributeSetBase::UAttributeSetBase()
	:Health(200.0f),
	MaxHealth(200.0f)
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
		UE_LOG(LogTemp, Warning, TEXT("Took some damage,now Health is : %f"), Health.GetCurrentValue());
		OnHealthChange.Broadcast(Health.GetCurrentValue(), MaxHealth.GetCurrentValue());
	}
}
