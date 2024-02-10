#pragma once
#include "Pawn.h"
#include "Level.h"
#include "Missil.h"
#include "LifeUI.h"

class Companion;

class Player : public Pawn
{
public:
	void Start() override;
	void OnKeyPressed(std::string keyPressed) override;

	void GetDamage(float damage) override;
	void Heal(float amount);

	void UpgradeAmmo();

	void Shoot();

	void SetLevel(Level* level);

	void AddCompanion(float yoffset);
	void RemoveCompanion(Companion* comp);

	void SetLivesUI();

	void RemoveLiveUI();

private:
	float movespeed = 2.f;
	float currentHealth = 0.f;
	float maxHealth = 500.f;

	int maxLives = 3;
	int currentLives = 0;
	float lifesUIOffset = 0.f;

	float shootPointOffset = .15f;
	Position shootPosition;
	float currentMissileDamage = 0.f;
	float smallMissileDamage = 25.f;
	float mediumMissileDamage = 50.f;
	float bigMissileDamage = 75.f;

	float companionXOffset = 0.1f;
	float companion1YOffset = .15f;
	float companion2YOffset = -.15f;

	std::vector<Companion*> companions;
	std::vector<LifeUI*> livesList;

	Level* currentLevel;

};

