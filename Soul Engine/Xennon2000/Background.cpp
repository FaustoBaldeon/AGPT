#include "Background.h"
#include <iostream>

void Background::Start()
{

}

Background::Background(){
	SetSpritesheetData("Assets/galaxy2.bmp", 1, 1, 2.f, 2.f);
}

void Background::OnUpdate()
{
	if (position.y > -2.f)
	{
		SetPosition(position.x, position.y -= movespeed);
	}
	else
	{
		position.y = 1.8f;
	}

}

void Background::SetInitialPosition(float xpos, float ypos) 
{
	SetPosition(xpos,ypos);
}
