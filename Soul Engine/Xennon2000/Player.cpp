#include "Player.h"
#include "ShieldPowerUp.h"
#include "Companion.h"


void Player::OnKeyPressed(std::string keyPressed)
{
	if (keyPressed == "a")
	{
		SetPosition(position.x -= movespeed*dTime, position.y);
		shootPosition.x = position.x + shootPointOffset;
		for (Companion* cptr : companions)
		{
			cptr->MoveLeft();
		}
	}
	if (keyPressed == "d")
	{
		SetPosition(position.x += movespeed*dTime, position.y);
		shootPosition.x = position.x + shootPointOffset;
		for (Companion* cptr : companions)
		{
			cptr->MoveRight();
		}
	}
	if (keyPressed == "w")
	{
		SetPosition(position.x, position.y += movespeed*dTime);
		shootPosition.y = position.y;
		for (Companion* cptr : companions)
		{
			cptr->MoveUp();
		}
	}
	if (keyPressed == "s")
	{
		SetPosition(position.x, position.y -= movespeed*dTime);
		shootPosition.y = position.y;
		for (Companion* cptr : companions)
		{
			cptr->MoveDown();
		}
	}
	if (keyPressed == "space")
	{
		Shoot();
		for (Companion* cptr : companions)
		{
			cptr->Shoot();
		}
	}
}

void Player::Start()
{	
	objectType = "ally";
	currentHealth = maxHealth;
	currentLives = maxLives;

	SetPosition(-.8f, 0.f); //initial position

	shootPosition.x = position.x + shootPointOffset;
	shootPosition.y = position.y;
	currentMissileDamage = smallMissileDamage;

	SetSpritesheetData("Assets/Ship1.bmp", 7, 1, .2f, .2f);
	SetAnimationData(7, 1.f);
	sprite.rotate = true;
	sprite.rotationAngle = -90.f;
	/*
	AddCompanion(companion1YOffset);
	AddCompanion(companion2YOffset);
	*/
	SetLivesUI();
}

void Player::SetLevel(Level* level)
{
	currentLevel = level;
}

void Player::Shoot()
{
	Missil* pj = new Missil;
	pj->SetInitialPosition(shootPosition.x, shootPosition.y);
	pj->SetDamage(currentMissileDamage);
	pj->SetLevel(currentLevel);
	currentLevel->AddActor(pj);
}

void Player::GetDamage(float damage)
{
	currentHealth -= damage;
	if (currentHealth <= 0.f && currentLives <= 0)
	{
		Destroy();
	}
	else if (currentHealth <= 0.f && currentLives > 0)
	{
		--currentLives;
		currentHealth = maxHealth;
		RemoveLiveUI();
	}
}

void Player::AddCompanion(float yoffset)
{
	if (companions.size() < 2)
	{
		Companion* companion = new Companion;

		companion->SetInitialPosition(position.x+companionXOffset, position.y+yoffset);
		companion->SetLevel(currentLevel);
		companion->SetSpeed(movespeed);
		companion->SetMissilesDamage(smallMissileDamage, mediumMissileDamage, bigMissileDamage);
		companion->SetOwner(this);

		companions.push_back(companion);

		currentLevel->AddActor(companion);
	}
}

void Player::Heal(float amount)
{
	currentHealth += amount;
	if (currentHealth > maxHealth)
	{
		currentHealth = maxHealth;
	}
}

void Player::UpgradeAmmo()
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

void Player::RemoveCompanion(Companion* comp)
{
	auto i = std::find(companions.begin(),companions.end(),comp);
	if (i != companions.end())
	{
		companions.erase(i);
		delete comp;
	}
}

void Player::SetLivesUI()
{
	for (int i = 0; i < maxLives; ++i)
	{
		LifeUI* life = new LifeUI;
		life->SetInitialPosition(-.9f + lifesUIOffset, -.9f);
		currentLevel->AddActor(life);
		livesList.push_back(life);
		lifesUIOffset+=.15f;
	}
}

void Player::RemoveLiveUI()
{
	if (!livesList.empty())
	{
		auto i = std::prev(livesList.end());
		(*i)->Destroy();
		livesList.pop_back();
	}
}
