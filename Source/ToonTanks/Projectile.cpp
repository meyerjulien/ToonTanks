// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	ProjectileMesh->SetupAttachment(RootComponent);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	ProjectileMovementComponent->InitialSpeed = 2000.f;
	ProjectileMovementComponent->MaxSpeed = 2500.f;

	//ProjectileMovementComponent->bRotationFollowsVelocity = true;
	//ProjectileMovementComponent->bShouldBounce = true;
	//ProjectileMovementComponent->Bounciness = 1.f;
	//ProjectileMovementComponent->ProjectileGravityScale = 0.f;

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("On hit executed"));

	if (HitComp)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Comp: %s"), *HitComp->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("HitComp is null"));
	}
	if (OtherActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Other Actor: %s"), *OtherActor->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Other Actor is null"));
	}

	if (OtherComp)
	{
		
		UE_LOG(LogTemp, Warning, TEXT("Other Comp: %s"), *OtherComp->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Other Component is null"));
	}

}

