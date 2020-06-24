// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLinearAroundPoint.h"
#include "DrawDebugHelpers.h"
#include "UE4_PlateformerGameMode.h"

// Sets default values for this component's properties
UMoveLinearAroundPoint::UMoveLinearAroundPoint()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	currentIndex = 0;
}


// Called when the game starts
void UMoveLinearAroundPoint::BeginPlay()
{
	Super::BeginPlay();

	currentIndex = 0;
	currentPosition = targetPositions[currentIndex];
	
	for (int i = 0; i < pointsNumber; i++)
	{
		DrawDebugSphere(GetWorld(), targetPositions[i], 50, 10, debugColor, true, -1, 0, 2);
	}
}

// Called every frame
void UMoveLinearAroundPoint::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector dir = targetPositions[currentIndex] - currentPosition;

	if (dir.Size() <= distanceTolerance)
	{
		if (isLooping)
		{
			currentIndex = (currentIndex + 1) % pointsNumber;
		}
		else
		{
			if(currentIndex + 1 == pointsNumber)
			{
				reverse = true;
			}
			else if(currentIndex == 0)
			{
				reverse = false;
			}

			currentIndex = reverse ? currentIndex - 1 : currentIndex + 1;
			
		}
	}

	dir.Normalize();

	if (AffectedByTime)
	{
		currentPosition += dir * speed * DeltaTime * AffectedByTime->getTimeModifier();
	}
}
