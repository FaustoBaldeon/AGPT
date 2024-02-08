#include "Asteroids.h"

void Asteroids::Start()
{
	objectType = "asteroid";
}

void Asteroids::OnUpdate()
{
	SetPosition(position.x, position.y-=moveSpeed);
}

