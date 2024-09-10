// Author: Pablo Sanchez


#include "SpaceShooter/Public/Spaceship.h"

// Sets default values
ASpaceship::ASpaceship()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASpaceship::BeginPlay()
{
	Super::BeginPlay();

	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
}

// Called every frame
void ASpaceship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float velocity = 0;

	velocity = (2 * 3.14 * 5) / DeltaTime;
}

// Called to bind functionality to input
void ASpaceship::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASpaceship::AddLife()
{
	Lives++;
}

void ASpaceship::SubstractLife()
{
	Lives--;
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Cyan, FString::FromInt(Lives));
}
