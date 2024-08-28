// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitCharacter.h"


// Sets default values
AUnitCharacter::AUnitCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TeamID = FGenericTeamId(0);
}

// Called when the game starts or when spawned
void AUnitCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUnitCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AUnitCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

FGenericTeamId AUnitCharacter::GetGenericTeamId() const
{
	// Return your team's ID
	return FGenericTeamId(TeamID);
}

void AUnitCharacter::SetGenericTeamId(const FGenericTeamId& NewTeamID)
{
	TeamID = NewTeamID;
}

ETeamAttitude::Type AUnitCharacter::GetTeamAttitudeTowardsImplementation(const AActor* Other) const
{
	// Determine friend or foe based on the Other actor's team ID
	const IGenericTeamAgentInterface* OtherTeamAgent = Cast<IGenericTeamAgentInterface>(Other);
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

