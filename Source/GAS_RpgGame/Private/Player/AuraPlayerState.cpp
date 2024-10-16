// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerState.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Net/UnrealNetwork.h"

AAuraPlayerState::AAuraPlayerState() {
	NetUpdateFrequency=100.f;//网络更新频率
	AbilitySystemComponent=CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");//构建AES组件
	AbilitySystemComponent->SetIsReplicated(true);//开启复制
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);//设置复制模式为最小效果
	AttributeSet=CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");//构建属性集
}

void AAuraPlayerState::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAuraPlayerState,Level);
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const {
	return AbilitySystemComponent;
}

void AAuraPlayerState::OnRep_Level(int OldLevel) {
	
}
