// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveLinearAroundPoint.h"

#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

#include "MovableAgent.generated.h"

UCLASS()
class UE4_PLATEFORMER_API AMovableAgent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovableAgent();

	// declare overlap begin function
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
	USphereComponent* SphereComponent;

	UPROPERTY(EditAnywhere, Category = "Components")
	UMoveLinearAroundPoint* Moving;

	UPROPERTY(EditAnywhere, Category = "Components")
	UAffectedByTime* AffectedByTime;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
