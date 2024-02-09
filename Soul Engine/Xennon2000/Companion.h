#pragma once
#include "Actor.h"
class Companion : public Actor
{
public:
	void Start() override;
	void SetInitialPosition(float xpos, float ypos) override;
	void Shoot();

private:
	Position shootPosition;
	float shootOffsetX = .1f;
	float currentHealth = 0.f;
	float maxHealth = 300.f;
};

