#include "Level.h"

Level::Level()
{

}

Level::~Level()
{

}

void Level::AddActor(Actor& newActor)
{
	actorsLevel.push_back(newActor);
	newActor.Start();
	
}

