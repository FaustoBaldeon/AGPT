#pragma once
#include "Projectile.h"

class Missil : public Projectile
{
public:
	void Start() override;
	void OnUpdate() override;
};

