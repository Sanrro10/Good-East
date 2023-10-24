// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DefenseGameCharacter.generated.h"

UCLASS(Blueprintable)
class ADefenseGameCharacter : public APawn
{
	GENERATED_BODY()

public:
	ADefenseGameCharacter();

	UCapsuleComponent* CapsuleComponent;

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;
};

