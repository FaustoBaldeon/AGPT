#pragma once
#include "Actor.h"
#include "Pawn.h"
#include <vector>

class Level
{
public:

	Level();
	~Level();

	void AddActor(Actor* newActor);
	std::vector<Actor*> actorsLevel;

	void AddPawn(Pawn* newPawn);
	std::vector<Pawn*> pawnsLevel;

};

