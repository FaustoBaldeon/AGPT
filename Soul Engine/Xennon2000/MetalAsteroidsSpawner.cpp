#include "MetalAsteroidsSpawner.h"

void MetalAsteroidsSpawner::Spawn()
{
	int i = GetRandomIntInRange(0,2);
	float xOffset = GetRandomFloatInRange(-.8f,.8f);
	if (i == 0)
	{
		MetalAsteroids* asteroidB = new MetalAsteroids;
		asteroidB->SetInitialPosition(position.x + xOffset, position.y);
		currentLevel->AddActor(asteroidB);
	}
	else if (i == 1)
	{
		MMetalAsteroid* asteroidM = new MMetalAsteroid;
		asteroidM->SetInitialPosition(position.x + xOffset, position.y);
		currentLevel->AddActor(asteroidM);
	}
	else if (i == 2)
	{
		SMetalAsteroid* asteroidS = new SMetalAsteroid; 
		asteroidS->SetInitialPosition(position.x + xOffset, position.y); 
		currentLevel->AddActor(asteroidS); 
	}
}
