// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveLinearAroundPoint.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "MovingPlateform.generated.h"

UCLASS()
class UE4_PLATEFORMER_API AMovingPlateform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlateform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
	UBoxComponent* BoxComponent;
	
	UPROPERTY(EditAnywhere, Category = "Components")
	UMoveLinearAroundPoint* Moving;

	UPROPERTY(EditAnywhere, Category = "Components")
	UAffectedByTime* AffectedByTime;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};