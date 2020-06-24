// Fill out your copyright notice in the Description page of Project Settings.


#include "MovableAgent.h"

#include "UE4_PlateformerCharacter.h"
#include "UE4_PlateformerGameMode.h"

// Sets default values
AMovableAgent::AMovableAgent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComponent->InitSphereRadius(100.f);
	RootComponent = SphereComponent;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	StaticMesh->SetupAttachment(RootComponent);

	Moving = CreateDefaultSubobject<UMoveLinearAroundPoint>("Moving");

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AMovableAgent::OnOverlapBegin);
	AffectedByTime = CreateDefaultSubobject<UAffectedByTime>("AffectedByTime");
}

// Called when the game starts or when spawned
void AMovableAgent::BeginPlay()
{
	Super::BeginPlay();

	Moving->AffectedByTime = this->AffectedByTime;
	
}

void AMovableAgent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor != nullptr)
	{
		if(AUE4_PlateformerCharacter* player = Cast<AUE4_PlateformerCharacter>(OtherActor))
		{
			if (AUE4_PlateformerGameMode* GM = Cast<AUE4_PlateformerGameMode>(GetWorld()->GetAuthGameMode()))
			{
				UE_LOG(LogTemp, Warning, TEXT("Le joueur a ete toucher !!!!!"));
				GM->GameOver();
			}
		}
	}
}


// Called every frame
void AMovableAgent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	SetActorLocation(Moving->currentPosition);
}

