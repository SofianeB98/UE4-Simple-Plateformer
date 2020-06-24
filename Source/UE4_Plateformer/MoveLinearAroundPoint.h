// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AffectedByTime.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoveLinearAroundPoint.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE4_PLATEFORMER_API UMoveLinearAroundPoint : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoveLinearAroundPoint();

	//UPROPERTY(EditAnywhere)
	FVector currentPosition;

	UPROPERTY(EditAnywhere, Category = "Debug")
	FColor debugColor = FColor(255, 0, 0);
	
	UPROPERTY(EditAnywhere, Category = "Type")
	bool isLooping = true;
	
	UPROPERTY(EditAnywhere, Category = "Speed")
	float speed = 100.0f;
	
	UPROPERTY(EditAnywhere, Category = "Checkpoints")
	float distanceTolerance = 10.f;
	UPROPERTY(EditAnywhere, Category = "Checkpoints")
	int pointsNumber = 2;
	UPROPERTY(EditAnywhere, Category = "Checkpoints")
	FVector targetPositions[4];

	UAffectedByTime* AffectedByTime = nullptr;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	int currentIndex = 0;
	bool reverse = false;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
