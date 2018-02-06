// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyInventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEADFIELD_API UMyInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector2D InventorySize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector2D ToolbarSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<FVector2D, class UMyItem*> InventoryTMap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<FVector2D, class UMyItem*> ToolbarTMap;
};
