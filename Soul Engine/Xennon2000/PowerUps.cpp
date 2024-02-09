#include "PowerUps.h"

void PowerUps::Start()
{
	objectType = "powerup";
}

void PowerUps::OnUpdate()
{
	SetPosition(position.x -= movespeed * dTime, position.y);
}
