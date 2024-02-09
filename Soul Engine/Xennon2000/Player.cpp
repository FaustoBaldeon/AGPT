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

	SetPosition(-.8f, 0.f);
	shootPosition.x = position.x + shootPointOffset;
	shootPosition.y = position.y;

	SetSpritesheetData("Assets/Ship1.bmp", 7, 1, .2f, .2f);
	SetAnimationData(7, 1.f);
	sprite.rotate = true;

	AddCompanion(companion1YOffset);
	AddCompanion(companion2YOffset);
}

void Player::SetLevel(Level* level)
{
	currentLevel = level;
}

void Player::Shoot()
{
	Missil* pj = new Missil;
	pj->SetInitialPosition(shootPosition.x, shootPosition.y);
	currentLevel->AddActor(pj);
}

void Player::GetDamage(float damage)
{
	currentHealth -= damage;
	if (currentHealth <= 0.f && lives <= 0)
	{
		Destroy();
	}
	else if (currentHealth <= 0.f && lives > 0)
	{
		--lives;
		currentHealth = maxHealth;
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
		companion->SetOwner(this);

		companions.push_back(companion);

		currentLevel->AddActor(companion);
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
