// Fill out your copyright notice in the Description page of Project Settings.



#include "Character/AuraCharacterBase.h"


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



