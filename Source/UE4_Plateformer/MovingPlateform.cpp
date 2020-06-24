// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlateform.h"

// Sets default values
AMovingPlateform::AMovingPlateform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	BoxComponent->InitBoxExtent(FVector(50.f, 50.f, 50.f));
	RootComponent = BoxComponent;
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	StaticMesh->SetupAttachment(RootComponent);
	
	Moving = CreateDefaultSubobject<UMoveLinearAroundPoint>("Moving");
	AffectedByTime = CreateDefaultSubobject<UAffectedByTime>("AffectedByTime");
}

// Called when the game starts or when spawned
void AMovingPlateform::BeginPlay()
{
	Super::BeginPlay();
	Moving->AffectedByTime = this->AffectedByTime;
	SetActorLocation(Moving->currentPosition);
}

// Called every frame
void AMovingPlateform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(Moving->currentPosition);
}