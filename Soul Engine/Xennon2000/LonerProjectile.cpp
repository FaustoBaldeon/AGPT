#include "LonerProjectile.h"

void LonerProjectile::Start()
{
	SetSpritesheetData("Assets/EnWeap6.bmp", 8,1,.07f,.07f);
	SetAnimationData(8, .1f);
	speed = .32f;
}

void LonerProjectile::OnUpdate()
{
	SetPosition(position.x-=speed*dTime,position.y);
}
