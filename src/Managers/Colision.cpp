#include "Managers/Collision.h"
#include "Element.h"

Collision::Collision()
{

}

Collision::Collision(List<Ent>* pL):
pListEnt(pL)
{
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 32; j++)
            board[i][j] = 0;
}

Collision::~Collision()
{

}

void Collision::checkCollisions()
{
    // PRIMERIRO CHECAR COLISÕES USANDO BOARD COM PAREDES ENTRE PONTOS
    Element<Character>* pElemCha = pListCha->getPrimeiro();
    for (int i = 0; i < pListEnt->getAmount(); i++) {
        int posx = pElemCha->getItem()->getPositionX();
        int posy = pElemCha->getItem()->getPositionX();
        int movDir = pElemCha->getItem()->getMovementDirection();

        switch(movDir) {
            case 'w':
                posy = (posy + 1) % 16;
                break;
            case 's':
                posy = (posy - 1 + 16) % 16;
                break;
            case 'a':
                posx = (posx - 1 + 32) % 32;
                break;
            case 'd':
                posx = (posx + 1) % 32;
                break;
        }
        if (board[posy][posx]) pElemCha->getItem()->handleCollision(WALL);
        pElemCha = pElemCha->getProx();
    }

    // SEGUNDO LOOP CHECAR COLISÕES ENTRE PERSONAGENS E DEMAIS ENTIDADES
    Element<Ent>* pElemEnt;
    pElemCha = pListCha->getPrimeiro();
    for (int i = 0; i < pListEnt->getAmount(); i++) {
        pElemEnt = pListEnt->getPrimeiro();
        for (int j = 0; j < pListEnt->getAmount(); j++) {
            if (i != j && !pElemCha->getItem()->getCollided()) {
                int posx1 = pElemCha->getItem()->getPositionX();
                int posy1 = pElemCha->getItem()->getPositionY();
                int posx2 = pElemEnt->getItem()->getPositionX();
                int posy2 = pElemEnt->getItem()->getPositionY();
                if (posx1 == posx2 && posy1 == posy2) {
                    pElemCha->getItem()->handleCollision(pElemEnt->getItem()->getId());
                    pElemEnt->getItem()->handleCollision(pElemCha->getItem()->getId());
                }
            }
            pElemEnt = pElemEnt->getProx();
        }
        pElemCha = pElemCha->getProx();
    }
}

void Collision::fillBoard()
{
    Element<Ent>* pElemEnt = pListEnt->getPrimeiro();
    for (int i = 0; i < pListEnt->getAmount(); i++) {
        if (pElemEnt->getItem()->getId() == WALL) {
            int posx = pElemEnt->getItem()->getPositionX();
            int posy = pElemEnt->getItem()->getPositionX();
            board[posy][posx] = pElemEnt->getItem()->getId();
            pElemEnt = pElemEnt->getProx();
        }
    }
}