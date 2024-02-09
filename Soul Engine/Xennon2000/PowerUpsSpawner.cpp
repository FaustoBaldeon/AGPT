#include "PowerUpsSpawner.h"

void PowerUpsSpawner::Spawn()
{
	int randomInt = GetRandomIntInRange(0,1);
	float randomYoffset = GetRandomFloatInRange(-.8f, .8f); 
	if(randomInt == 0)
	{
		ShieldPowerUp* shieldPU = new ShieldPowerUp;
		shieldPU->SetInitialPosition(position.x, position.y + randomYoffset);
		currentLevel->AddActor(shieldPU);
	}
	else if(randomInt == 1)
	{
		WeaponPowerUp* weaponPU = new WeaponPowerUp;
		weaponPU->SetInitialPosition(position.x, position.y + randomYoffset);
		currentLevel->AddActor(weaponPU);
	}
}
