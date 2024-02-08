#include "MetalAsteroids.h"

void MetalAsteroids::Start()
{
	//testing
	SetPosition(-.5f, 1.1f);
	//--------------------------------
	SetSpritesheetData("Assets/MAster96.bmp", 5, 5, scaleX, scaleY);
	SetAnimationData(25, animDuration);
	moveSpeed = 0.002;
	Asteroids::Start();
}
