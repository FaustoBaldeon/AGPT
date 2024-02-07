#pragma once
#include "Actor.h"
class Asteroids :
    public Actor
{
public:
	void Start() override;
	void OnUpdate() override;
};

