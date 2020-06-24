// Fill out your copyright notice in the Description page of Project Settings.


#include "AffectedByTime.h"
#include "Engine/World.h"
#include "UE4_PlateformerGameMode.h"

// Sets default values for this component's properties
UAffectedByTime::UAffectedByTime()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	timeModifier = 1.0f;
	isInTimeZone = false;
}


// Called when the game starts
void UAffectedByTime::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAffectedByTime::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!isInTimeZone)
		if (AUE4_PlateformerGameMode* GM = Cast<AUE4_PlateformerGameMode>(GetWorld()->GetAuthGameMode()))
			this->timeModifier = GM->getCustomTime();
	
}

void UAffectedByTime::SetInTimeZone(bool val)
{
	this->isInTimeZone = val;
}


void UAffectedByTime::SetTimeModifier(float val)
{
	this->timeModifier = val;
}
