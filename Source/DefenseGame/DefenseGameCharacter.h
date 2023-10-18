// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DefenseGameCharacter.generated.h"

UCLASS(Blueprintable)
class ADefenseGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ADefenseGameCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;
};

