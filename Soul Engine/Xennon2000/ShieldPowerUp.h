#pragma once
#include "PowerUps.h"
#include "Player.h"

class ShieldPowerUp : public PowerUps
{
public:
	void Start() override;
	void OnCollisionEnter(Actor& actor) override;

private:
	float healthToRestore = 0.f;
	
};

