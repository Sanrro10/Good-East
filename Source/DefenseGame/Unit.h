// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "GameFramework/Character.h"
#include "Unit.generated.h"

UCLASS(Blueprintable)
class AUnit : public ACharacter, public IGenericTeamAgentInterface
{
	GENERATED_BODY()
	
private:
	FGenericTeamId TeamNumber;

	public:
	virtual FGenericTeamId GetGenericTeamId() const override
	{
		
		// Return your team's ID
		return FGenericTeamId(TeamNumber);
	}

	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override
	{
		// Determine friend or foe based on the Other actor's team ID
		const IGenericTeamAgentInterface* OtherTeamAgent = Cast<IGenericTeamAgentInterface>(&Other);
		if (OtherTeamAgent)
		{
			if (OtherTeamAgent->GetGenericTeamId() == GetGenericTeamId())
			{
				return ETeamAttitude::Friendly;
			}
			else
			{
				return ETeamAttitude::Hostile;
			}
		}

		return ETeamAttitude::Neutral;
	}
};

