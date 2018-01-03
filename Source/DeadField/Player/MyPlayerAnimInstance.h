// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyPlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class DEADFIELD_API UMyPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "MyPlayerMovement")
		float forwardSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "MyPlayerMovement")
		float strafeSpeed;
public:
	UMyPlayerAnimInstance(const FObjectInitializer &ObjectInitializer);

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
};
