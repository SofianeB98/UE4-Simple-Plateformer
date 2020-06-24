// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UE4_PlateformerGameMode.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "UE4_PlateformerCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "TimerGameState.h"

AUE4_PlateformerGameMode::AUE4_PlateformerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AUE4_PlateformerGameMode::UpdateCustomTime(float val)
{
	if(ATimerGameState* GS = Cast<ATimerGameState>(GameState))
	{
		GS->customTime = FMath::Clamp(GS->customTime + val * speedIncreaseTime, minTimeValue, maxTimeValue);
		UE_LOG(LogTemp, Warning, TEXT("Modification du custom Time %f"), GS->customTime);
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Game State mauvais !!!"));
}

float AUE4_PlateformerGameMode::getCustomTime()
{
	if (ATimerGameState* GS = Cast<ATimerGameState>(GameState))
	{
		return GS->customTime;
	}
	return 0;
}

float AUE4_PlateformerGameMode::getCustomTimeForSlider()
{
	if (ATimerGameState* GS = Cast<ATimerGameState>(GameState))
	{
		return GS->customTime / maxTimeValue;
	}
	return 0;
}

void AUE4_PlateformerGameMode::LoadNextLevel(FName name)
{
	UE_LOG(LogTemp, Error, TEXT("WIN ----- Le joueur a atteind l objectif ! EVERY GO"));
	UGameplayStatics::OpenLevel(GetWorld(), name);
}

void AUE4_PlateformerGameMode::GameOver()
{
	UE_LOG(LogTemp, Error, TEXT("GAME OVER ----- Le joueur a ete toucher par un mechant ! RELOAD"));
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}
