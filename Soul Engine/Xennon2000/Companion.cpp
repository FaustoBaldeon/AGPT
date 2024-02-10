#include "Companion.h"
#include "Player.h"

void Companion::Start()
{
	objectType = "ally";
	SetSpritesheetData("Assets/clone.bmp", 4, 5, .09f,.09f);
	SetAnimationData(20, .1f);
	sprite.rotate = true;
	sprite.rotationAngle = -90.f;
	currentHealth = maxHealth;
	currentMissileDamage = smallMissileDamage;
}

void Companion::SetInitialPosition(float xpos, float ypos)
{
	Actor::SetInitialPosition(xpos,ypos);
	shootPosition.x = xpos+shootOffsetX;
	shootPosition.y = ypos;
}

void Companion::MoveDown()
{
	SetPosition(position.x, position.y -= moveSpeed * dTime);
	shootPosition.y = position.y;
}

void Companion::MoveUp()
{
	SetPosition(position.x , position.y += moveSpeed * dTime);
	shootPosition.y = position.y;
}

void Companion::MoveLeft()
{
	SetPosition(position.x -= moveSpeed * dTime, position.y );
	shootPosition.x = position.x+shootOffsetX;
}

void Companion::MoveRight()
{
	SetPosition(position.x += moveSpeed * dTime, position.y );
	shootPosition.x = position.x+shootOffsetX;
}

void Companion::SetSpeed(float nspeed)
{
	moveSpeed = nspeed;
}

void Companion::GetDamage(float damage)
{
	currentHealth -= damage;
	if (currentHealth <= 0.f)
	{
		Destroy();
	}
}

void Companion::Shoot()
{
	Missil* pj = new Missil;
	pj->SetInitialPosition(shootPosition.x, shootPosition.y);
	pj->SetDamage(currentMissileDamage);
	pj->SetLevel(currentLevel);
	currentLevel->AddActor(pj);
}

void Companion::SetMissilesDamage(float smallmiss, float mediummiss, float bigmiss)
{
	smallMissileDamage = smallmiss;
	mediumMissileDamage = mediummiss;
	bigMissileDamage = bigmiss;
}

void Companion::UpgradeAmmo()
{
	if (currentMissileDamage == smallMissileDamage)
	{
		currentMissileDamage = mediumMissileDamage;
	}
	else if (currentMissileDamage == mediumMissileDamage)
	{
		currentMissileDamage = bigMissileDamage;
	}
}

void Companion::Heal(float amount)
{
	currentHealth += amount;
	if (currentHealth > maxHealth)
	{
		currentHealth = maxHealth;
	}
}

void Companion::SetLevel(Level* level)
{
	currentLevel = level;
}

void Companion::SetOwner(Player* newowner)
{
	owner = newowner;
}

void Companion::OnDestroyed()
{
	owner->RemoveCompanion(this);
}
