// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AffectedByTime.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE4_PLATEFORMER_API UAffectedByTime : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAffectedByTime();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="debug")
	float timeModifier = 1.0f;
	UPROPERTY(EditAnywhere, Category = "debug")
	bool isInTimeZone = false;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetTimeModifier(float val);
	void SetInTimeZone(bool val);
	float getTimeModifier()
	{
		return timeModifier;
	}
	
};
