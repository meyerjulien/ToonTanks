// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

// Sets default values
ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Movement
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);

	// Inputs
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ATank::Fire);
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerControllerRef)
	{
		FHitResult HitResult;
		PlayerControllerRef->GetHitResultUnderCursor(
			ECC_Visibility,
			false,
			HitResult);

		RotateTurret(HitResult.ImpactPoint);
	}
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

	PlayerControllerRef = Cast<APlayerController>(GetController());
}

void ATank::MoveForward(float Value)
{
	FVector DeltaLocation(0.f);

	// X = Value * DeltaTime *  Speed
	float LocalDeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	Value = DeltaLocation.X = Value * LocalDeltaTime * Speed;

	AddActorLocalOffset(DeltaLocation, true);
}

void ATank::Turn(float Value)
{
	FRotator DeltaRotation(0.f);

	// X = Value * DeltaTime *  TurnRate
	float LocalDeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	DeltaRotation.Yaw = Value * LocalDeltaTime * TurnRate;

	AddActorLocalRotation(DeltaRotation, true);
}
