#include "SpaceShip.h"

SpaceShip::SpaceShip(){
	SetPosition(-0.f,-.5f);
	SetSpritesheetData("Assets/LonerB.bmp", 4 , 4 , .2f,.2f);
	SetAnimationData(16,.1f);
}

void SpaceShip::OnUpdate()
{
	//std::cout << "update called on player" << std::endl;
	SetPosition(position.x+=movespeed, position.y);
}
