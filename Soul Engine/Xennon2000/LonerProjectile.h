#pragma once
#include "Projectile.h"
class LonerProjectile : public Projectile
{
public:
	void Start() override;
	void OnUpdate() override;
};

