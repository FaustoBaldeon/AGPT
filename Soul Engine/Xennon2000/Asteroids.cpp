#include "Asteroids.h"


void Asteroids::OnUpdate()
{
	SetPosition(position.x, position.y-=(moveSpeed*dTime));
}

