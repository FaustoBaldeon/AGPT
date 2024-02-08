#include "PowerUps.h"

void PowerUps::Start()
{
	objectType = "powerup";
}

void PowerUps::OnUpdate()
{
	SetPosition(position.x, position.y-=movespeed*dTime);
}
