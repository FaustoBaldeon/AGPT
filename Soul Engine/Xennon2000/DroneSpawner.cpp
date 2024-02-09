#include "DroneSpawner.h"

void DroneSpawner::Spawn()
{
	float randomXoffset = GetRandomFloatInRange(-.8f,.8f);
	Drone* drone = new Drone;
	drone->SetInitialPosition(position.x+randomXoffset, position.y);
	currentLevel->AddActor(drone);
}
