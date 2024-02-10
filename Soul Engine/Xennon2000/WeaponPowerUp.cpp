#include "WeaponPowerUp.h"

void WeaponPowerUp::Start()
{
	PowerUps::Start();
	SetSpritesheetData("Assets/PUWeapon.bmp", 4, 2, xScale, yScale);
	SetAnimationData(8, .1f);
}

void WeaponPowerUp::OnCollisionEnter(Actor& actor)
{
	Player* player = dynamic_cast<Player*>(&actor);
	if (player != nullptr)
	{
		player->UpgradeAmmo();
		Destroy();
	}
}
