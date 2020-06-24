// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UE4_PlateformerGameMode.generated.h"

UCLASS(minimalapi)
class AUE4_PlateformerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUE4_PlateformerGameMode();

	UPROPERTY(EditAnywhere, Category = "Time Control")
	float minTimeValue = 0.0f;
	
	UPROPERTY(EditAnywhere, Category = "Time Control")
	float maxTimeValue = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Time Control")
	float speedIncreaseTime = 2.0f;

	void UpdateCustomTime(float val);

	UFUNCTION(BlueprintCallable, Category = "Custom Time")
	float getCustomTime();

	UFUNCTION(BlueprintCallable, Category = "Custom Time")
	float getCustomTimeForSlider();
	
	UFUNCTION(BlueprintCallable, Category = "Level Set")
	void LoadNextLevel(FName name);

	UFUNCTION(BlueprintCallable, Category = "Level Set")
	void GameOver();
};



