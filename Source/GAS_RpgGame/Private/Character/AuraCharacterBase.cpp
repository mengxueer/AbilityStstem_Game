// Fill out your copyright notice in the Description page of Project Settings.



#include "Character/AuraCharacterBase.h"


AAuraCharacterBase::AAuraCharacterBase() {
	PrimaryActorTick.bCanEverTick = false;
	//创建武器骨骼网格体
	weapon=CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	//设置附加插槽
	weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	//设置碰撞类型为无碰撞
	weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}



