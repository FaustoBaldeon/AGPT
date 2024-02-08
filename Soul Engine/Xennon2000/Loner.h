#pragma once
#include "Enemy.h"
#include "EnemyProjectiles.h"
#include "Level.h"

class Loner : public Enemy
{	
public:
	void Start() override;
	void OnUpdate() override;
	void SetInitialPosition(float xpos, float ypos) override;
	void Shoot();

	void SetLevel(Level& level);


private:
	float moveSpeed = .15f;

	Level currentLevel;
	float shootPosOffset = .1f;
	float timeToShoot = 2.f;
	float elapsedTimeToShoot = 0.f;
	Position shootPos;
};

