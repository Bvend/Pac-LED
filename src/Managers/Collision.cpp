#include "Managers/Collision.h"
#include <Arduino.h>

Collision::Collision()
{ 
    pWalls = NULL; pListCha = NULL;
}

Collision::Collision(Walls* pWalls, List<Character>* pC):
pWalls(pWalls),
pListCha(pC)
{
}

Collision::~Collision()
{
}

void Collision::checkCollisions()
{
    Element<Character>* pElemCha = pListCha->getPrimeiro();
    for (int i = 0; i < pListCha->getAmount(); i++) {
        if (!pElemCha->getItem()->getCollided()) {
            int oddPosx, posx = pElemCha->getItem()->getPositionX();
            int oddPosy, posy = pElemCha->getItem()->getPositionY();
            oddPosx = posx; oddPosy = posy;
            int dir = pElemCha->getItem()->getMovementDirection();
            switch(dir) {
            case 'w': oddPosy = (oddPosy + 1) % 16; break;
            case 's': oddPosy = (oddPosy - 1 + 16) % 16; break;
            case 'a': oddPosx = (oddPosx - 1 + 32) % 32; break;
            case 'd': oddPosx = (oddPosx + 1) % 32; break;
            }
            if (pWalls->wallsMap[oddPosy][oddPosx] ||
                pWalls->wallsMap[posy][posx]) { 
                pElemCha->getItem()->handleCollision(WALL);
            }
        }
        pElemCha = pElemCha->getProx();
    } 
    /*
    Character<Cha>* pElemChaCol;
    pElemCha = pListCha->getPrimeiro();
    for (int i = 0; i < pListCha->getAmount(); i++) {
        pElemChaCol = pElemChaCol->getPrimeiro();
        for (int j = 0; j < pListEnt->getAmount(); j++) {
            if (pElemChaCol->getItem() != pElemCha->getItem() &&
                !pElemCha->getItem()->getCollided()) {
                int posx1 = pElemCha->getItem()->getPositionX();
                int posy1 = pElemCha->getItem()->getPositionY();
                int posx2 = pElemChaCol->getItem()->getPositionX();
                int posy2 = pElemChaCol->getItem()->getPositionY();
                if (posx1 == posx2 && posy1 == posy2) {
                    pElemCha->getItem()->handleCollision(pElemEnt->getItem()->getId());
                    pElemChaCol->getItem()->handleCollision(pElemCha->getItem()->getId());
                }
            }
            pElemChaCol = pElemChaCol->getProx();
        }
        pElemCha = pElemCha->getProx();
    }
    */
}