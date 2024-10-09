// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraEnemy.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

AAuraEnemy::AAuraEnemy() {

	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);//设置mesh 碰撞类型为可见,阻挡
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);//设置自定义深度的值为250
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

	AbilitySystemComponent=CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");//构建AES组件
	AbilitySystemComponent->SetIsReplicated(true);//开启复制
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);//设置复制模式为混合
	
	AttributeSet=CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");//构建属性集
}

void AAuraEnemy::HighlightActor() {

	GetMesh()->SetRenderCustomDepth(true);//设置开启自定义深度
	//GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);//设置自定义深度的值为250
	Weapon->SetRenderCustomDepth(true);
	//weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemy::UnlightActor() {

	GetMesh()->SetRenderCustomDepth(false);//关闭自定义深度
	Weapon->SetRenderCustomDepth(false);
}

void AAuraEnemy::BeginPlay() {
	Super::BeginPlay();
	InitAbilityActorInfo();
}

void AAuraEnemy::InitAbilityActorInfo() {
	check(AbilitySystemComponent);
	AbilitySystemComponent->InitAbilityActorInfo(this,this);//设置abilitySystem 的拥有者和化身
	Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();//通知初始化成功
}
