// Fill out your copyright notice in the Description page of Project Settings.



#include "Character/AuraCharacterBase.h"

#include "AbilitySystemComponent.h"


AAuraCharacterBase::AAuraCharacterBase() {
	PrimaryActorTick.bCanEverTick = false;
	//创建武器骨骼网格体
	Weapon=CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	//设置附加插槽
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	//设置碰撞类型为无碰撞
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const {
	return AbilitySystemComponent;//获取aes 组件
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAuraCharacterBase::InitAbilityActorInfo() {
	
}

void AAuraCharacterBase::AppleEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	FGameplayEffectContextHandle ContextHandle= GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle= GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level,ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(),GetAbilitySystemComponent());
}

void AAuraCharacterBase::InitializeDefaultAttributes() const {
	AppleEffectToSelf(DefaultPrimaryAttributes,1.0f);
	AppleEffectToSelf(DefaultSeconderAttributes,1.0f);
	AppleEffectToSelf(DefaultVitalAttributes,1.0f);
}



