// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class BATTLEOFTHEBITES_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

	UFUNCTION(BlueprintPure)
	bool isDead() const;

	UFUNCTION(BlueprintPure)
	float GetHealthPercentage() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UPROPERTY(VisibleAnywhere)
	float Health;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Shoot();

	UPROPERTY()
	AGun* Gun;

	UFUNCTION(BlueprintPure)
	AGun* GetGun() const;

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);


	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100;

};
