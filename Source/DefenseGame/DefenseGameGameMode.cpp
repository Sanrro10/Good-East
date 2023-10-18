// Copyright Epic Games, Inc. All Rights Reserved.

#include "DefenseGameGameMode.h"
#include "DefenseGamePlayerController.h"
#include "DefenseGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADefenseGameGameMode::ADefenseGameGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ADefenseGamePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/BaseContent/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/BaseContent/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}