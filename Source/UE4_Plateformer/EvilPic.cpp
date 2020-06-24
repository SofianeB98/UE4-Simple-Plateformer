// Fill out your copyright notice in the Description page of Project Settings.


#include "EvilPic.h"

#include "DrawDebugHelpers.h"
#include "UE4_PlateformerCharacter.h"
#include "UE4_PlateformerGameMode.h"

// Sets default values
AEvilPic::AEvilPic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComponent->InitSphereRadius(100.f);
	RootComponent = SphereComponent;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	StaticMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AEvilPic::BeginPlay()
{
	Super::BeginPlay();
	if (useOverlap)
	{
		PrimaryActorTick.bCanEverTick = false;
		SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AEvilPic::OnOverlapBegin);
	}
}

void AEvilPic::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//A voir si on fait pas sous raycast plutot

	if (OtherActor != nullptr)
	{
		if (AUE4_PlateformerCharacter* player = Cast<AUE4_PlateformerCharacter>(OtherActor))
		{
			if (AUE4_PlateformerGameMode* GM = Cast<AUE4_PlateformerGameMode>(GetWorld()->GetAuthGameMode()))
			{
				UE_LOG(LogTemp, Warning, TEXT("Le joueur a ete piquer !"));
				GM->GameOver();
			}
		}
	}
}


// Called every frame
void AEvilPic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if (!useOverlap)
	{
		FHitResult hit;

		FVector startLocation = GetActorLocation() - FVector(0, rayOffset, 0);
		FVector endLocation = GetActorUpVector() * rayLength;
		FCollisionQueryParams param;

		for (int i = 0; i < rayNumber; i++)
		{
			endLocation = startLocation + GetActorUpVector() * rayLength;
			GetWorld()->LineTraceSingleByProfile(hit, startLocation, endLocation, FName("UE4_PlateformerCharacter"));
			//GetWorld()->LineTraceSingleByChannel(hit, startLocation, endLocation, ECollisionChannel::ECC_PhysicsBody, param);
			DrawDebugLine(GetWorld(), startLocation, endLocation, FColor::Red, true, -1, 0, 4.f);

			if (hit.GetActor())
			{
				if (AUE4_PlateformerCharacter* player = Cast<AUE4_PlateformerCharacter>(hit.GetActor()))
				{
					if (AUE4_PlateformerGameMode* GM = Cast<AUE4_PlateformerGameMode>(GetWorld()->GetAuthGameMode()))
					{
						UE_LOG(LogTemp, Warning, TEXT("Le joueur a ete piquer !"));
						GM->GameOver();
					}
				}
			}

			startLocation += FVector(0, rayOffset, 0);
		}
	}
}

