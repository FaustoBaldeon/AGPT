#pragma once
#include "Actor.h"
#include "Explosion.h"
#include "Level.h"

class Projectile :
    public Actor
{
public:
    void OnDestroyed() override;

    void SetLevel(Level* level);

protected:
    float speed = 0.f;
    Level* currentLevel;
};

