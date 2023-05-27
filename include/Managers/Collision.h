#pragma once

#include "Walls.h"
#include "Characters/Player.h"

class Collision {
private:
    Player* pPlayer;

public:
    Collision();
    Collision(Player* pPlayer);
    ~Collision();

    void checkCollisions();
};