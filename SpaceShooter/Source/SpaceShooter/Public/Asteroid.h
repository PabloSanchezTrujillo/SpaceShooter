// Author: Pablo Sanchez

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Asteroid.generated.h"

UCLASS()
class SPACESHOOTER_API AAsteroid : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAsteroid();

	bool IsActive = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	FName CheckCollidedActor(AActor* OtherActor);

	bool CollisionWithPlayer(AActor* OtherActor);

	bool CollisionWithDestroyVolume(AActor* OtherActor);

	UFUNCTION(BlueprintCallable)
	void SpawnPlayerCollisionVFX(UClass* VFX, USoundBase* SoundBase);

	UFUNCTION(BlueprintCallable)
	void ActivateActor(bool Activate);
};
