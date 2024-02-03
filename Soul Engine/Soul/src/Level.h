#pragma once
#include "Actor.h"
#include <vector>

class Level
{
public:

	Level();
	~Level();

	void AddActor(Actor& newActor);
	std::vector<Actor> actorsLevel;

};

