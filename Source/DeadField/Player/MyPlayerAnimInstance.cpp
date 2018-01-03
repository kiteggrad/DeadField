// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerCharacter.h"
#include "DeadField.h"

#include "MyPlayerAnimInstance.h"

UMyPlayerAnimInstance::UMyPlayerAnimInstance(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{

}

void UMyPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	AMyPlayerCharacter *character = Cast<AMyPlayerCharacter>(TryGetPawnOwner());
	if (!character)//Прерывание выполнения функции если указатель на персонажа пустой
	{
		return;
	}
	forwardSpeed = character->getAnimVectorSpeed().X;
	strafeSpeed = character->getAnimVectorSpeed().Y;
}
