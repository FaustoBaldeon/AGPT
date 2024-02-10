#include "Projectile.h"

void Projectile::OnDestroyed()
{
	Explosion* exp = new Explosion;
	exp->SetInitialPosition(position.x,position.y);
	currentLevel->AddActor(exp);
}

void Projectile::SetLevel(Level* level)
{
	currentLevel = level;
}

