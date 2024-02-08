#pragma once
#include "Actor.h"
class Companion : public Actor
{
public:
	void Start() override;

	void Shoot();

private:
	Position shootPosition;
};

