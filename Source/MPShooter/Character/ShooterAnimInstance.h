// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ShooterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MPSHOOTER_API UShooterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	

private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess=true), Category=Movement)
	bool bIsFalling;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess=true), Category=Movement)
	bool bIsAccelerating;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess=true), Category=Movement)
	float Speed;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess=true), Category=Character)
	class AShooterCharacter* Character;

protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	
};
