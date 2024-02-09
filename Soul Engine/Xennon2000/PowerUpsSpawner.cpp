#include "PowerUpsSpawner.h"

void PowerUpsSpawner::Spawn()
{
	int randomInt = GetRandomIntInRange(0,1);
	float randomXoffset = GetRandomFloatInRange(-.8f, .8f); 
	if(randomInt == 0)
	{
		ShieldPowerUp* shieldPU = new ShieldPowerUp;
		shieldPU->SetInitialPosition(position.x + randomXoffset, position.y);
		currentLevel->AddActor(shieldPU);
	}
	else if(randomInt == 1)
	{
		WeaponPowerUp* weaponPU = new WeaponPowerUp;
		//std::unique_ptr<WeaponPowerUp> weaponPU;
		weaponPU->SetInitialPosition(position.x + randomXoffset, position.y);
		currentLevel->AddActor(weaponPU);
	}
}
