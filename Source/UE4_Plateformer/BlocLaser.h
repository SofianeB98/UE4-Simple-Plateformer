// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AffectedByTime.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "RotateBehavior.h"
#include "Laser.h"
#include "BlocLaser.generated.h"

UCLASS()
class UE4_PLATEFORMER_API ABlocLaser : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlocLaser();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
	UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere, Category = "Components")
	URotateBehavior* RotateBehavior;

	UPROPERTY(EditAnywhere, Category = "Components")
	UAffectedByTime* AffectedByTime;
	
	UPROPERTY(EditAnywhere, Category = "Components")
	ULaser* LaserUp;
	UPROPERTY(EditAnywhere, Category = "Components")
	ULaser* LaserDown;
	UPROPERTY(EditAnywhere, Category = "Components")
	ULaser* LaserLeft;
	UPROPERTY(EditAnywhere, Category = "Components")
	ULaser* LaserRight;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
