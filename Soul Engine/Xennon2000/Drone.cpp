#include "Drone.h"

void Drone::Start()
{
	SetSpritesheetData("Assets/drone.bmp", 8, 2, .12f, .12f);
	SetAnimationData(16, .05f);
	Enemy::Start();
}

void Drone::OnUpdate()
{
	SinMovementUpdate();
	SetPosition(sin(position.x+xSinOffset), position.y -= moveSpeed*dTime);
}

void Drone::SinMovementUpdate()
{
	elapsedMovementTime += dTime;
	if (directionFlag == true) 
	{
		xSinOffset = sin(moveSpeed * dTime * elapsedMovementTime);
	}
	else if(directionFlag == false)
	{
		xSinOffset = sin( -moveSpeed * dTime * elapsedMovementTime);
	}
	if (elapsedMovementTime >= maxMovementTime)
	{
		elapsedMovementTime = 0.f; 
		directionFlag = !directionFlag; 
	}
}
