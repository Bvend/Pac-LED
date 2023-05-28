#include "Managers/Matrices.h"

Matrices::Matrices(int d, int c, int s, Player* pPlayer, Ghost* pGhost1, Ghost* pGhost2, int bitOrder) :
data(d),
clock(c),
store(s),
bitOrder(bitOrder),
pPlayer(pPlayer),
pGhost1(pGhost1),
pGhost2(pGhost2)
{ 
    for (int i = 0; i < 8; i++) { valx[i] = 1 << i; valx[i+8] = 1 << i; }
    pinMode(d,OUTPUT); pinMode(s,OUTPUT); pinMode(c,OUTPUT);
    reset();
}

Matrices::~Matrices()
{
}

void Matrices::reset()
{ 
    empty(); draw();
}

void Matrices::empty()
{
    for (int i = 0; i < 8; i++) {
        picGreen[0][i] = 0;
        picGreen[1][i] = 0;
        picRed[0][i] = 0;
        picRed[1][i] = 0;
        //for (int j = 0; j < 16; j++)
        //    { auxRed[i][j] = auxGreen[i][j] = 0; }
    }        
}

void Matrices::retainInfo()
{
    digitalWrite(store, HIGH); delayMicroseconds(10); 
    digitalWrite(store, LOW); delayMicroseconds(10);
}

/*
void Matrices::updatePic(int posy, int posx, int id)
{
    posy /= 2; posx /= 2;
    if (id == PLAYER || id == GHOST) auxRed[posy][posx] = 1;
    if (id == PLAYER || id == CHERRY) auxGreen[posy][posx] = 1;
    empty();
    int red[8][16], green[8][16];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 16; j++)
            red[i][j] = green[i][j] = 0;
    Element<Character>* pElemCha = pListCha->getPrimeiro();
    for (int i = 0; i < pListCha->getAmount(); i++) {
        int posx = pElemCha->getItem()->getPositionX() / 2;
        int posy = pElemCha->getItem()->getPositionY() / 2;
        int idElem = pElemCha->getItem()->getId();
        if (idElem == PLAYER || idElem == GHOST) red[posy][posx] = 1;
        if (idElem == PLAYER || idElem == CHERRY) green[posy][posx] = 1;
        pElemCha = pElemCha->getProx();
    }
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 16; j++) {
            if (red[i][j]) picRed[(int)(j/8)][i] += valx[j];
            if (green[i][j]) picGreen[(int)(j/8)][i] += valx[j];
        }
    draw();
}
*/

void Matrices::updateMatrices() {
    empty();
    int red[8][16], green[8][16];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 16; j++)
            { red[i][j] = green[i][j] = 0; }
    /*
    Element<Character>* pElemCha = pListCha->getPrimeiro();
    for (int i = 0; i < pListCha->getAmount(); i++) {
        int posy = pElemCha->getItem()->getPositionY() / 2;
        int posx = pElemCha->getItem()->getPositionX() / 2;
        int idElem = pElemCha->getItem()->getId();
        if (idElem == PLAYER || idElem == GHOST) red[posy][posx] = 1;
        if (idElem == PLAYER) green[posy][posx] = 1;
        pElemCha = pElemCha->getProx();
    }
    */
    red[pGhost1->getPositionY()/2][pGhost1->getPositionX()/2] = 1;
    red[pGhost2->getPositionY()/2][pGhost2->getPositionX()/2] = 1;
    red[pPlayer->getPositionY()/2][pPlayer->getPositionX()/2] = 1;
    green[pPlayer->getPositionY()/2][pPlayer->getPositionX()/2] = 1;
    int numCherrys = 9; // arrumar isso dps
    for (int i = 0; i < numCherrys; i++) {
        int posy = Walls::getCherryPosy(i);
        int posx = Walls::getCherryPosx(i);
        if (Walls::checkCherry(posy, posx) && !red[posy/2][posx/2]) green[posy/2][posx/2] = 1;
    }
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 16; j++) {
            if (red[i][j]) picRed[(int)(j/8)][i] += valx[j];
            if (green[i][j]) picGreen[(int)(j/8)][i] += valx[j];
        }
    draw();
}

void Matrices::draw()
{
    //for (int i = 0; i < 8; i++)
    //    for (int j = 0; j < 16; j++) {
    //        if (auxRed[i][j]) picRed[(int)(j/8)][i] += valx[j];
    //        if (auxGreen[i][j]) picGreen[(int)(j/8)][i] += valx[j];
    //    }
    // Para pcb inverter 1 e 0
    for (int i = 0; i < 8; i++) {
        shiftOut(data, clock, LSBFIRST, ~picGreen[0][i]);
        shiftOut(data, clock, LSBFIRST, ~picRed[0][i]);
        shiftOut(data, clock, LSBFIRST, ~picGreen[1][i]);
        shiftOut(data, clock, LSBFIRST, ~picRed[1][i]);
        shiftOut(data, clock, LSBFIRST, 128 >> i);
        retainInfo();
    }
}