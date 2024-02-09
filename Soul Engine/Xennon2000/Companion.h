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

	void GetDamage(float damage);

	void SetLevel(Level* level);

	void OnDestroyed() override;

	void SetOwner(Player* newowner);
private:
	Position shootPosition;
	float shootOffsetX = .1f;
	float currentHealth = 0.f;
	float maxHealth = 300.f;
	float moveSpeed = 0.f;
	Level* currentLevel;
	Player* owner;
};

