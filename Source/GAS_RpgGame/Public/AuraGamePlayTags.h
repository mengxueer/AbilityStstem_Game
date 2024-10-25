// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * 
 */


struct FAuraGamePlayTags {
public:
 static const FAuraGamePlayTags& Get(){return  GameplayTags;}
 static void InitializeNativeGameplayTags();

 FGameplayTag Attributes_Primary_Strength;//力量
 FGameplayTag Attributes_Primary_Intelligence;//智力
 FGameplayTag Attributes_Primary_Resilience;//体力
 FGameplayTag Attributes_Primary_Vigor;//精力
 
 //次要属性
 FGameplayTag Attributes_Secondary_Armor;//护甲
 FGameplayTag Attributes_Secondary_ArmorPenetration;//护甲穿透

 FGameplayTag Attributes_Secondary_BlockChance;//格挡
 FGameplayTag Attributes_Secondary_CriticalHitChance;//格挡几率
 
 FGameplayTag Attributes_Secondary_CriticalHitDamage;//暴击伤害
 FGameplayTag Attributes_Secondary_CriticalHitResistance;//暴击抵挡

 FGameplayTag Attributes_Secondary_HealthRegeneration;//生命恢复
 FGameplayTag Attributes_Secondary_ManaRegeneration;//蓝量恢复

 FGameplayTag Attributes_Secondary_MaxHealth;
 FGameplayTag Attributes_Secondary_MaxMana;

 FGameplayTag InputTag_LMB;
 FGameplayTag InputTag_RMB;
 FGameplayTag InputTag_1;
 FGameplayTag InputTag_2;
 FGameplayTag InputTag_3;
 FGameplayTag InputTag_4;
protected:
 
private:
static FAuraGamePlayTags GameplayTags;
};
