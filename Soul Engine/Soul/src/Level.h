#pragma once
#include "Actor.h"
#include <vector>

class Level
{
public:

	Level();
	~Level();

	void AddActor(const Actor& newActor);


private:

	std::vector<Actor> actorsLevel;

};

