#include "Spawner.h"

void Spawner::Start()
{
	SetSpritesheetData("Assets/PUDive.bmp", 4, 2, .05f,.05f);
	SetAnimationData(1,5.f);
}

void Spawner::OnUpdate()
{
	elapsedTimeToSpawn+=dTime;
	if (elapsedTimeToSpawn >= timeToSpawn)
	{	
		std::cout << "spawned" << std::endl;

		Loner* loner = new Loner;
		loner->SetInitialPosition(position.x,position.y);
		currentLevel->AddActor(loner);

		elapsedTimeToSpawn = 0.f;
		Spawn();
	}
}

void Spawner::SetLevel(Level* level)
{
	currentLevel = level;
}
