// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "GameFramework/PlayerController.h"
#include "interaction/EnemyInterface.h"
#include "AuraPlayerController.generated.h"


class USplineComponent;
class UAuraAbilitySystemComponent;
struct FGameplayTag;
class UAuraInputConfig;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
/**
 * 
 */
UCLASS()
class GAS_RPGGAME_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AAuraPlayerController();
	virtual void Tick(float DeltaSeconds) override;
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	UPROPERTY(EditAnywhere,Category="Input",meta=(ShortToolTip="输入映射"))
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere,Category="Input",meta=(ShortToolTip="按键输入动作"))
	TObjectPtr<UInputAction> MoveAction;

	void Move(const struct  FInputActionValue& InputActionValue) ;
	
	void CursorTrace();

	
	IEnemyInterface* LastActor;
	
	IEnemyInterface*  ThisActor;

	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);
	
	UPROPERTY(EditDefaultsOnly,Category="Input")
	TObjectPtr<UAuraInputConfig> InputConfig;

	UPROPERTY()
	TObjectPtr<UAuraAbilitySystemComponent> AuraAbilitySystemComponent;
	UAuraAbilitySystemComponent* GetAsc() ;

	FVector CachedDestination=FVector::ZeroVector;
	float FollowTime=.0f;
	float ShortPressThreshold=0.5f;
	bool bAutoRunning=false;
	bool bTargeting=false;

	UPROPERTY(EditDefaultsOnly)
	float AutoRunAcceptanceRadius=50.0f;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> Spline;
};


