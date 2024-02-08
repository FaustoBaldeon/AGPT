#pragma once
#include "PowerUps.h"
class WeaponPowerUp : public PowerUps
{
public:
	void Start() override;
	void OnCollisionEnter(Actor& actor) override;

};

