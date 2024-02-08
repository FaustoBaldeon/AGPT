#pragma once
#include "Actor.h"

class Enemy : public Actor
{
public:
    void GetDamage(float damage);
    void Start() override;
    void OnDestroyed() override;

protected:
    float totalHealth = 100.f;
    float currentHealth = 0.f;
};

