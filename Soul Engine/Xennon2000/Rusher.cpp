#include "Rusher.h"

void Rusher::Start()
{
	//testing
	SetPosition(0.f, .5f);
	//--------------------------------
	SetSpritesheetData("Assets/rusher.bmp", 4, 6, .15f,.15f);
	SetAnimationData(24,.05f);
	Enemy::Start();
}

void Rusher::OnUpdate()
{
	SetPosition(position.x , position.y -= moveSpeed*dTime);
}
