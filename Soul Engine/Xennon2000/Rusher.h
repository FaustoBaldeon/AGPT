#pragma once
#include "Enemy.h"

class Rusher : public Enemy
{
public:
    void Start() override;
    void OnUpdate() override;

private:
    float moveSpeed = .25f;
};

