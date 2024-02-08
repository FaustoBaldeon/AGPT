#include "StoneAsteroids.h"

void StoneAsteroids::Start()
{
	objectType = "stoneasteroid";
	currentHealth = maxHealth;
	//testing
	SetPosition(-.25f, 1.1f);
	//--------------------------------
	objectType = "metalasteroid";
	SetSpritesheetData("Assets/SAster96.bmp", 5, 5, scaleX, scaleY);
	SetAnimationData(25, animDuration);
	moveSpeed = 0.002;
}


void StoneAsteroids::OnDestroyed()
{
	//spawn smaller asteroids
}

void StoneAsteroids::GetDamage(float damage)
{
	currentHealth -= damage;
	if (currentHealth <= 0.f)
	{
		Destroy();
	}
}