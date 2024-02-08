#pragma once
#include "Actor.h"
class EnemyProjectiles : public Actor
{
public:
	void Start() override;
	void OnUpdate() override;
	void OnCollisionEnter(Actor& actor);

private:
	float damage = 25.f;
	float speed = .1f;

};

