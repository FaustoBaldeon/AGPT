#include "SpaceShip.h"

SpaceShip::SpaceShip(){
	SetPosition(0.f,-.5f);
	SetSpritesheetData("Assets/PUDive.bmp", 4 , 2 , .3f,.3f);
	SetAnimationData(8,.3f);
}

void SpaceShip::OnUpdate()
{
	//std::cout << "update called on player" << std::endl;
	//SetPosition(position.x+=movespeed, position.y);
}
