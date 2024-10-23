// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AuraAbilitySystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Player/AuraPlayerState.h"
#include "UI/HUD/AuraHUD.h"
#include "UI/WidgetController/AuraWidgetController.h"

UOverlayWidgetController* UAuraAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject) {
	if(APlayerController* Pc= UGameplayStatics::GetPlayerController(WorldContextObject,0)) {
		if (AAuraHUD* AuraHUD=Cast<AAuraHUD>(Pc->GetHUD())) {
			AAuraPlayerState* PS=Pc->GetPlayerState<AAuraPlayerState>();
			UAbilitySystemComponent* ASC=PS->GetAbilitySystemComponent();
			UAttributeSet* AS=PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(Pc, PS,ASC, AS);
			return  AuraHUD->GetOverlayWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

UAttributeMenuWidgetController* UAuraAbilitySystemLibrary::GetAttributeMenuWidgetController(const UObject* WorldContextObject) {
	if(APlayerController* Pc= UGameplayStatics::GetPlayerController(WorldContextObject,0)) {
		if (AAuraHUD* AuraHUD=Cast<AAuraHUD>(Pc->GetHUD())) {
			AAuraPlayerState* PS=Pc->GetPlayerState<AAuraPlayerState>();
			UAbilitySystemComponent* ASC=PS->GetAbilitySystemComponent();
			UAttributeSet* AS=PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(Pc, PS,ASC, AS);
			return  AuraHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}
