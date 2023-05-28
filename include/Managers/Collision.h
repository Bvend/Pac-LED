#pragma once

#include "Walls.h"
#include "Characters/Ghost.h"

class Collision {
private:
    Player* pPlayer;
    Ghost* pGhost1;
    Ghost* pGhost2;

public:
    Collision();
    Collision(Player* pPlayer, Ghost* pGhost1, Ghost* pGhost2);
    ~Collision();

    void checkCollisions();
    void playerWallCollision(int posy, int posx, int movementDirection);
    void playerCherryCollision();
    void playerGhostCollision();
};