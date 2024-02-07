#pragma once
#include "Actor.h"
class EnemyProjectiles :
    public Actor
{
    void Start() override;
    void OnUpdate() override;
};

