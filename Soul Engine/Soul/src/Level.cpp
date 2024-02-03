#include "Level.h"

Level::Level()
{

}

Level::~Level()
{

}

void Level::AddActor(const Actor& newActor)
{
	actorsLevel.push_back(newActor);
}

