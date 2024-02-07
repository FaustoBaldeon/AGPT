#pragma once
#include "Actor.h"
class Drone : public Actor
{
public:
	void Start() override;
	void OnUpdate() override;
};

