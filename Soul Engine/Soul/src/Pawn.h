#pragma once
#include "Actor.h"
class Pawn : public Actor
{
public:
	virtual void OnKeyPressed(std::string keyPressed){};
};

