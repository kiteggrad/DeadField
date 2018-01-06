// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyItemConfig.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, abstract, EditInlineNew)
class DEADFIELD_API UMyItemConfig : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MyItemConfig")
		TSubclassOf<AActor> WeaponBlueprint;
	
	
};
