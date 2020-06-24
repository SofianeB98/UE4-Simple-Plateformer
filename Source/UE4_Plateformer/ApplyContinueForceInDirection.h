// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AffectedByTime.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UE4_PlateformerCharacter.h"
#include "ApplyContinueForceInDirection.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE4_PLATEFORMER_API UApplyContinueForceInDirection : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UApplyContinueForceInDirection();

	UPROPERTY(EditAnywhere, Category = "Parametre")
	float force = 100.0f;
	UPROPERTY(EditAnywhere, Category = "Parametre")
	float detectionSize = 100.0f;

	FVector forceDir;

	// declare overlap begin function
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UAffectedByTime* AffectedByTime = nullptr;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Detection")
	UBoxComponent* detectionZone;

	AUE4_PlateformerCharacter* detectedAgent;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
