#include "SpaceShip.h"

SpaceShip::SpaceShip(){
	SetPosition(-2.f,-.5f);
	SetSpritesheetData("Assets/LonerA.bmp", 4 , 4 , 1.f,1.f);
	SetAnimationData(16,.1f);
}

void SpaceShip::OnUpdate()
{
	//std::cout << "update called on player" << std::endl;
	SetPosition(position.x+=movespeed, position.y);
}
