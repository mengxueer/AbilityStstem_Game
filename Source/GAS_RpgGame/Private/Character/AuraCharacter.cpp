// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerState.h"

AAuraCharacter::AAuraCharacter() {
	
	GetCharacterMovement()->bOrientRotationToMovement=true; //将角色加速方向旋转
	GetCharacterMovement()->RotationRate=FRotator(0.0f,400.0f,0.0f);//旋转速率
	
	GetCharacterMovement()->bConstrainToPlane=true;//对齐到地面
	GetCharacterMovement()->bSnapToPlaneAtStart = true;//开始扑获到平面

	bUseControllerRotationPitch=false; //不使用控制器的旋转控制
	bUseControllerRotationYaw=false;//不使用控制器的旋转控制
	bUseControllerRotationRoll=false;//不使用控制器的旋转控制
}

void AAuraCharacter::PossessedBy(AController* NewController) {//给予控制器的受控的时候
	Super::PossessedBy(NewController);
	//在服务器上初始化
	InitAbilityActorInfo();
}

void AAuraCharacter::OnRep_PlayerState() {
	Super::OnRep_PlayerState();
	//在客户端上初始化
	InitAbilityActorInfo();
}

void AAuraCharacter::InitAbilityActorInfo() {
	AAuraPlayerState* AuraPlayerState=GetPlayerState<AAuraPlayerState>();//得到玩家状态句柄
	check(AuraPlayerState);
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState,this);//在服务器上设置AbilitySystemComponent 的拥有者和化身
	AbilitySystemComponent=AuraPlayerState->GetAbilitySystemComponent();//AbilitySystemComponent赋值
	AttributeSet=AuraPlayerState->GetAttributeSet();//AttributeSet赋值
}
