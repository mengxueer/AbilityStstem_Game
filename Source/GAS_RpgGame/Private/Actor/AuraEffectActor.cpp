// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Components/SphereComponent.h"


AAuraEffectActor::AAuraEffectActor()
{

	PrimaryActorTick.bCanEverTick = false;
	Mesh=CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	Sphere=CreateDefaultSubobject<USphereComponent>("Sphere");
    Sphere->SetupAttachment(GetRootComponent());
}

void AAuraEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if (IAbilitySystemInterface* AscInterface=Cast<IAbilitySystemInterface>(OtherActor)) {
	const UAuraAttributeSet* AuraAttributes=//获取属性设置
		Cast<UAuraAttributeSet>(AscInterface->GetAbilitySystemComponent()->GetAttributeSet(UAttributeSet::StaticClass()));
		UAuraAttributeSet* MutableAuraAttributes=const_cast<UAuraAttributeSet*>(AuraAttributes);//从const 类型转换为为普通类型
		MutableAuraAttributes->SetHealth(AuraAttributes->GetHealth()+25.f);//血量+25.f
<<<<<<< HEAD
		MutableAuraAttributes->SetMana(AuraAttributes->GetMana()+10.f);
=======
>>>>>>> e21d9ee0d1114ffa03abd27d9a5d57708e109715
		Destroy();//销毁自身
	}
}

void AAuraEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}


void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this,&AAuraEffectActor::OnOverlap);//添加开始碰撞事件
	Sphere->OnComponentEndOverlap.AddDynamic(this,&AAuraEffectActor::EndOverlap);//添加结束碰撞事件
}



