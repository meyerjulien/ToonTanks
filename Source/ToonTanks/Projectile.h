// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"


UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "01 - Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "01 - Components", meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "01 - Components", meta = (AllowPrivateAccess = "true"))
	class UParticleSystemComponent* TrailParticles;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, Category = "02 - Combat")
	float Damage = 50.f;

	UPROPERTY(EditAnywhere, Category = "03 - VFX")
	class UParticleSystem* HitParticles;

	UPROPERTY(EditAnywhere, Category = "03 - VFX")
	class USoundBase* ShootSound;

	UPROPERTY(EditAnywhere, Category = "03 - VFX")
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category = "03 - VFX")
	TSubclassOf<class UCameraShakeBase> HitCameraShakeClass;
};
