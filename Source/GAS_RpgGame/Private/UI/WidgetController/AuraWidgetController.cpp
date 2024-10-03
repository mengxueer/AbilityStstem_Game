// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AuraWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayController=WCParams.PlayerController;
	PlayState=WCParams.PlayerState;
	AbilitySystemComponent=WCParams.AbilitySystemComponent;
	AttributeSet=WCParams.AttributeSet;
}

void UAuraWidgetController::BrodcastInitValues()
{
}

void UAuraWidgetController::BindCallbacksToDependencies()
{
}

