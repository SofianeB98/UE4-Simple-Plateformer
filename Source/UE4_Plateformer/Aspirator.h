// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ApplyContinueForceInDirection.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Aspirator.generated.h"

UCLASS()
class UE4_PLATEFORMER_API AAspirator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAspirator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
	UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere, Category = "Components")
	UApplyContinueForceInDirection* ApplyForceBehavior;

	UPROPERTY(EditAnywhere, Category = "Components")
	UAffectedByTime* AffectedByTime;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
