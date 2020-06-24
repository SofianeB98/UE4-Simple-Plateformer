// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UE4_PlateformerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "UE4_PlateformerGameMode.h"

AUE4_PlateformerCharacter::AUE4_PlateformerCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f,0.f,75.f);
	CameraBoom->SetRelativeRotation(FRotator(0.f,180.f,0.f));

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera
	SideViewCameraComponent->SetProjectionMode(ECameraProjectionMode::Perspective);
	//SideViewCameraComponent->SetOrthoWidth(3000.0f);
	//SideViewCameraComponent->SetOrthoNearClipPlane(0.1f);
	//SideViewCameraComponent->SetOrthoFarClipPlane(100000.0f);
	
	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void AUE4_PlateformerCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &AUE4_PlateformerCharacter::MoveRight);
	
	PlayerInputComponent->BindAxis("ModifyTime", this, &AUE4_PlateformerCharacter::Test);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &AUE4_PlateformerCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AUE4_PlateformerCharacter::TouchStopped);
}

void AUE4_PlateformerCharacter::MoveRight(float Value)
{
	// add movement in that direction
	AddMovementInput(FVector(0.f,-1.f,0.f), Value);
}

void AUE4_PlateformerCharacter::Test(float val)
{
	if(val > 0.1f || val < -0.1f)
	{
		if(AUE4_PlateformerGameMode* GM = Cast<AUE4_PlateformerGameMode>(GetWorld()->GetAuthGameMode()))
		{
			GM->UpdateCustomTime(val * GetWorld()->GetDeltaSeconds() );
		}
	}
}


void AUE4_PlateformerCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	Jump();
}

void AUE4_PlateformerCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}

