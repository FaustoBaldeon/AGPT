#include "Enemy.h"

void Enemy::Start()
{
	currentHealth = totalHealth;
	objectType = "enemy";
}

void Enemy::GetDamage(float damage)
{
	currentHealth -= damage;
	if (currentHealth <= 0.f)
	{
		Destroy();
	}
}

void Enemy::OnDestroyed()
{
	delete this;
}
