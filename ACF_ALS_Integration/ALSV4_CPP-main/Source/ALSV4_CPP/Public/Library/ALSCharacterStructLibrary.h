// Project:         Advanced Locomotion System V4 on C++
// Copyright:       Copyright (C) 2020 Doğa Can Yanıkoğlu
// License:         MIT License (http://www.opensource.org/licenses/mit-license.php)
// Source Code:     https://github.com/dyanikoglu/ALSV4_CPP
// Original Author: Doğa Can Yanıkoğlu
// Contributors:    


#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Library/ALSCharacterEnumLibrary.h"

#include "ALSCharacterStructLibrary.generated.h"

class UCurveVector;
class UAnimMontage;
class UAnimSequenceBase;
class UCurveFloat;

USTRUCT(BlueprintType)
struct FALSComponentAndTransform
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FTransform Transform;

	UPROPERTY(EditAnywhere)
	class UPrimitiveComponent* Component = nullptr;
};

USTRUCT(BlueprintType)
struct FALSCameraSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float TargetArmLength = 0.0f;

	UPROPERTY(EditAnywhere)
	FVector SocketOffset;

	UPROPERTY(EditAnywhere)
	float LagSpeed = 0.0f;

	UPROPERTY(EditAnywhere)
	float RotationLagSpeed = 0.0f;

	UPROPERTY(EditAnywhere)
	bool bDoCollisionTest = true;
};

USTRUCT(BlueprintType)
struct FALSCameraGaitSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FALSCameraSettings Walking;

	UPROPERTY(EditAnywhere)
	FALSCameraSettings Running;

	UPROPERTY(EditAnywhere)
	FALSCameraSettings Sprinting;

	UPROPERTY(EditAnywhere)
	FALSCameraSettings Crouching;
};

USTRUCT(BlueprintType)
struct FALSCameraStateSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FALSCameraGaitSettings VelocityDirection;

	UPROPERTY(EditAnywhere)
	FALSCameraGaitSettings LookingDirection;

	UPROPERTY(EditAnywhere)
	FALSCameraGaitSettings Aiming;
};

USTRUCT(BlueprintType)
struct FALSMantleAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UAnimMontage* AnimMontage = nullptr;

	UPROPERTY(EditAnywhere)
	UCurveVector* PositionCorrectionCurve = nullptr;

	UPROPERTY(EditAnywhere)
	FVector StartingOffset;

	UPROPERTY(EditAnywhere)
	float LowHeight = 0.0f;

	UPROPERTY(EditAnywhere)
	float LowPlayRate = 0.0f;

	UPROPERTY(EditAnywhere)
	float LowStartPosition = 0.0f;

	UPROPERTY(EditAnywhere)
	float HighHeight = 0.0f;

	UPROPERTY(EditAnywhere)
	float HighPlayRate = 0.0f;

	UPROPERTY(EditAnywhere)
	float HighStartPosition = 0.0f;
};

USTRUCT(BlueprintType)
struct FALSMantleParams
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UAnimMontage* AnimMontage = nullptr;

	UPROPERTY(EditAnywhere)
	UCurveVector* PositionCorrectionCurve = nullptr;

	UPROPERTY(EditAnywhere)
	float StartingPosition = 0.0f;

	UPROPERTY(EditAnywhere)
	float PlayRate = 0.0f;

	UPROPERTY(EditAnywhere)
	FVector StartingOffset;
};

USTRUCT(BlueprintType)
struct FALSMantleTraceSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float MaxLedgeHeight = 0.0f;

	UPROPERTY(EditAnywhere)
	float MinLedgeHeight = 0.0f;

	UPROPERTY(EditAnywhere)
	float ReachDistance = 0.0f;

	UPROPERTY(EditAnywhere)
	float ForwardTraceRadius = 0.0f;

	UPROPERTY(EditAnywhere)
	float DownwardTraceRadius = 0.0f;
};

USTRUCT(BlueprintType)
struct FALSMovementSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float WalkSpeed = 0.0f;

	UPROPERTY(EditAnywhere)
	float RunSpeed = 0.0f;

	UPROPERTY(EditAnywhere)
	float SprintSpeed = 0.0f;

	UPROPERTY(EditAnywhere)
	UCurveVector* MovementCurve = nullptr;

	UPROPERTY(EditAnywhere)
	UCurveFloat* RotationRateCurve = nullptr;

	float GetSpeedForGait(EALSGait Gait) const
	{
		switch (Gait)
		{
		case EALSGait::Running:
			return RunSpeed;
		case EALSGait::Sprinting:
			return SprintSpeed;
		case EALSGait::Walking:
			return WalkSpeed;
		default:
			return RunSpeed;
		}
	}
};

USTRUCT(BlueprintType)
struct FALSMovementStanceSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FALSMovementSettings Standing;

	UPROPERTY(EditAnywhere)
	FALSMovementSettings Crouching;
};

USTRUCT(BlueprintType)
struct FALSMovementStateSettings : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FALSMovementStanceSettings VelocityDirection;

	UPROPERTY(EditAnywhere)
	FALSMovementStanceSettings LookingDirection;

	UPROPERTY(EditAnywhere)
	FALSMovementStanceSettings Aiming;
};

USTRUCT(BlueprintType)
struct FALSRotateInPlaceAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UAnimSequenceBase* Animation = nullptr;

	UPROPERTY(EditAnywhere)
	FName SlotName;

	UPROPERTY(EditAnywhere)
	float SlowTurnRate = 90.0f;

	UPROPERTY(EditAnywhere)
	float FastTurnRate = 90.0f;

	UPROPERTY(EditAnywhere)
	float SlowPlayRate = 1.0f;

	UPROPERTY(EditAnywhere)
	float FastPlayRate = 1.0f;
};
