// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ModMagCalc/MMC_MaxMana.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "interaction/CombatInterface.h"

UMMC_MaxMana::UMMC_MaxMana() {
	IntDef.AttributeToCapture=UAuraAttributeSet::GetIntelligenceAttribute();
	IntDef.AttributeSource=EGameplayEffectAttributeCaptureSource::Target;
	IntDef.bSnapshot=false;

	RelevantAttributesToCapture.Add(IntDef);
}

float UMMC_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const {
	const FGameplayTagContainer* SourceTags=Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags=Spec.CapturedTargetTags.GetAggregatedTags();
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags=SourceTags;
	EvaluateParameters.TargetTags=TargetTags;
	float intelligence=.0f;
	GetCapturedAttributeMagnitude(IntDef,Spec,EvaluateParameters,intelligence);
	intelligence=FMath::Max<float>(intelligence,0.f);

	ICombatInterface* CombatInterface=Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel=CombatInterface->GetPlayerLevel();
	return 50.f+2.5f*intelligence+15.f*PlayerLevel;
}
