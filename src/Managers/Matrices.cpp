#include "Managers/Matrices.h"

Matrices::Matrices(int d, int c, int s, List<Ent>* pL, int bitOrder) :
data(d),
clock(c),
store(s),
bitOrder(bitOrder),
pListEnt(pL)
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
    }
}

void Matrices::retainInfo()
{
    digitalWrite(store, HIGH); delayMicroseconds(10); 
    digitalWrite(store, LOW); delayMicroseconds(10);
}

void Matrices::updateMatrices()
{
    empty();
    int red[8][16], green[8][16];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 16; j++)
            red[i][j] = green[i][j] = 0;
    Element<Ent>* pElemEnt = pListEnt->getPrimeiro();
    for (int i = 0; i < pListEnt->getAmount(); i++) {
        int posx = pElemEnt->getItem()->getPositionX() / 2;
        int posy = pElemEnt->getItem()->getPositionY() / 2;
        int idElem = pElemEnt->getItem()->getId();
        if (idElem == PLAYER || idElem == GHOST) red[posy][posx] = 1;
        if (idElem == PLAYER || idElem == CHERRY) green[posy][posx] = 1;
        pElemEnt = pElemEnt->getProx();
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
    for (int i = 0; i < 8; i++) {
        shiftOut(data, clock, LSBFIRST, ~picGreen[0][i]);
        shiftOut(data, clock, LSBFIRST, ~picRed[0][i]);
        shiftOut(data, clock, LSBFIRST, ~picGreen[1][i]);
        shiftOut(data, clock, LSBFIRST, ~picRed[1][i]);
        shiftOut(data, clock, LSBFIRST, 128 >> i);
        retainInfo();
    }
}