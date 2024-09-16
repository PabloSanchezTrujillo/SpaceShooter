// Author: Pablo Sanchez

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class SPACESHOOTER_API GameTags
{
public:
	GameTags();
	~GameTags();

	enum GameplayTags
	{
		Spaceship,
		Destroy,
		Asteroid,
		Enemy
	};

	static FName GetTagName(GameplayTags Tag);
};
