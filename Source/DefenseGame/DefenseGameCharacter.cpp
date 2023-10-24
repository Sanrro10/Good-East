// Copyright Epic Games, Inc. All Rights Reserved.

#include "DefenseGameCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"

ADefenseGameCharacter::ADefenseGameCharacter()
{

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("CapsuleComponent");
	// Set size for player capsule
	CapsuleComponent->InitCapsuleSize(42.f, 96.0f);
	CapsuleComponent->SetCollisionProfileName("Pawn");
	CapsuleComponent->SetGenerateOverlapEvents(true);
	CapsuleComponent->SetCanEverAffectNavigation(false);
	CapsuleComponent->SetShouldUpdatePhysicsVolume(true);
	RootComponent = CapsuleComponent;
	
	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	//GetMovementComponent()->bOrientRotationToMovement = true; // Rotate character to moving direction
	//GetMovementComponent()->RotationRate = FRotator(0.f, 640.f, 0.f);
	//GetMovementComponent()->bConstrainToPlane = true;
	//GetMovementComponent()->bSnapToPlaneAtStart = true;

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void ADefenseGameCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}
