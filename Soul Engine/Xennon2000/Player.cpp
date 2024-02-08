#include "Player.h"

void Player::OnKeyPressed(std::string keyPressed)
{
	if (keyPressed == "a")
	{
		SetPosition(position.x -= movespeed*dTime, position.y);
		shootPosition.x = position.x;
	}
	if (keyPressed == "d")
	{
		SetPosition(position.x += movespeed*dTime, position.y);
		shootPosition.x = position.x;
	}
	if (keyPressed == "w")
	{
		SetPosition(position.x, position.y += movespeed*dTime);
		shootPosition.y = position.y + shootPointOffset;
	}
	if (keyPressed == "s")
	{
		SetPosition(position.x, position.y -= movespeed*dTime);
		shootPosition.y = position.y + shootPointOffset;
	}
	if (keyPressed == "space")
	{
		Shoot();
		std::cout << currentLevel->actorsLevel.size() << std::endl;
	}
}

void Player::Start()
{	
	objectType = "ally";
	currentHealth = maxHealth;

	SetPosition(0.f, -.8f);
	shootPosition.x = position.x;
	shootPosition.y = position.y + shootPointOffset;

	SetSpritesheetData("Assets/Ship1.bmp", 7, 1, .25f, .25f);
	SetAnimationData(7, 1.f);
}

void Player::SetLevel(Level* level)
{
	currentLevel = level;
}

void Player::OnCollisionEnter(Actor& actor)
{

}

void Player::Shoot()
{
	std::cout << "PlayerShoot" << std::endl;
	std::cout << "XcoordShoot" << shootPosition.x << "YcoordShoot:" << shootPosition.y << std::endl;
	std::cout << "XcoordPlayer" << position.x << "YcoordPlayer:" << position.y << std::endl;
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
