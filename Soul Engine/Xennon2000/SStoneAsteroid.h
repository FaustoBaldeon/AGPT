#pragma once
#include "Asteroids.h"
class SStoneAsteroid : public Asteroids
{
public:
	void Start() override;

	void GetDamage(float damage);
private:
	float currentHealth = 0.f;
	float maxHealth = 80.f;
};

