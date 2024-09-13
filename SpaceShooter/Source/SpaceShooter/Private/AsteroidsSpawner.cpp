// Author: Pablo Sanchez


#include "AsteroidsSpawner.h"

// Sets default values
AAsteroidsSpawner::AAsteroidsSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAsteroidsSpawner::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAsteroidsSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

AAsteroid* AAsteroidsSpawner::GetAsteroidFromPool()
{
	for (AAsteroid* Asteroid : AsteroidsList)
	{
		if (!Asteroid->IsActive)
		{
			Asteroid->ActivateActor(true);
			return Asteroid;
		}
	}

	return nullptr;
}
