#include "ShieldPowerUp.h"

void ShieldPowerUp::Start()
{
	PowerUps::Start();

	healthToRestore = 50.f;
	
	SetSpritesheetData("Assets/PUShield.bmp", 4, 2, xScale,yScale);
	SetAnimationData(8, .1f);
}

void ShieldPowerUp::OnCollisionEnter(Actor& actor)
{
	Player* player = dynamic_cast<Player*>(&actor);
	if (player != nullptr)
	{
		player->Heal(healthToRestore);
		Destroy();
	}
	else
	{
		Companion* companion = dynamic_cast<Companion*>(&actor);
		if (companion != nullptr)
		{
			companion->Heal(healthToRestore);
			Destroy();
		}
	}
}
