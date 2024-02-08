#pragma once
#include "Actor.h"
class Rusher :
    public Actor
{
public:
    void Start() override;
    void OnUpdate() override;

private:
    float moveSpeed = .0015f;
    float totalHealth = 100.f;
    float currentHealth = 0.f;
    void GetDamage(float damage);
};

