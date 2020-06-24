// Fill out your copyright notice in the Description page of Project Settings.


#include "ApplyContinueForceInDirection.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DrawDebugHelpers.h"
#include "UE4_PlateformerGameMode.h"

// Sets default values for this component's properties
UApplyContinueForceInDirection::UApplyContinueForceInDirection()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	detectionZone = CreateDefaultSubobject<UBoxComponent>("DetectionZone");
	detectionZone->InitBoxExtent(FVector(50.f, 50.f, 50.f));

	detectionZone->OnComponentBeginOverlap.AddDynamic(this, &UApplyContinueForceInDirection::OnOverlapBegin);
	detectionZone->OnComponentEndOverlap.AddDynamic(this, &UApplyContinueForceInDirection::OnOverlapEnd);

	detectedAgent = nullptr;
}


// Called when the game starts
void UApplyContinueForceInDirection::BeginPlay()
{
	Super::BeginPlay();

	detectedAgent = nullptr;
	
}

void UApplyContinueForceInDirection::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor != nullptr)
	{
		if (AUE4_PlateformerCharacter* player = Cast<AUE4_PlateformerCharacter>(OtherActor))
		{
			UE_LOG(LogTemp, Warning, TEXT("Le joueur est trouver !"));
			
			detectedAgent = player;
		}
	}
}

void UApplyContinueForceInDirection::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor != nullptr)
	{
		if (AUE4_PlateformerCharacter* player = Cast<AUE4_PlateformerCharacter>(OtherActor))
		{
			UE_LOG(LogTemp, Warning, TEXT("Le joueur est partie !"));
			detectedAgent = nullptr;
		}
	}
}


// Called every frame
void UApplyContinueForceInDirection::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (AffectedByTime)
	{
		if (detectedAgent != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("ON APPLIQUE UNE FORCE"));
			detectedAgent->GetCharacterMovement()->Velocity += forceDir * force * AffectedByTime->getTimeModifier() * DeltaTime;
		}
		
		detectionZone->SetBoxExtent(FVector(detectionZone->GetScaledBoxExtent().X, detectionZone->GetScaledBoxExtent().Y, detectionSize * AffectedByTime->getTimeModifier()));
		detectionZone->SetRelativeLocation(FVector(0.0f, 0.0f, detectionSize * AffectedByTime->getTimeModifier()));

		DrawDebugBox(GetWorld(), detectionZone->GetComponentLocation(), 
						detectionZone->GetScaledBoxExtent(), detectionZone->GetComponentRotation().Quaternion(), FColor(0.0f, 0.0f, 255),
						false, 0.1f, 0, 2);

	}
	

	
}

