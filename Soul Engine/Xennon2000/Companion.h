#pragma once
#include "Actor.h"
#include "Missil.h"
#include "Level.h"

class Player;

class Companion : public Actor
{
public:
	void Start() override;
	void SetInitialPosition(float xpos, float ypos) override;
	void SetSpeed(float nspeed);
	void Shoot();

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	void GetDamage(float damage) override;
	void Heal(float amount);

	void UpgradeAmmo();

	void SetLevel(Level* level);

	void OnDestroyed() override;

	void SetMissilesDamage(float smallmiss, float mediummiss, float bigmiss);

	void SetOwner(Player* newowner);
private:
	Position shootPosition;
	float currentMissileDamage = 0.f;
	float smallMissileDamage = 25.f;
	float mediumMissileDamage = 50.f;
	float bigMissileDamage = 75.f;

	float shootOffsetX = .1f;
	float currentHealth = 0.f;

	float maxHealth = 300.f;
	float moveSpeed = 0.f;

	Level* currentLevel;
	Player* owner;
};

