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
	if (!character)//���������� ���������� ������� ���� ��������� �� ��������� ������
	{
		return;
	}
	forwardSpeed = character->getAnimVectorSpeed().X;
	strafeSpeed = character->getAnimVectorSpeed().Y;
}
