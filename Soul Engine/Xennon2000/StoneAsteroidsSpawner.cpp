#include "StoneAsteroidsSpawner.h"

void StoneAsteroidsSpawner::Spawn()
{
	int i = GetRandomIntInRange(0,2);
	float xOffset = GetRandomFloatInRange(-.8f,.8f);
	if (i == 0)
	{
		StoneAsteroids* asteroidB = new StoneAsteroids;
		asteroidB->SetInitialPosition(position.x + xOffset, position.y);
		currentLevel->AddActor(asteroidB);
	}
	else if (i == 1)
	{
		MStoneAsteroid* asteroidM = new MStoneAsteroid;
		asteroidM->SetInitialPosition(position.x + xOffset, position.y);
		currentLevel->AddActor(asteroidM);
	}
	else if (i == 2)
	{
		SStoneAsteroid* asteroidS = new SStoneAsteroid;
		asteroidS->SetInitialPosition(position.x + xOffset, position.y);
		currentLevel->AddActor(asteroidS); 
	}
}
