#include "Player.h"

void Player::OnKeyPressed(std::string keyPressed)
{
	if (keyPressed == "a")
	{
		SetPosition(position.x -= movespeed, position.y);
	}
	if (keyPressed == "d")
	{
		SetPosition(position.x += movespeed, position.y);
	}
	if (keyPressed == "w")
	{
		SetPosition(position.x, position.y += movespeed);
	}
	if (keyPressed == "s")
	{
		SetPosition(position.x, position.y -= movespeed);
	}
}

void Player::Start()
{
	SetPosition(0.f, -.5f);
	SetSpritesheetData("Assets/LonerA.bmp", 4, 4, .5f, .5f);
	SetAnimationData(16, .1f);
}

