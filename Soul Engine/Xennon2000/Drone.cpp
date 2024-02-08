#include "Drone.h"

void Drone::Start()
{
	//testing
	SetPosition(-.5f, 1.1f);
	//--------------------------------
	SetSpritesheetData("Assets/drone.bmp", 8, 2, .10f, .10f);
	SetAnimationData(16, .05f);
	Enemy::Start();
}

void Drone::OnUpdate()
{
	SinMovementUpdate();
	SetPosition(sin(position.x+xSinOffset), position.y -= moveSpeed);
}

void Drone::SinMovementUpdate()
{
	elapsedMovementTime += dTime;
	if (directionFlag == true) 
	{
		xSinOffset = sin(moveSpeed * elapsedMovementTime); 
	}
	else if(directionFlag == false)
	{
		xSinOffset = sin( -moveSpeed * elapsedMovementTime);
	}
	if (elapsedMovementTime >= maxMovementTime)
	{
		elapsedMovementTime = 0.f; 
		directionFlag = !directionFlag; 
	}
}
