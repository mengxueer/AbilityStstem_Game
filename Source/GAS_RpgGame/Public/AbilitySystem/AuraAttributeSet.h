// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "AuraAttributeSet.generated.h"

 #define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties{
	GENERATED_BODY()
	FEffectProperties(){};
	FGameplayEffectContextHandle EffectContextHandle;
	UPROPERTY()
	UAbilitySystemComponent* SourceASC=nullptr;
	UPROPERTY()
	AActor* SourceAvatarActor=nullptr;
	UPROPERTY()
	AController* SourceController=nullptr;
	UPROPERTY()
	ACharacter* SourceCharacter=nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC=nullptr;
	UPROPERTY()
	AActor* TargetAvatarActor=nullptr;
	UPROPERTY()
	AController* TargetController=nullptr;
	UPROPERTY()
	ACharacter* TargetCharacter=nullptr;
};
/**
 * 
 */
UCLASS()
class GAS_RPGGAME_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UAuraAttributeSet();
    virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual  void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual  void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_Strength,Category="Primary Attributes",meta=(tooltip="主要属性"))
	FGameplayAttributeData Strength;//体力
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,Strength);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_Intelligence,Category="Primary Attributes",meta=(tooltip="主要属性"))
	FGameplayAttributeData Intelligence;//智力
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,Intelligence);
	
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_Resilience,Category="Primary Attributes",meta=(tooltip="主要属性"))
	FGameplayAttributeData Resilience;//韧性
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,Resilience);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_Vigor,Category="Primary Attributes",meta=(tooltip="主要属性"))
	FGameplayAttributeData vigor;//活力
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,vigor);

	
	//重要属性
    UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_Health,Category="Vital Attributes",meta=(tooltip="重要属性"))
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,Health);
	
	
	
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_Mana,category="Vital Attributes",meta=(tooltip="重要属性"))
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,Mana);
	


	//二级属性
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_Armor,category="Sencondary Attributes",meta=(tooltip="次要属性"))
	FGameplayAttributeData Armor;//护甲
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,Armor);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_ArmorPenetration,category="Sencondary Attributes",meta=(tooltip="次元要属性"))
	FGameplayAttributeData ArmorPenetration;//护甲穿透
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,ArmorPenetration);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_BlockChance,category="Sencondary Attributes",meta=(tooltip="次元要属性"))
	FGameplayAttributeData BlockChance;//格挡
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,BlockChance);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_CriticalHitChance,category="Sencondary Attributes",meta=(tooltip="次元要属性"))
	FGameplayAttributeData CriticalHitChance;//命中
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,CriticalHitChance);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_CriticalHitDamage,category="Sencondary Attributes",meta=(tooltip="次元要属性"))
	FGameplayAttributeData CriticalHitDamage;//击中伤害
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,CriticalHitDamage);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_CriticalHitResistance,category="Sencondary Attributes",meta=(tooltip="次元要属性"))
	FGameplayAttributeData CriticalHitResistance;//击中抵抗
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,CriticalHitResistance);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_HealthRegeneration,category="Sencondary Attributes",meta=(tooltip="次元要属性"))
	FGameplayAttributeData HealthRegeneration;//生命恢复
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,HealthRegeneration);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_ManaRegeneration,category="Sencondary Attributes",meta=(tooltip="次元要属性"))
	FGameplayAttributeData ManaRegeneration;//蓝量恢复
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,ManaRegeneration);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_MaxHealth,Category="Vital Attributes",meta=(tooltip="重要属性"))
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,MaxHealth);

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_MaxMana,category="Vital Attributes",meta=(tooltip="重要属性"))
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet,MaxMana);
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth)const;
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)const;
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana)const;
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana)const;
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength)const;
	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence)const;
	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& OldResilience)const;
	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor)const;

	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor)const;
	UFUNCTION()
	void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration)const;
	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance)const;
	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance)const;
	UFUNCTION()
	void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage)const;
	UFUNCTION()
	void OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance)const;
	UFUNCTION()
	void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration)const;
	UFUNCTION()
	void OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration)const;
private:
	void SetEffectProperties(const struct FGameplayEffectModCallbackData& Data,FEffectProperties& Props)const;
};



