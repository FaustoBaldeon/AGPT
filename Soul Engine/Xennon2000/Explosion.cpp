#include "Explosion.h"

void Explosion::Start()
{
	SetSpritesheetData("Assets/explode16.bmp", 5, 2, .06f,.06f);
	SetAnimationData(totalFrames,frameTime);
}

void Explosion::OnUpdate()
{
	elapsedTime+=dTime;
	if (elapsedTime >= (totalFrames * frameTime) +.1f)
	{
		Destroy();
	}
}
