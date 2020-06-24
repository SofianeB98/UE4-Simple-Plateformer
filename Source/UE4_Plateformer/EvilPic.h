// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

#include "EvilPic.generated.h"

UCLASS()
class UE4_PLATEFORMER_API AEvilPic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEvilPic();

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, Category = "Mode")
	bool useOverlap = false;

	UPROPERTY(EditAnywhere, Category = "Parametre")
	int rayNumber = 3;
	UPROPERTY(EditAnywhere, Category = "Parametre")
	float rayOffset = 150.0f;
	UPROPERTY(EditAnywhere, Category = "Parametre")
	float rayLength = 100.0f;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
	USphereComponent* SphereComponent;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
