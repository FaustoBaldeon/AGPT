#include "EnemyProjectiles.h"

void EnemyProjectiles::Start()
{
	/*
	SetSpritesheetData("Assets/EnWeap6.bmp", 8, 1, 3.f, 3.f);
	SetAnimationData(8, .1f);*/

	SetSpritesheetData("Assets/PUShield.bmp", 4, 2, .5f, .5f);
	SetAnimationData(8, .1f);
	//-------------test---------
	SetPosition(.0f, .0f);
}

void EnemyProjectiles::OnUpdate()
{

}

void EnemyProjectiles::OnCollisionEnter(Actor& actor)
{
	if (actor.objectType == "ally")
	{
		//damage
	}
}
