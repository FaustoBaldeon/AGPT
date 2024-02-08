#pragma once
#include "Actor.h"
class Asteroids :
    public Actor
{
public:
	void OnUpdate() override;

protected:
	float moveSpeed = 0.025f;
	float scaleX = .5f;
	float scaleY = .5f;
	float animDuration = .1f;
};

