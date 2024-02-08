#include "SStoneAsteroid.h"

void SStoneAsteroid::Start()
{
	//testing
	SetPosition(.25f, 1.1f);
	//--------------------------------
	currentHealth = maxHealth;
	objectType = "stoneasteroid";
	scaleX = .1f;
	scaleY = .1f;
	SetSpritesheetData("Assets/SAster32.bmp", 8, 2, scaleX, scaleY);
	SetAnimationData(16, animDuration);
	moveSpeed = 0.002;
}

void SStoneAsteroid::GetDamage(float damage)
{
	currentHealth -= damage;
	if (currentHealth <= 0.f)
	{
		Destroy();
	}
}
