// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"



AAuraEffectActor::AAuraEffectActor()
{

	PrimaryActorTick.bCanEverTick = false;
	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot")));
}



void AAuraEffectActor::BeginPlay() {
	Super::BeginPlay();
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass) {

		UAbilitySystemComponent* TargetASC= UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	    if (TargetASC==nullptr) return;

	    check(GameplayEffectClass);
	    FGameplayEffectContextHandle EffectContextHandle= TargetASC->MakeEffectContext();
	    EffectContextHandle.AddSourceObject(this);
	    const FGameplayEffectSpecHandle EffectSpecHandle= TargetASC->MakeOutgoingSpec(GameplayEffectClass,Actorlevel,EffectContextHandle);
	    const FActiveGameplayEffectHandle ActiveGameplayEffectHandle=TargetASC->
	      ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
	const bool bIsInFinite=EffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy==EGameplayEffectDurationType::Infinite;
	if (bIsInFinite&&InfiniteEffectRemovePolicy==EEffectRemovePolicy::RemoveEndOverlap) {
		ActiveEffectHandles.Add(ActiveGameplayEffectHandle,TargetASC);
	}
	     
}

void AAuraEffectActor::OnOverlap(AActor* TargetActor) {
	if (InstantEffectApplicationPolicy==EEffectApplicationPolicy::ApplyOnOverlap) {
		ApplyEffectToTarget(TargetActor,InstantGameplayEffectClass);
	}
	if (DurationEffectApplicationPolicy==EEffectApplicationPolicy::ApplyOnOverlap) {
		ApplyEffectToTarget(TargetActor,DurationGameplayEffectClass);
	}
	if (InfiniteEffectApplicationPolicy==EEffectApplicationPolicy::ApplyOnOverlap) {
		ApplyEffectToTarget(TargetActor,InfiniteGameplayEffectClass);
	}
}

void AAuraEffectActor::OnEndOverlap(AActor* TargetActor) {
	if (InstantEffectApplicationPolicy==EEffectApplicationPolicy::ApplyOnEndOverlap) {
		ApplyEffectToTarget(TargetActor,InstantGameplayEffectClass);
	}
	if (DurationEffectApplicationPolicy==EEffectApplicationPolicy::ApplyOnEndOverlap) {
		ApplyEffectToTarget(TargetActor,DurationGameplayEffectClass);
	}
	if (InfiniteEffectApplicationPolicy==EEffectApplicationPolicy::ApplyOnEndOverlap) {
		ApplyEffectToTarget(TargetActor,InfiniteGameplayEffectClass);
	}
	TArray<FActiveGameplayEffectHandle> HandlesToRemove;
	if (InfiniteEffectRemovePolicy==EEffectRemovePolicy::RemoveEndOverlap) {
		UAbilitySystemComponent* TargetASC= UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
		if (TargetASC==nullptr) return;
		for (TTuple<FActiveGameplayEffectHandle, UAbilitySystemComponent*> HandlePair : ActiveEffectHandles) {
			if (TargetASC==HandlePair.Value) {
				TargetASC->RemoveActiveGameplayEffect(HandlePair.Key,1);
				HandlesToRemove.Add(HandlePair.Key);
			}
		}
		for (FActiveGameplayEffectHandle& ToRemove : HandlesToRemove) {
			ActiveEffectHandles.FindAndRemoveChecked(ToRemove);
		}
	}
}



