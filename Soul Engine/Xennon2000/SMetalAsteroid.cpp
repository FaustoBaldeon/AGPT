#include "SMetalAsteroid.h"

void SMetalAsteroid::Start()
{
	//testing
	SetPosition(.5f, 1.1f);
	//--------------------------------
	scaleX = .1f;
	scaleY = .1f;
	SetSpritesheetData("Assets/MAster32.bmp", 8, 2, scaleX, scaleY);
	SetAnimationData(16, animDuration);
	moveSpeed = 0.002;
	Asteroids::Start();
}
