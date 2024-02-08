#pragma once
#include "Actor.h"
#include "EnemyProjectiles.h"
#include "Level.h"

class Loner : public Actor
{	
public:
	void Start() override;
	void OnUpdate() override;
	void SetInitialPosition(float xpos, float ypos) override;
	void Shoot();

	void SetLevel(Level& level);


private:
	float moveSpeed = .001f;
	Level currentLevel;
	float shootPosOffset = .1f;
	float timeToShoot = 2.f;
	float elapsedTimeToShoot = 0.f;
	Position shootPos;
	float totalHealth = 100.f;
	float currentHealth = 0.f;
	void GetDamage(float damage);
	
};

