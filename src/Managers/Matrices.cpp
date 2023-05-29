#include "Managers/Matrices.h"
#include "Game.h"

Matrices::Matrices(int d, int c, int s, Player* pPlayer, List<Character>* pGhostList, int bitOrder) :
data(d),
clock(c),
store(s),
bitOrder(bitOrder),
pPlayer(pPlayer),
pGhostList(pGhostList)
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

void Matrices::updateMatrices() {
    empty();
    int red[8][16], green[8][16];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 16; j++)
            { red[i][j] = green[i][j] = 0; }
    Element<Character>* pElemGhost = pGhostList->getFirst();
    for (int i = 0; i < pGhostList->getAmount(); i++) {
        int posy = pElemGhost->getItem()->getPositionY() / 2;
        int posx = pElemGhost->getItem()->getPositionX() / 2;
        red[posy][posx] = 1;
        pElemGhost = pElemGhost->getNext();
    }
    red[pPlayer->getPositionY()/2][pPlayer->getPositionX()/2] = 1;
    green[pPlayer->getPositionY()/2][pPlayer->getPositionX()/2] = 1;
    int numCherrys = Scenery::getTotalNumCherrys(); // arrumar isso dps
    for (int i = 0; i < numCherrys; i++) {
        int posy = Scenery::getCherryPosy(i);
        int posx = Scenery::getCherryPosx(i);
        if (Scenery::checkCherry(posy, posx) && !red[posy/2][posx/2]) green[posy/2][posx/2] = 1;
    }
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 16; j++) {
            if (red[i][j]) picRed[(int)(j/8)][i] += valx[j];
            if (green[i][j]) picGreen[(int)(j/8)][i] += valx[j];
        }
    draw();
}

void Matrices::transtitionAnimation(int win, int rows) {
    unsigned long totalTime = Game::getTotalTime();
    unsigned long rowAnimationTime = 1000/rows;
    unsigned long lastAnimationTime = Game::getTotalTime();
    for (int i = 0; i < rows; i++) {
        while (totalTime - lastAnimationTime < rowAnimationTime) {
            empty();
            win ? picGreen[0][i] = picGreen[1][i] = 255 : picRed[0][i] = picRed[1][i] = 255;
            draw();
            Game::updateTotalTime();
            totalTime = Game::getTotalTime();
        }
        lastAnimationTime = totalTime;
    }
}

void Matrices::draw()
{
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