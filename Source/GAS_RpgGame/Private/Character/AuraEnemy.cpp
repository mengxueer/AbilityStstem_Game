// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraEnemy.h"

AAuraEnemy::AAuraEnemy() {

	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);//设置mesh 碰撞类型为可见,阻挡
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);//设置自定义深度的值为250
	weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemy::HighlightActor() {

	GetMesh()->SetRenderCustomDepth(true);//设置开启自定义深度
	//GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);//设置自定义深度的值为250
	weapon->SetRenderCustomDepth(true);
	//weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemy::UnlightActor() {

	GetMesh()->SetRenderCustomDepth(false);//关闭自定义深度
	weapon->SetRenderCustomDepth(false);
}
