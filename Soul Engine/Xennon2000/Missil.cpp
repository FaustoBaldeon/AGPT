#include "Missil.h"

void Missil::Start()
{
	SetSpritesheetData("Assets/missile.bmp", 2 , 3, .06f,.06f);
	SetAnimationData(2, .1);
	sprite.rotate = true;
	speed = .5f;
}
void Missil::OnUpdate()
{
	SetPosition(position.x+=speed*dTime, position.y);
}

void Missil::OnCollisionEnter(Actor& actor)
{
	if (actor.objectType == "enemy" || actor.objectType == "stoneasteroid")
	{
		actor.GetDamage(damageToApply);
		Destroy();
	}
}

void Missil::SetDamage(float damage)
{
	damageToApply = damage;
}


