#include "Managers/Collision.h"

Collision::Collision()
{ 
    pPlayer = NULL;
}

Collision::Collision(Player* pPlayer, List<Character>* pGhostList):
pPlayer(pPlayer),
pGhostList(pGhostList)
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
        if (dir != '0') {
            playerWallCollision(posy, posx, dir);
        }

        if (!pPlayer->getMoved()) {
            playerWallCollision(posy, posx, prevDir);
            if (!pPlayer->getMoved()) {
                pPlayer->setPrevMovementDirection('0');
                pPlayer->setMovementDirection('0');
                pPlayer->setMoved(true);
            }
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
    if (!Scenery::checkWall(oddPosy,oddPosx) &&
        !Scenery::checkWall(evenPosy,evenPosx)) { 
        pPlayer->setPosition(evenPosy, evenPosx);
        pPlayer->setPrevMovementDirection(movementDirection);
        pPlayer->setMoved(true);
    }
}

void Collision::playerCherryCollision()
{
    int posy = pPlayer->getPositionY(), posx = pPlayer->getPositionX();
    if (Scenery::checkCherry(posy, posx)) Scenery::eatCherry(posy, posx);
}

void Collision::playerGhostCollision()
{
    int posy = pPlayer->getPositionY(), posx = pPlayer->getPositionX();
    Element<Character> *pElemGhost = pGhostList->getFirst();
    for (int i = 0; i < pGhostList->getAmount() && pPlayer->getAlive(); i++)
    {
        if (pElemGhost->getItem()->getPositionY() == posy &&
            pElemGhost->getItem()->getPositionX() == posx)
            pPlayer->setAlive(false);
        pElemGhost = pElemGhost->getNext();
    }
}