#include "Rusher.h"

void Rusher::Start()
{
	SetSpritesheetData("Assets/rusher.bmp", 4, 6, .12f,.12f);
	SetAnimationData(24,.05f);
	Enemy::Start();
}

void Rusher::OnUpdate()
{
	SetPosition(position.x , position.y -= moveSpeed*dTime);
}
