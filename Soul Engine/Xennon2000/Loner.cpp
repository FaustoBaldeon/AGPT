#include "Loner.h"

void Loner::Start()
{
	SetSpritesheetData("Assets/LonerA.bmp", 4, 4, .2f, .2f);
	SetAnimationData(16, .1f);
	Enemy::Start();
}
void Loner::OnUpdate() 
{
	SetPosition(position.x+=moveSpeed*dTime,position.y);
	shootPos.x = position.x;
	Shoot();
}
void Loner::SetInitialPosition(float xpos, float ypos)
{
	Actor::SetInitialPosition(xpos,ypos);
	shootPos.x = xpos;
	shootPos.y = ypos+shootPosOffset;
}

void Loner::Shoot()
{
	elapsedTimeToShoot += dTime;
	if (elapsedTimeToShoot >= timeToShoot)
	{
		elapsedTimeToShoot = 0.f;
		std::cout << "Shoot" << std::endl;
	}
}
void Loner::SetLevel(Level* level) 
{
	currentLevel = level;
}
