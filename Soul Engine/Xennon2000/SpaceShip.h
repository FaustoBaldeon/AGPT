#pragma once
#include "Actor.h"

class SpaceShip : public Actor
{
public:
	SpaceShip();

	void OnUpdate() override;

private:
	float movespeed = .001f;
};

