#pragma once

#include "Scenery.h"
#include "Characters/Ghost.h"
#include "List/List.h"

class Collision {
private:
    Player* pPlayer;
    List<Character>* pGhostList;

public:
    Collision();
    Collision(Player* pPlayer, List<Character>* pGhostList);
    ~Collision();

    void checkCollisions();
    void playerWallCollision(int posy, int posx, int movementDirection);
    void playerCherryCollision();
    void playerGhostCollision();
};