// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyItem.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, EditInlineNew)//DefaultToInstanced
class DEADFIELD_API UMyItem : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, blueprintReadWrite)
		TSubclassOf<AActor> BpClass;
	UPROPERTY(EditAnywhere, blueprintReadWrite)
		class UTexture2D *Texture;
	UPROPERTY(EditAnywhere, blueprintReadWrite)
		FString Name;
};
