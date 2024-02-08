#include "RusherSpawner.h"

void RusherSpawner::Spawn()
{
	Rusher* rusher = new Rusher;
	rusher->SetInitialPosition(position.x, position.y);
	currentLevel->AddActor(rusher);
}
