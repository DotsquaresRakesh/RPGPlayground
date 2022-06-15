// Copyright Epic Games, Inc. All Rights Reserved.

#include "RPGPlaygroundGameMode.h"
#include "RPGPlaygroundHUD.h"
#include "RPGPlaygroundCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARPGPlaygroundGameMode::ARPGPlaygroundGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ARPGPlaygroundHUD::StaticClass();
}
