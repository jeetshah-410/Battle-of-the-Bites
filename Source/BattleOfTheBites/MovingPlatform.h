// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class BATTLEOFTHEBITES_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnyWhere, Category = "MovingPlatform")
	FVector PlatformVelocity = FVector(0,0,200);

	UPROPERTY(EditAnywhere, Category = "MovingPlatform")
	float MoveDistance = 500;

	UPROPERTY(EditAnyWhere, Category="Moving")
	FRotator RotationVelocity = FRotator(0,90,0);

	FVector StartLocation;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn() const;
	float GetDistanceMoved() const;

};
