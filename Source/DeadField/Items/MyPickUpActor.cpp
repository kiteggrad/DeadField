// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPickUpActor.h"


// Sets default values
AMyPickUpActor::AMyPickUpActor(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, "MeshComponent");
	Item = ObjectInitializer.CreateDefaultSubobject<UMyItem>(this, "item");
}

// Called when the game starts or when spawned
void AMyPickUpActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPickUpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

