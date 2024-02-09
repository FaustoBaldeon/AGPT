#include "StoneAsteroidsSpawner.h"

void StoneAsteroidsSpawner::Spawn()
{
	int i = GetRandomIntInRange(0,2);
	float yOffset = GetRandomFloatInRange(-.8f,.8f);
	if (i == 0)
	{
		StoneAsteroids* asteroidB = new StoneAsteroids;
		asteroidB->SetInitialPosition(position.x , position.y + yOffset);
		currentLevel->AddActor(asteroidB);
	}
	else if (i == 1)
	{
		MStoneAsteroid* asteroidM = new MStoneAsteroid;
		asteroidM->SetInitialPosition(position.x , position.y + yOffset);
		currentLevel->AddActor(asteroidM);
	}
	else if (i == 2)
	{
		SStoneAsteroid* asteroidS = new SStoneAsteroid;
		asteroidS->SetInitialPosition(position.x , position.y + yOffset);
		currentLevel->AddActor(asteroidS); 
	}
}
