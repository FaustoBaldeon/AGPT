#pragma once
#include "Actor.h"
class Explosion : public Actor
{
public:
	void Start() override;
	void OnUpdate() override;

private:
	float totalFrames = 10.f;
	float frameTime = .03f;
	float elapsedTime = 0.f;
};

