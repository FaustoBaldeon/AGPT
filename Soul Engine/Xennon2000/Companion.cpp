#include "Companion.h"

void Companion::Start()
{
	objectType = "ally";
	SetSpritesheetData("Assets/clone.bmp", 4, 5, .1f,.1f);
	SetAnimationData(20, .1f);
}


void Companion::Shoot()
{
 // shoot from shoot position
}
