#include "Asteroids.h"


void Asteroids::OnUpdate()
{
	SetPosition(position.x -= (moveSpeed * dTime), position.y);
}

