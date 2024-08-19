// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"


UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HealthPoint = 100.00;

	void HandleDestruction();

protected:
	void RotateTurret(FVector LookAtTarget);
	void Fire();
	
	float GetHealth() const;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "01 - Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "01 - Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "01 - Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "02 - Combat", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditDefaultsOnly, Category = "02 - Combat")
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "03 - VFX")
	class UParticleSystem* DeathParticles;

	UPROPERTY(EditAnywhere, Category = "03 - VFX")
	class USoundBase* DeathSound;

	UPROPERTY(EditAnywhere, Category = "03 - VFX")
	TSubclassOf<class UCameraShakeBase> DeathCameraShakeClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "01 - Components", meta = (AllowPrivateAccess = "true"))
	class UParticleSystemComponent* MovementTrailParticles;
};
