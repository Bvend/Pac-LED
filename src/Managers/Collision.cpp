#include "Managers/Collision.h"
#include <Arduino.h>

Collision::Collision()
{ 
    pPlayer = NULL;
}

Collision::Collision(Player* pPlayer, Ghost* pGhost1, Ghost* pGhost2):
pPlayer(pPlayer),
pGhost1(pGhost1),
pGhost2(pGhost2)
{
}

Collision::~Collision()
{
}

void Collision::checkCollisions()
{
    if (!pPlayer->getMoved()) {
        int posy = pPlayer->getPositionY(), posx = pPlayer->getPositionX();
        int dir = pPlayer->getMovementDirection();
        int prevDir = pPlayer->getPrevMovementDirection();
        if (!((dir == 'w' && prevDir == 's') ||
              (dir == 's' && prevDir == 'w') ||
              (dir == 'a' && prevDir == 'd') ||
              (dir == 'd' && prevDir == 'a')) && 
              dir != '0') {
            playerWallCollision(posy, posx, dir);
        }

        if (!pPlayer->getMoved()) {
            playerWallCollision(posy, posx, prevDir);
        }

        if (!pPlayer->getMoved()) {
            pPlayer->setPrevMovementDirection('0');
            pPlayer->setMovementDirection('0');
            pPlayer->setMoved(true);
        }
    }

    playerCherryCollision();

    playerGhostCollision();
}

void Collision::playerWallCollision(int posy, int posx, int movementDirection)
{
    int oddPosy, evenPosy = posy;
    int oddPosx, evenPosx = posx;
    oddPosx = evenPosx; oddPosy = evenPosy;
    int dir = movementDirection;
    switch(dir) {
    case 'w': 
        oddPosy = (oddPosy - 1 + 16) % 16;
        evenPosy = (evenPosy - 2 + 16) % 16;
        break;
    case 's': 
        oddPosy = (oddPosy + 1) % 16;
        evenPosy = (evenPosy + 2) % 16;
        break;
    case 'a': 
        oddPosx = (oddPosx + 1) % 32;
        evenPosx = (evenPosx + 2) % 32;
        break;
    case 'd': 
        oddPosx = (oddPosx - 1 + 32) % 32;
        evenPosx = (evenPosx - 2 + 32) % 32;
        break;
    }
    if (!Walls::checkWall(oddPosy,oddPosx) &&
        !Walls::checkWall(evenPosy,evenPosx)) { 
        pPlayer->setPosition(evenPosy, evenPosx);
        pPlayer->setPrevMovementDirection(movementDirection);
        pPlayer->setMoved(true);
    }
}

void Collision::playerCherryCollision()
{
    int posy = pPlayer->getPositionY(), posx = pPlayer->getPositionX();
    if (Walls::checkCherry(posy, posx)) Walls::eatCherry(posy, posx);
}

void Collision::playerGhostCollision()
{
    int posy = pPlayer->getPositionY(), posx = pPlayer->getPositionX();
    if ((pGhost1->getPositionY() == posy && pGhost1->getPositionX() == posx) ||
        (pGhost2->getPositionY() == posy && pGhost2->getPositionX() == posx)) {
            pPlayer->setAlive(false);
    }
}