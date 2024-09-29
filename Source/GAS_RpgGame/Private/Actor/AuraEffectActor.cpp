// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
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
		AscInterface->GetAbilitySystemComponent()->GetAttributeSet(UAttributeSet::StaticClass());
	}
}

void AAuraEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}


void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this,AAuraEffectActor::OnOverlap);//添加开始碰撞事件
	Sphere->OnComponentEndOverlap.AddDynamic(this,AAuraEffectActor::EndOverlap);//添加结束碰撞事件
}



