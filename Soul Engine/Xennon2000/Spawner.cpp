#include "Spawner.h"

void Spawner::Start()
{
	SetSpritesheetData("Assets/PUDive.bmp", 4, 2, .05f,.05f);
	SetAnimationData(1,5.f);
}

int Spawner::GetRandomIntInRange(int min, int max)
{
	int randomNumber = rand() % (max - min + 1) + min;
	return randomNumber;
}

float Spawner::GetRandomFloatInRange(float min, float max)
{
	float randomNumber = min + static_cast<float>(rand()) / RAND_MAX * (max - min);
	return randomNumber;
}

void Spawner::OnUpdate()
{
	
	elapsedTimeToSpawn+=dTime;
	if (elapsedTimeToSpawn >= timeToSpawn)
	{	
		//std::cout << "spawned" << std::endl;
		/*
		Loner* loner = new Loner;
		loner->SetInitialPosition(position.x,position.y);
		currentLevel->AddActor(loner);*/
		Spawn(); 
		elapsedTimeToSpawn = 0.f;
		
	}
}

void Spawner::SetLevel(Level* level)
{ 
	currentLevel = level; 
}
