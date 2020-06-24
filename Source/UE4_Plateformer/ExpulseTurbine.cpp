// Fill out your copyright notice in the Description page of Project Settings.


#include "ExpulseTurbine.h"

// Sets default values
AExpulseTurbine::AExpulseTurbine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	BoxComponent->InitBoxExtent(FVector(50.f, 50.f, 50.f));
	RootComponent = BoxComponent;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	StaticMesh->SetupAttachment(RootComponent);

	ApplyForceBehavior = CreateDefaultSubobject<UApplyContinueForceInDirection>("ApplyForce");
	ApplyForceBehavior->forceDir = GetActorUpVector();

	AffectedByTime = CreateDefaultSubobject<UAffectedByTime>("AffectedByTime");
}

// Called when the game starts or when spawned
void AExpulseTurbine::BeginPlay()
{
	Super::BeginPlay();
	ApplyForceBehavior->forceDir = GetActorUpVector();
	ApplyForceBehavior->AffectedByTime = this->AffectedByTime;
}

// Called every frame
void AExpulseTurbine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

