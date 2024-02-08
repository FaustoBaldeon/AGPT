#include "SMetalAsteroid.h"

void SMetalAsteroid::Start()
{
	objectType = "metalasteroid";
	scaleX = .1f;
	scaleY = .1f;
	SetSpritesheetData("Assets/MAster32.bmp", 8, 2, scaleX, scaleY);
	SetAnimationData(16, animDuration);
	moveSpeed = .2f;

}
