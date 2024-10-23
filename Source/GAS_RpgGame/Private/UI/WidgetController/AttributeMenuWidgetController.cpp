// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Date/AttributeInfo.h"

void UAttributeMenuWidgetController::BroadcastInitValues() {
   UAuraAttributeSet* AS=CastChecked<UAuraAttributeSet>(AttributeSet);
	check(AttributeInfo);

	// FAuraAttributeInfo Info=AttributeInfo->FindAttributeInfoTag(FAuraGamePlayTags::Get().Attributes_Primary_Strength);
	// Info.AttributeValue=AS->GetStrength();
	// AttributeInfoDelegate.Broadcast(Info);

	for (auto& Pair:AS->TagToAttributes) {
		BordCastAttributeInfo(Pair.Key, Pair.Value());
	}
	

}

void UAttributeMenuWidgetController::BindCallbacksToDependencies() {
	
	UAuraAttributeSet* AS=CastChecked<UAuraAttributeSet>(AttributeSet);
	
	for (auto& Pair:AS->TagToAttributes) {
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
	  [&](const FOnAttributeChangeData& Data)
	  {
	  	BordCastAttributeInfo(Pair.Key, Pair.Value());
	  }
	);
	}
	
}

void UAttributeMenuWidgetController::BordCastAttributeInfo(const FGameplayTag& AttributeTag,
	const FGameplayAttribute& Attribute) const {
	FAuraAttributeInfo Info=AttributeInfo->FindAttributeInfoTag(AttributeTag);
	Info.AttributeValue=Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(Info);
}
