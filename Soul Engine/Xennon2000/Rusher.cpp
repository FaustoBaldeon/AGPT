#include "Rusher.h"

void Rusher::Start()
{
	//testing
	SetPosition(0.f, .5f);
	//--------------------------------
	SetSpritesheetData("Assets/rusher.bmp", 4, 6, .15f,.15f);
	SetAnimationData(24,.05f);
	currentHealth = totalHealth;
}

void Rusher::GetDamage(float damage)
{
	currentHealth-=damage;
	if (currentHealth <= 0.f)
	{
		Destroy();
	}
}

void Rusher::OnUpdate()
{
	SetPosition(position.x , position.y -= moveSpeed);
}
