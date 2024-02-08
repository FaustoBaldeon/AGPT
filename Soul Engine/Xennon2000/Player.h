#pragma once
#include "Pawn.h"
#include "Missiles.h"
#include "Level.h"

class Player : public Pawn
{
public:
	void Start() override;
	void OnKeyPressed(std::string keyPressed) override;
	void OnCollisionEnter(Actor& actor) override;

	void GetDamage(float damage);

	void Shoot();

	void SetLevel(Level* level);

private:
	float movespeed = 2.f;
	float currentHealth = 0.f;
	float maxHealth = 500.f;
	int lives = 3;
	float shootPointOffset = .2f;

	Position shootPosition;

	Level* currentLevel;

};

