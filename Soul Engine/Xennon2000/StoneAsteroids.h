#pragma once
#include "Asteroids.h"
#include "MStoneAsteroid.h"
#include "Level.h"

class StoneAsteroids : public Asteroids
{
public:
	void Start() override;
	void OnDestroyed() override;
	void GetDamage(float damage) override;

	void SpawnAsteroid(float offset);
	void SetLevel(Level* level);

private:
	float currentHealth = 0.f;
	float maxHealth = 200.f;

	float yOffsetAsteroid1 = .15f;
	float yOffsetAsteroid2 = -.15f;

	Level* currentLevel;
};

