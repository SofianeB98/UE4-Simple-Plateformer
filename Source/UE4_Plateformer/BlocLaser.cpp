// Fill out your copyright notice in the Description page of Project Settings.


#include "BlocLaser.h"

// Sets default values
ABlocLaser::ABlocLaser()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	BoxComponent->InitBoxExtent(FVector(50.f, 50.f, 50.f));
	RootComponent = BoxComponent;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	StaticMesh->SetupAttachment(RootComponent);

	RotateBehavior = CreateDefaultSubobject<URotateBehavior>("RotateBehavior");
	LaserUp = CreateDefaultSubobject<ULaser>("LaserUp");
	LaserDown = CreateDefaultSubobject<ULaser>("LaserDown");
	LaserLeft = CreateDefaultSubobject<ULaser>("LaserLeft");
	LaserRight = CreateDefaultSubobject<ULaser>("LaserRight");

	AffectedByTime = CreateDefaultSubobject<UAffectedByTime>("AffectedByTime");

}

// Called when the game starts or when spawned
void ABlocLaser::BeginPlay()
{
	Super::BeginPlay();

	RotateBehavior->AffectedByTime = this->AffectedByTime;
	
	LaserUp->startPosition = GetActorLocation();
	LaserDown->startPosition = GetActorLocation();
	LaserLeft->startPosition = GetActorLocation();
	LaserRight->startPosition = GetActorLocation();

	LaserUp->AffectedByTime = this->AffectedByTime;
	LaserDown->AffectedByTime = this->AffectedByTime;
	LaserLeft->AffectedByTime = this->AffectedByTime;
	LaserRight->AffectedByTime = this->AffectedByTime;
}

// Called every frame
void ABlocLaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorRotation(RotateBehavior->currentRotation);
	if(LaserUp->isEnable)
		LaserUp->dir = GetActorUpVector();

	if (LaserDown->isEnable)
		LaserDown->dir = -GetActorUpVector();
	
	if (LaserLeft->isEnable)
		LaserLeft->dir = -GetActorRightVector();
	
	if (LaserRight->isEnable)
		LaserRight->dir = GetActorRightVector();


}

