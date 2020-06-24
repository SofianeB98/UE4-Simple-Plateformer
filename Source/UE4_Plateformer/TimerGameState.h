// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TimerGameState.generated.h"

/**
 * 
 */
UCLASS()
class UE4_PLATEFORMER_API ATimerGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ATimerGameState();

	float customTime;
};
