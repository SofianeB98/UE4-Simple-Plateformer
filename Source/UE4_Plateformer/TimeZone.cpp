// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeZone.h"

#include "AffectedByTime.h"

// Sets default values
ATimeZone::ATimeZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	BoxComponent->InitBoxExtent(FVector(50.f, 50.f, 50.f));
	RootComponent = BoxComponent;

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ATimeZone::OnOverlapBegin);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &ATimeZone::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ATimeZone::BeginPlay()
{
	Super::BeginPlay();
}

void ATimeZone::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UAffectedByTime* abt = OtherActor->FindComponentByClass<UAffectedByTime>();
	if(abt)
	{
		UE_LOG(LogTemp, Warning, TEXT("AFFECTED BY TIME DETECTED"));
		abt->SetInTimeZone(true);
		abt->SetTimeModifier(timeZoneModifier);
	}
}

void ATimeZone::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UAffectedByTime* abt = OtherActor->FindComponentByClass<UAffectedByTime>();
	if (abt)
	{
		abt->SetInTimeZone(false);
	}
}

// Called every frame
void ATimeZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

