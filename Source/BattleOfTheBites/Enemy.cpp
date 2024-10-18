// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Gun.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"
#include "BattleOfTheBitesGameMode.h"
#include "Kismet/GameplayStatics.h"

class AGun;

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

bool AEnemy::isDead() const
{
	if (Health == 0)
	{
		return true;
	}
	return false;
}

float AEnemy::GetHealthPercentage() const
{
	return Health / MaxHealth;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AEnemy::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageToApply = FMath::Min(Health, DamageToApply);
	Health -= DamageToApply;
	isDead();

	if (isDead())
	{
		ABattleOfTheBitesGameMode* GameMode = GetWorld()->GetAuthGameMode<ABattleOfTheBitesGameMode>();
		if (GameMode)
		{
			GameMode->PawnKilled(this);
		}
		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	}

	return DamageToApply;
}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AEnemy::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AEnemy::MoveRight);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &AEnemy::Shoot);
}

void AEnemy::Shoot()
{
	Gun->PullTrigger();
}

AGun* AEnemy::GetGun() const
{
	return Gun;
}

void AEnemy::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AEnemy::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

