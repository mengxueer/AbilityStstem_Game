// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraGamePlayTags.h"
#include "GameplayTagsManager.h"



FAuraGamePlayTags FAuraGamePlayTags::GameplayTags;

void FAuraGamePlayTags::InitializeNativeGameplayTags() {
	GameplayTags.Attributes_Primary_Strength= UGameplayTagsManager::Get().
	AddNativeGameplayTag(FName("Attributes.Primary.Strength"),FString("力量"));
	GameplayTags.Attributes_Primary_Intelligence= UGameplayTagsManager::Get().
	AddNativeGameplayTag(FName("Attributes.Primary.Intelligence"),FString("智力"));
	GameplayTags.Attributes_Primary_Resilience= UGameplayTagsManager::Get().
	AddNativeGameplayTag(FName("Attributes.Primary.Resilience"),FString("体力"));
	GameplayTags.Attributes_Primary_Vigor= UGameplayTagsManager::Get().
	AddNativeGameplayTag(FName("Attributes.Primary.Vigor"),FString("精力"));
	
	
	GameplayTags.Attributes_Secondary_Armor= UGameplayTagsManager::Get().
	AddNativeGameplayTag(FName("Attributes.Secondary.Armor"),FString("护甲值"));
	GameplayTags.Attributes_Secondary_ArmorPenetration= UGameplayTagsManager::Get().
	AddNativeGameplayTag(FName("Attributes.Secondary.ArmorPenetration"),FString("护甲穿透"));

	GameplayTags.Attributes_Secondary_BlockChance= UGameplayTagsManager::Get().
	AddNativeGameplayTag(FName("Attributes.Secondary.BlockChance"),FString("格挡"));
	GameplayTags.Attributes_Secondary_CriticalHitChance= UGameplayTagsManager::Get().
	AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitChance"),FString("格挡几率"));

	GameplayTags.Attributes_Secondary_CriticalHitDamage= UGameplayTagsManager::Get().
	AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitDamage"),FString("暴击伤害"));
	GameplayTags.Attributes_Secondary_CriticalHitResistance= UGameplayTagsManager::Get().
	AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitResistance"),FString("暴击抵挡"));

	GameplayTags.Attributes_Secondary_HealthRegeneration= UGameplayTagsManager::Get().
	AddNativeGameplayTag(FName("Attributes.Secondary.HealthRegeneration"),FString("生命恢复"));
	GameplayTags.Attributes_Secondary_ManaRegeneration= UGameplayTagsManager::Get().
	AddNativeGameplayTag(FName("Attributes.Secondary.ManaRegeneration"),FString("蓝量恢复"));

	GameplayTags.Attributes_Secondary_MaxHealth= UGameplayTagsManager::Get().
	AddNativeGameplayTag(FName("Attributes.Secondary.MaxHealth"),FString("生命最大"));
	GameplayTags.Attributes_Secondary_MaxMana= UGameplayTagsManager::Get().
	AddNativeGameplayTag(FName("Attributes.Secondary.MaxMana"),FString("蓝量最大"));


	GameplayTags.InputTag_LMB= UGameplayTagsManager::Get().
	AddNativeGameplayTag(FName("InputTag.LMB"),FString("左键"));

	GameplayTags.InputTag_RMB= UGameplayTagsManager::Get().
	AddNativeGameplayTag(FName("InputTag.RMB"),FString("右键"));

	GameplayTags.InputTag_1= UGameplayTagsManager::Get().
	AddNativeGameplayTag(FName("InputTag.1"),FString("1"));

	GameplayTags.InputTag_2= UGameplayTagsManager::Get().
	AddNativeGameplayTag(FName("InputTag.2"),FString("2"));
	
	GameplayTags.InputTag_3= UGameplayTagsManager::Get().
	AddNativeGameplayTag(FName("InputTag.3"),FString("3"));
	
	GameplayTags.InputTag_4= UGameplayTagsManager::Get().
	AddNativeGameplayTag(FName("InputTag.4"),FString("4"));
	
	
}
