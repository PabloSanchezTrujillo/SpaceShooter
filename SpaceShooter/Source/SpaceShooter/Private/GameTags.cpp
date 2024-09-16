// Author: Pablo Sanchez


#include "GameTags.h"

GameTags::GameTags()
{
}

GameTags::~GameTags()
{
}

FName GameTags::GetTagName(GameplayTags Tag)
{
	switch (Tag)
	{
	case Spaceship:
		return FName("Spaceship");

	case Destroy:
		return FName("Destroy");

	case Asteroid:
		return FName("Asteroid");

	case Enemy:
		return FName("Enemy");

	default:
		return FName();
	}
}
