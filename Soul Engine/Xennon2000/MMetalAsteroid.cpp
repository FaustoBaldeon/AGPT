#include "MMetalAsteroid.h"

void MMetalAsteroid::Start()
{
	//testing
	SetPosition(0.f, 1.1f);
	//--------------------------------
	objectType = "metalasteroid";
	scaleX = .2f;
	scaleY = .2f;
	SetSpritesheetData("Assets/MAster64.bmp", 8, 3, scaleX, scaleY);
	SetAnimationData(24, animDuration);
	moveSpeed = 0.002;
}
