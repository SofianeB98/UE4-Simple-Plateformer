// Fill out your copyright notice in the Description page of Project Settings.


#include "WinDoor.h"

#include "UE4_PlateformerCharacter.h"
#include "UE4_PlateformerGameMode.h"

// Sets default values
AWinDoor::AWinDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	BoxComponent->InitBoxExtent(FVector(50.f, 50.f, 50.f));
	BoxComponent->SetCollisionProfileName("Trigger");
	RootComponent = BoxComponent;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	StaticMesh->SetupAttachment(RootComponent);

	nextLevel = "";
	number = 1;
	
	OnActorBeginOverlap.AddDynamic(this, &AWinDoor::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AWinDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWinDoor::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor != nullptr)
	{
		if (AUE4_PlateformerCharacter* player = Cast<AUE4_PlateformerCharacter>(OtherActor))
		{
			if (AUE4_PlateformerGameMode* GM = Cast<AUE4_PlateformerGameMode>(GetWorld()->GetAuthGameMode()))
			{
				UE_LOG(LogTemp, Warning, TEXT("Le joueur a win !!"));
				if(nextLevel != "")
					GM->LoadNextLevel(nextLevel);
			}
		}
	}
}


// Called every frame
void AWinDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

