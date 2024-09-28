// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

UCLASS(Abstract)//抽象类
class GAS_RPGGAME_API AAuraCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	
	AAuraCharacterBase();
protected:

	virtual void BeginPlay() override;
    UPROPERTY(EditAnywhere,Category="Combat",meta=(ShortToolTip="战斗"))
    TObjectPtr<USkeletalMeshComponent> weapon; //父类构造共同拥有的武器

};
