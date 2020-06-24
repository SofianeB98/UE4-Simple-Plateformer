// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AffectedByTime.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "CollisionQueryParams.h"
#include "Laser.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE4_PLATEFORMER_API ULaser : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULaser();

	UPROPERTY(EditAnywhere, Category = "Laser")
	bool isEnable = true;

	UPROPERTY(EditAnywhere, Category = "Alternate Parameter")
	bool isAlternatif = false;
	UPROPERTY(EditAnywhere, Category = "Alternate Parameter")
	float alternateCycle = 1.0f;
	
	float currentCycle = 0.0f;
	bool isActivate = true;
	
	UPROPERTY(EditAnywhere, Category = "General Parameter")
	float laserLength = 10.0f;
	FVector startPosition = FVector(0,0,0);
	FVector dir;

	UAffectedByTime* AffectedByTime = nullptr;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
