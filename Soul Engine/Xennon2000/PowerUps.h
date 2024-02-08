#pragma once
#include "Actor.h"
class PowerUps : public Actor
{
public:
	void Start() override;
	void OnUpdate() override;

protected:
	float movespeed = .15f;
	float xScale = .1f;
	float yScale = .1f;

};

