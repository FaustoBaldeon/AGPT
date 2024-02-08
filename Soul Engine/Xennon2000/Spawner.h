#pragma once
#include "Actor.h"
#include "Level.h"

class Spawner : public Actor
{
public:
	void OnUpdate() override;
	void Start() override;

	float timeToSpawn = 0.f;
	float elapsedTimeToSpawn = 0.f;

	Level* currentLevel;

	void SetLevel(Level* level);

	virtual void Spawn(){};

};

