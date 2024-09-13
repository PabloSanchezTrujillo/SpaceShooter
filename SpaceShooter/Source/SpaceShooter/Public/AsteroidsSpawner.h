// Author: Pablo Sanchez

#pragma once

#include "CoreMinimal.h"
#include "Asteroid.h"
#include "AsteroidsSpawner.generated.h"

UCLASS()
class SPACESHOOTER_API AAsteroidsSpawner : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TArray<AAsteroid*> AsteroidsList;

	// Sets default values for this actor's properties
	AAsteroidsSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	AAsteroid* GetAsteroidFromPool();
};
