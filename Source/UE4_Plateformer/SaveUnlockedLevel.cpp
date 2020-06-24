// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveUnlockedLevel.h"

#include "Kismet/GameplayStatics.h"

USaveUnlockedLevel::USaveUnlockedLevel()
{
	SaveSlotName = TEXT("SaveGame");
	UserIndex = 0;
	lastLevelUnlocked = 0;
}

void USaveUnlockedLevel::SetLastLevel(int index)
{
	lastLevelUnlocked = lastLevelUnlocked < index ? index : lastLevelUnlocked;
	SaveGame();
}

void USaveUnlockedLevel::SaveGame()
{
	UGameplayStatics::SaveGameToSlot(this, SaveSlotName, UserIndex);
}

USaveUnlockedLevel* USaveUnlockedLevel::LoadGame()
{
	return Cast<USaveUnlockedLevel>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, UserIndex));
}
