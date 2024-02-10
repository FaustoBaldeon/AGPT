#pragma once
#include "Projectile.h"

class Missil : public Projectile
{
public:
	void Start() override;
	void OnUpdate() override;
	void OnCollisionEnter(Actor& actor) override;

	void SetDamage(float damage);


private:
	float damageToApply = 25.f;
};

