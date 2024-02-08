#pragma once
#include "Actor.h"
class Background : public Actor
{
public:
	Background();

	 void Start() override;

	 void OnUpdate() override;

	 void SetInitialPosition(float xpos, float ypos);

private:
	float movespeed = 0.0005f;
};

