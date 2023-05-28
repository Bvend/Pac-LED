#pragma once

#include <Arduino.h>

#include "Characters/Player.h"
#include "Characters/Ghost.h"
#include "Walls.h"

class Matrices {
private:
    int data;
    int clock;
    int store;
    int bitOrder;
    int picGreen[2][8], picRed[2][8], valx[16];
    //List<Character>* pListCha;
    Player* pPlayer;
    Ghost* pGhost1;
    Ghost* pGhost2;

public:
    Matrices() {}
    Matrices(int data, int clock, int store, Player* pPlayer, Ghost* pGhost1, Ghost* pGhost2, int bitOrder = LSBFIRST);
    ~Matrices();

    void reset();

    void empty();

    void retainInfo();

    void updatePic(int posy, int posx, int id);

    void updateMatrices();

    void draw();
};