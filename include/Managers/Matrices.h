#pragma once

#include <Arduino.h>

#include "Characters/Player.h"
#include "Characters/Ghost.h"
#include "Scenery.h"
#include "List/List.h"

class Matrices {
private:
    int data;
    int clock;
    int store;
    int bitOrder;
    char picGreen[2][8], picRed[2][8], valx[16];
    Player* pPlayer;
    List<Character>* pGhostList;

public:
    Matrices() {}
    Matrices(int data, int clock, int store, Player* pPlayer, List<Character>* pGhostList, int bitOrder = LSBFIRST);
    ~Matrices();

    void reset();

    void empty();

    void retainInfo();

    void updateMatrices();

    void transtitionAnimation(int win, int rows);

    void draw();
};