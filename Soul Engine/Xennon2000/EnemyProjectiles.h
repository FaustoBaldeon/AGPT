#pragma once
#include "Actor.h"
class EnemyProjectiles : public Actor
{
public:
    void Start() override;
    void OnUpdate() override;
    EnemyProjectiles();
private:
    float speed = .001f;
};

