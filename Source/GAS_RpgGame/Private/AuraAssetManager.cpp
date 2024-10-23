// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraAssetManager.h"

#include "AuraGamePlayTags.h"


UAuraAssetManager& UAuraAssetManager::Get() {
	return *Cast<UAuraAssetManager>(GEngine->AssetManager);
}

void UAuraAssetManager::StartInitialLoading() {
	Super::StartInitialLoading();
   FAuraGamePlayTags::InitializeNativeGameplayTags();
}
