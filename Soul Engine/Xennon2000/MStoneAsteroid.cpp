#include "MStoneAsteroid.h"

void MStoneAsteroid::Start()
{
	objectType = "stoneasteroid";
	currentHealth = maxHealth;
	scaleX = .2f;
	scaleY = .2f;
	SetSpritesheetData("Assets/SAster64.bmp", 8, 3, scaleX, scaleY);
	SetAnimationData(24, animDuration);
	moveSpeed = .2f;
}
void MStoneAsteroid::OnDestroyed()
{
	//spawn smaller asteroids
}

void MStoneAsteroid::GetDamage(float damage)
{
	currentHealth -= damage;
	if (currentHealth <= 0.f)
	{
		Destroy();
	}
}
