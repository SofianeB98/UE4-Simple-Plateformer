// Fill out your copyright notice in the Description page of Project Settings.


#include "Laser.h"

#include "BlocLaser.h"
#include "DrawDebugHelpers.h"
#include "UE4_PlateformerCharacter.h"
#include "UE4_PlateformerGameMode.h"

// Sets default values for this component's properties
ULaser::ULaser()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	isEnable = true;

	isAlternatif = false;
	alternateCycle = 1.0f;
	currentCycle = 0.0f;
	isActivate = true;

	laserLength = 500.0f;
}


// Called when the game starts
void ULaser::BeginPlay()
{
	Super::BeginPlay();
	PrimaryComponentTick.bCanEverTick = isEnable;
}


// Called every frame
void ULaser::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FHitResult hit;
	FCollisionQueryParams param;

	if(isEnable)
	{
		if (!isAlternatif)
		{
			GetWorld()->LineTraceSingleByProfile(hit, startPosition, startPosition + dir * laserLength, FName("UE4_PlateformerCharacter"));
			DrawDebugLine(GetWorld(), startPosition, startPosition + dir * laserLength, FColor::Red, false, 0.1f, 0, 2.f);

			if (hit.GetActor())
			{
				if (AUE4_PlateformerCharacter* player = Cast<AUE4_PlateformerCharacter>(hit.GetActor()))
				{
					if (AUE4_PlateformerGameMode* GM = Cast<AUE4_PlateformerGameMode>(GetWorld()->GetAuthGameMode()))
					{
						UE_LOG(LogTemp, Warning, TEXT("LASER ------- player"));
						GM->GameOver();
					}
				}
			}
		}
		else
		{
			if (isActivate)
			{
				GetWorld()->LineTraceSingleByProfile(hit, startPosition, startPosition + dir * laserLength, FName("UE4_PlateformerCharacter"));
				DrawDebugLine(GetWorld(), startPosition, startPosition + dir * laserLength, FColor::Red, false, 0.1f, 0, 2.f);

				if (hit.GetActor())
				{
					if (AUE4_PlateformerGameMode* GM = Cast<AUE4_PlateformerGameMode>(GetWorld()->GetAuthGameMode()))
					{
						UE_LOG(LogTemp, Warning, TEXT("LASER ------- player"));
						GM->GameOver();
					}
				}
			}
			
			if (AffectedByTime)
			{
				currentCycle += DeltaTime * AffectedByTime->getTimeModifier();

				if (currentCycle >= alternateCycle)
				{
					isActivate = !isActivate;
					currentCycle = 0.0f;
				}
			}
		}
	}

}

