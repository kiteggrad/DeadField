// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/MyItem_Weapon.h"
#include "UObject/NoExportTypes.h"
#include "MyItem_Weapon_m4a1.generated.h"

/**
 * 
 */
class UMyItemConfig;

UCLASS(EditInlineNew, Blueprintable, meta = (BlueprintSpawnableComponent))
class DEADFIELD_API UMyItem_Weapon_m4a1 : public UMyItem_Weapon
{
	GENERATED_BODY()
	
public:
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category = "Stats")
		UStaticMeshComponent * m4a1mesh;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category = "ItemConfig")
		TArray<UObject*> ItemConfig;
};
