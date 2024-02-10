#pragma once
#include "Projectile.h"
class LonerProjectile : public Projectile
{
public:
	void Start() override;
	void OnUpdate() override;
	void OnCollisionEnter(Actor& actor) override;

private:
	float damageToApply = 25.f;
};

