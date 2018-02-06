// Fill out your copyright notice in the Description page of Project Settings.




#include "MyPlayerCharacter.h"
#include "Classes/Kismet/KismetMathLibrary.h"


// Sets default values
AMyPlayerCharacter::AMyPlayerCharacter(const FObjectInitializer &ObjectInitializer):Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	cameraSpring = ObjectInitializer.CreateDefaultSubobject<USpringArmComponent>(this, "CameraSpring");
	cameraSpring->SetupAttachment(RootComponent);
	cameraSpring->RelativeRotation = FRotator(-90.f, 0.f, 0.f);

	//cameraSpring->bEnableCameraLag = true;//Включить плавное движение камеры

	//UCameraComponent *cameraComp;
	cameraComp = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, "CameraComponent");
	cameraComp->SetupAttachment(cameraSpring, USpringArmComponent::SocketName);

	GetMesh()->AddLocalOffset(FVector(0, 0, -90));
	GetMesh()->AddLocalRotation(FRotator(0, -90, 0));
	
	InventoryComp = ObjectInitializer.CreateDefaultSubobject<UMyInventoryComponent>(this, "InventoryComponent");
}

// Called when the game starts or when spawned
void AMyPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	pc = GetWorld()->GetFirstPlayerController();

	cameraSpring->bUsePawnControlRotation;
	cameraSpring->bInheritYaw = false;
	cameraSpring->bInheritPitch = false;
	cameraSpring->bInheritRoll = false;
	cameraSpring->TargetArmLength = CameraDistance;//Высота обзора
	
	pc->InputYawScale = TurnSpeed;//Скорость поворота. Чем выше скорость, тем меньше плавность

}

// Called every frame
void AMyPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyPlayerCharacter::moveForward);
	PlayerInputComponent->BindAxis("Strafe", this, &AMyPlayerCharacter::strafe);
	PlayerInputComponent->BindAxis("Turn", this, &AMyPlayerCharacter::turn);
}

void AMyPlayerCharacter::moveForward(float step)
{
	//const FVector directoin = FRotationMatrix(FRotator(0, GetControlRotation().Yaw, 0)).GetUnitAxis(EAxis::X);//движение в направлении камеры
	const FVector direction = FVector(1, 0, 0);//Независимо от направления камеры
	AddMovementInput(direction, step);
}

void AMyPlayerCharacter::strafe(float step)
{
	//const FVector dir = FRotationMatrix(FRotator(0, GetControlRotation().Yaw, 0)).GetUnitAxis(EAxis::Y);//движение в направлении камеры
	const FVector direction = FVector(0, 1, 0);//движение независимо от камеры
	AddMovementInput(direction, step);
}

void AMyPlayerCharacter::turn(float step)
{
	FHitResult hit;
	pc->GetHitResultUnderCursor(ECollisionChannel::ECC_MAX, false, hit);
	//FRotator rot = (GetActorLocation() - hit.ImpactPoint).Rotation;
	
	FVector dir = hit.ImpactPoint - GetActorLocation();
	AddControllerYawInput(FMath::Atan2(GetActorForwardVector().X*dir.Y - dir.X*GetActorForwardVector().Y, GetActorForwardVector().X*dir.X + GetActorForwardVector().Y*dir.Y));
}

FVector AMyPlayerCharacter::getAnimVectorSpeed()
{
	return FRotationMatrix(FRotator(0, GetControlRotation().Yaw, 0)).InverseTransformVector(GetVelocity());
}

