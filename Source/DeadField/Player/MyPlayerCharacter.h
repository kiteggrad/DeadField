// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "MyInventoryComponent.h"

#include "GameFramework/Character.h"
#include "MyPlayerCharacter.generated.h"

UCLASS()
class DEADFIELD_API AMyPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyPlayerCharacter(const FObjectInitializer &ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	USpringArmComponent *cameraSpring;
	UCameraComponent *cameraComp;
	USceneComponent *sceneComp;

	

	void moveForward(float step);
	void strafe(float step);
	void turn(float step);
	FVector getAnimVectorSpeed();

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMyInventoryComponent *InventoryComp;
	UPROPERTY(BlueprintReadWrite)
		APlayerController *pc;
	UPROPERTY(Category = "PlayerSettings", EditDefaultsOnly)//Скорость поворота. Чем выше скорость, тем меньше плавность
		float TurnSpeed = 5.f;
	UPROPERTY(Category = "PlayerSettings", EditDefaultsOnly)//Высота обзора
		float CameraDistance = 800.f;
	
};
