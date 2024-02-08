#include "WeaponPowerUp.h"

void WeaponPowerUp::Start()
{
	PowerUps::Start();
	SetSpritesheetData("Assets/PUWeapon.bmp", 4, 2, xScale, yScale);
	SetAnimationData(8, .1f);
	//-------- test ----------
	SetPosition(-.75f, .75f);
}

void WeaponPowerUp::OnCollisionEnter(Actor& actor)
{
	if (actor.objectType == "ally")
	{
		//upgrade weapon
		Destroy();
	}
}
