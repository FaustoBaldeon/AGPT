#include "RusherSpawner.h"

void RusherSpawner::Spawn()
{
	float randomXOffset = GetRandomFloatInRange(-.8f,.8f);
	Rusher* rusher = new Rusher;
	rusher->SetInitialPosition(position.x+randomXOffset, position.y);
	currentLevel->AddActor(rusher);
}
