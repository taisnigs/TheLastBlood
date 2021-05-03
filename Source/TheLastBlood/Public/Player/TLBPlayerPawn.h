
#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "TLBPlayerPawn.generated.h"

UCLASS()
class THELASTBLOOD_API ATLBPlayerPawn : public ACharacter
{
	GENERATED_BODY()

public:
	ATLBPlayerPawn();

	/** First-person mesh */
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* Mesh_1P;

	/** First-person and main camera */
	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* Camera_1P;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	/** Regular movement functions */
	virtual void MoveForward(float Value);
	virtual void MoveSide(float Value);
	
};
