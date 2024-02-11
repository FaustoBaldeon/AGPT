#pragma once
#include "Actor.h"
#include "Level.h"
#include <cstdlib>

class Spawner : public Actor
{
public:
	void OnUpdate() override;
	void Start() override;

	float timeToSpawn = 0.f;
	float elapsedTimeToSpawn = 0.f;

	Level* currentLevel;

	void SetLevel(Level* level);

protected:
	virtual void Spawn(){};
	int GetRandomIntInRange(int min, int max);
	float GetRandomFloatInRange(float min, float max);

};

