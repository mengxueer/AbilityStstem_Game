// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

AAuraCharacter::AAuraCharacter() {
	
	GetCharacterMovement()->bOrientRotationToMovement=true; //将角色加速方向旋转
	GetCharacterMovement()->RotationRate=FRotator(0.0f,400.0f,0.0f);//旋转速率
	
	GetCharacterMovement()->bConstrainToPlane=true;//对齐到地面
	GetCharacterMovement()->bSnapToPlaneAtStart = true;//开始扑获到平面

	bUseControllerRotationPitch=false; //不使用控制器的旋转控制
	bUseControllerRotationYaw=false;//不使用控制器的旋转控制
	bUseControllerRotationRoll=false;//不使用控制器的旋转控制
}
