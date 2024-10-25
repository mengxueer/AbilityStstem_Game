// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AuraGamePlayTags.h"
#include "AbilitySystem/Ability/AuraGameplayAbility.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet() {
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this,&UAuraAbilitySystemComponent::EffectApplied);
	// const FAuraGamePlayTags GamePlayTags= FAuraGamePlayTags::Get();
	// //GamePlayTags.Attributes_Secondary_Armor.ToString();
	// GEngine->AddOnScreenDebugMessage(-1,5,FColor::Black,
	// 	GamePlayTags.Attributes_Secondary_Armor.ToString());
}

void UAuraAbilitySystemComponent::AddCharactAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartUpAbilities) {
	for (const auto AbilityClass : StartUpAbilities) {
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass,1);
		if (const UAuraGameplayAbility* AuraAbility=Cast<UAuraGameplayAbility>(AbilitySpec.Ability)) {
			AbilitySpec.DynamicAbilityTags.AddTag(AuraAbility->StartupInputTag);
			GiveAbility(AbilitySpec);
		}
		//GiveAbility(AbilitySpec);
		//GiveAbilityAndActivateOnce(AbilitySpec);
	}
}

void UAuraAbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag& InputTag) {
	if (!InputTag.IsValid()) return;
		for (FGameplayAbilitySpec& AbilitySpec:GetActivatableAbilities())
			{
				if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag)) {
					AbilitySpecInputPressed(AbilitySpec);
					if (!AbilitySpec.IsActive()) {
						TryActivateAbility(AbilitySpec.Handle);
						
					}
				}
			}
	
}

void UAuraAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag) {
	if (!InputTag.IsValid()) return;
	for (FGameplayAbilitySpec& AbilitySpec:GetActivatableAbilities())
	{
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag)) {
			AbilitySpecInputReleased(AbilitySpec);
		}
	}
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                                const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle) const {
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	EffectAssetTags.Broadcast(TagContainer);
	
}
