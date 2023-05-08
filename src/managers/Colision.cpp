#include "managers/Colision.h"
#include "Element.h"

Colision::Colision()
{

}

Colision::Colision(List<Ent>* pL):
pListEnt(pL)
{
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 32; j++)
            board[i][j] = 0;
}

Colision::~Colision()
{
}

void Colision::checkColisions()
{
}

void Colision::fillBoard()
{
    Element<Ent>* pElemEnt = pListEnt->getPrimeiro();
    for (int i = 0; i < pListEnt->getAmount(); i++) {
        int posx = pElemEnt->getItem()->getPositionX();
        int posy = pElemEnt->getItem()->getPositionX();
        board[posx][posy] = pElemEnt->getItem()->getId();
        pElemEnt = pElemEnt->getProx();
    }
}