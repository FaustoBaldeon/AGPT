#include "StoneAsteroids.h"

void StoneAsteroids::Start()
{
	objectType = "stoneasteroid";
	currentHealth = maxHealth;

	SetSpritesheetData("Assets/SAster96.bmp", 5, 5, scaleX, scaleY);
	SetAnimationData(25, animDuration);
	moveSpeed = .2f;
}


void StoneAsteroids::OnDestroyed()
{
	SpawnAsteroid(yOffsetAsteroid1);
	SpawnAsteroid(yOffsetAsteroid2);
	SpawnAsteroid(0.f);
}

void StoneAsteroids::SetLevel(Level* level)
{
	currentLevel = level;
}

void StoneAsteroids::SpawnAsteroid(float offset)
{
	MStoneAsteroid* stoneas = new MStoneAsteroid;
	stoneas->SetInitialPosition(position.x,position.y+offset);
	stoneas->SetLevel(currentLevel);
	currentLevel->AddActor(stoneas);
}

void StoneAsteroids::GetDamage(float damage)
{
	currentHealth -= damage;
	if (currentHealth <= 0.f)
	{
		Destroy();
	}
}