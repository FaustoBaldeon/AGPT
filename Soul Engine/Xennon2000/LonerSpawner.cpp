#include "LonerSpawner.h"

void LonerSpawner::Spawn()
{
	Loner* loner = new Loner;
	loner->SetInitialPosition(position.x, position.y);
	currentLevel->AddActor(loner);
}
