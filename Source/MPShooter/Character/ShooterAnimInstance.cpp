// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAnimInstance.h"

#include "ShooterCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PawnMovementComponent.h"

void UShooterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	Character = Cast<AShooterCharacter>(TryGetPawnOwner());
	
}

void UShooterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if(!Character)
	{
		Character = Cast<AShooterCharacter>(TryGetPawnOwner());
	}
	if(!Character) return;

	FVector Velocity = Character -> GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();
	
	bIsFalling = Character->GetCharacterMovement()->IsFalling();

	bIsAccelerating = Character->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ;
}
