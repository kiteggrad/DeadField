// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MyItem.h"

#include "MyPickUpActor.generated.h"

UCLASS()
class DEADFIELD_API AMyPickUpActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyPickUpActor(const FObjectInitializer &ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, blueprintReadWrite)
		UStaticMeshComponent *MeshComp;
	UPROPERTY(EditAnywhere, blueprintReadWrite, Instanced)
		UMyItem *Item;
};
