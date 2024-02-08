#pragma once
#include "Asteroids.h"
class MStoneAsteroid : public Asteroids
{
public:
	void Start() override;
	void OnDestroyed() override;

	void GetDamage(float damage);

private:

	float currentHealth = 0.f;
	float maxHealth = 100.f;


};

