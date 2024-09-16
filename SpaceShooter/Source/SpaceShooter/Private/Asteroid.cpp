// Author: Pablo Sanchez

#include "Asteroid.h"

#include "GameTags.h"
#include "Spaceship.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAsteroid::AAsteroid()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAsteroid::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAsteroid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FName AAsteroid::CheckCollidedActor(AActor* OtherActor)
{
	return (OtherActor->Tags.IsEmpty()) ? FName() : OtherActor->Tags[0];
}

bool AAsteroid::CollisionWithPlayer(AActor* OtherActor)
{
	if (OtherActor->Tags.IsEmpty())
	{
		return false;
	}

	if (OtherActor->Tags[0] == GameTags::GetTagName(GameTags::Spaceship))
	{
		ASpaceship* Player = Cast<ASpaceship>(OtherActor);
		Player->SubstractLife();

		return true;
	}

	return false;
}

bool AAsteroid::CollisionWithDestroyVolume(AActor* OtherActor)
{
	if (OtherActor->Tags.IsEmpty())
	{
		return false;
	}

	if (OtherActor->Tags[0] == GameTags::GetTagName(GameTags::Destroy))
	{
		return true;
	}

	return false;
}

void AAsteroid::SpawnPlayerCollisionVFX(UClass* VFX, USoundBase* SoundBase)
{
	GetWorld()->SpawnActor<AActor>(VFX, GetActorLocation(), GetActorRotation());
	UGameplayStatics::PlaySound2D(GetWorld(), SoundBase);
}

void AAsteroid::ActivateActor(bool Activate)
{
	IsActive = Activate;

	// When an actor is deactivated (Active = false) needs to be hidden in game (true)
	SetActorHiddenInGame(!Activate);
	SetActorEnableCollision(Activate);
	SetActorTickEnabled(Activate);
}
