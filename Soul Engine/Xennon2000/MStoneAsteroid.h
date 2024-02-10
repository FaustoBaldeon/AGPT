#pragma once
#include "Asteroids.h"
#include "SStoneAsteroid.h"
#include "Level.h"

class MStoneAsteroid : public Asteroids
{
public:
	void Start() override;
	void OnDestroyed() override;
	void SetLevel(Level* level);

	void SpawnAsteroid(float offset);

	void GetDamage(float damage) override;

private:

	float currentHealth = 0.f;
	float maxHealth = 100.f;

	float yOffsetAsteroid1 = .15f;
	float yOffsetAsteroid2 = -.15f;

	Level* currentLevel;

};

