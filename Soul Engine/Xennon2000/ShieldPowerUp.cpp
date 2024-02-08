#include "ShieldPowerUp.h"

void ShieldPowerUp::Start()
{
	PowerUps::Start();

	healthToRestore = 50.f;

	SetSpritesheetData("Assets/PUShield.bmp", 4, 2, xScale,yScale);
	SetAnimationData(8, .1f);

	//-------- test ----------
	SetPosition (.75f, .75f);
}

void ShieldPowerUp::OnCollisionEnter(Actor& actor)
{
	if (actor.objectType == "ally")
	{
		//restore health
		Destroy();
	}
}
