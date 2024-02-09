#pragma once
#include "Pawn.h"
#include "Level.h"
#include "Missil.h"

class Companion;

class Player : public Pawn
{
public:
	void Start() override;
	void OnKeyPressed(std::string keyPressed) override;

	void GetDamage(float damage);

	void Shoot();

	void SetLevel(Level* level);

	void AddCompanion(float yoffset);
	void RemoveCompanion(Companion* comp);

private:
	float movespeed = 2.f;
	float currentHealth = 0.f;
	float maxHealth = 500.f;
	int lives = 3;
	float shootPointOffset = .15f;

	Position shootPosition;

	float companionXOffset = 0.1f;
	float companion1YOffset = .15f;
	float companion2YOffset = -.15f;

	std::vector<Companion*> companions;

	Level* currentLevel;

};

