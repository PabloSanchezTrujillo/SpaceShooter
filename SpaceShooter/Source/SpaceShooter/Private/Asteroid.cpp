// Author: Pablo Sanchez

#include "Asteroid.h"
#include "Spaceship.h"

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

bool AAsteroid::CollisionWithPlayer(AActor* OtherActor)
{
	if(OtherActor->Tags.IsEmpty()) return false;

	if(OtherActor->Tags[0].ToString() == "Kill")
	{
		Destroy();
	}
	else if(OtherActor->Tags[0].ToString() == "Spaceship")
	{
		ASpaceship* Player = Cast<ASpaceship>(OtherActor);
		Destroy();

		return true;
	}

	return false;
}

