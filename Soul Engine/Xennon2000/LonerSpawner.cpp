#include "LonerSpawner.h"

void LonerSpawner::Spawn()
{
	float randomYoffset = GetRandomFloatInRange(-0.8, 0.8);
	Loner* loner = new Loner;
	loner->SetInitialPosition(position.x, position.y+randomYoffset);
	loner->SetLevel(currentLevel);
	currentLevel->AddActor(loner);
}
