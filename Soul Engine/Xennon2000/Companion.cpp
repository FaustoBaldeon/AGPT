#include "Companion.h"

void Companion::Start()
{
	objectType = "ally";
	SetSpritesheetData("Assets/clone.bmp", 4, 5, .1f,.1f);
	SetAnimationData(20, .1f);
	sprite.rotate = true;
}

void Companion::SetInitialPosition(float xpos, float ypos)
{
	Actor::SetInitialPosition(xpos,ypos);
	shootPosition.x = xpos+shootOffsetX;
	shootPosition.y = ypos;
}


void Companion::Shoot()
{
 // shoot from shoot position
}
