#pragma once
#include "Enemy.h"
class Drone : public Enemy
{
public:
	void Start() override;
	void OnUpdate() override;
	void SinMovementUpdate();

private:
	float moveSpeed = 0.0035;

	float xSinOffset = 0.f;
	float elapsedMovementTime = 0.f;
	float maxMovementTime = 2.f;
	bool directionFlag = true;
};

