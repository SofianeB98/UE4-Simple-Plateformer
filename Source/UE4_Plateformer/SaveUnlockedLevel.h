// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveUnlockedLevel.generated.h"

/**
 * 
 */
UCLASS()
class UE4_PLATEFORMER_API USaveUnlockedLevel : public USaveGame
{
	GENERATED_BODY()

public:
	USaveUnlockedLevel();

	UPROPERTY(VisibleAnywhere, Category = "Basics")
	int lastLevelUnlocked;

	UPROPERTY(VisibleAnywhere, Category = "Basics")
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = "Basics")
	uint32 UserIndex;

	UFUNCTION()
	void SetLastLevel(int index);

	UFUNCTION()
	USaveUnlockedLevel* LoadGame();
	
	UFUNCTION()
	void SaveGame();
};
