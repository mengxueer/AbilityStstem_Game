// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Date/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoTag(const FGameplayTag& AttributeTag, bool bLogNotFound) {
	for (FAuraAttributeInfo Info:AuraAttributeInformation) {
		if (Info.AttributeTag.MatchesTagExact(AttributeTag)) {
			return Info;
		}
	}
	if (bLogNotFound) {
		UE_LOG(LogTemp, Error, TEXT("找不到属性tag[%s]来自于%s"),*AttributeTag.ToString(),*GetNameSafe(this));
	}
	return FAuraAttributeInfo();
}
