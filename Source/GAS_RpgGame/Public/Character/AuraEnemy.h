// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacter.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

#define CUSTOM_DEPTH_RED 250
/**
 * 
 */
UCLASS()
class GAS_RPGGAME_API AAuraEnemy : public AAuraCharacter,public IEnemyInterface
{
	GENERATED_BODY()
public:
	AAuraEnemy();
	virtual void HighlightActor() override;
	virtual void UnlightActor() override;
protected:
	virtual void BeginPlay() override;
	
};
