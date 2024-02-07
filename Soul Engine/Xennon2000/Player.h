#pragma once
#include "Pawn.h"
class Player : public Pawn
{
public:
	void Start() override;
	void OnKeyPressed(std::string keyPressed) override;

private:
	float movespeed = .02f;

};

