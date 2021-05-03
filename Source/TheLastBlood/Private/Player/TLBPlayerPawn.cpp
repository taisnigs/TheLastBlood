
#include "Player/TLBPlayerPawn.h"

// Constructor
ATLBPlayerPawn::ATLBPlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	
	/** Create components */
	Mesh_1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FPMesh"));
	Camera_1P = CreateDefaultSubobject<UCameraComponent>(TEXT("FPCamera"));

	/** Attach camera to root (capsule) and allow to look around */
	Camera_1P->SetupAttachment(RootComponent);
	Camera_1P->bUsePawnControlRotation = true;
	
	/** Attach first person mesh to camera */
	Mesh_1P->SetupAttachment(Camera_1P);

	/** Make sure that local player can only see FP mesh, and remotes can only see third person mesh  */
	GetMesh()->bOwnerNoSee = true;
	GetMesh()->bCastHiddenShadow = true;
	Mesh_1P->bOnlyOwnerSee = true;
	Mesh_1P->CastShadow = false;
}

void ATLBPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
}

void ATLBPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATLBPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	/** Bind movement */
	PlayerInputComponent->BindAxis("MoveForward", this, &ATLBPlayerPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveSide", this, &ATLBPlayerPawn::MoveSide);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ATLBPlayerPawn::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ATLBPlayerPawn::StopJumping);
	
	PlayerInputComponent->BindAction("Duck", IE_Pressed, this, &ATLBPlayerPawn::Duck);
	PlayerInputComponent->BindAction("Duck", IE_Released, this, &ATLBPlayerPawn::UnDuck);
	
}

void ATLBPlayerPawn::MoveForward(float Value)
{
	if(Value)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void ATLBPlayerPawn::MoveSide(float Value)
{
	if(Value)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

// Later, i will implement some advanced logic here. - jffrey
void ATLBPlayerPawn::Duck()
{
	Crouch();
}

void ATLBPlayerPawn::UnDuck()
{
	UnCrouch();
}

