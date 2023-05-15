#pragma once

#include <Arduino.h>

#include "Characters/Character.h"
#include "List/List.h"

class Matrices {
private:
    int data;
    int clock;
    int store;
    int bitOrder;
    int picGreen[2][8], picRed[2][8];
    int valx[16];

    List<Character>* pListCha;

public:
    Matrices(){}
    Matrices(int data, int clock, int store, List<Character>* pListCha, int bitOrder = LSBFIRST);
    ~Matrices();

    void reset();

    void empty();

    void retainInfo();

    void updateMatrices();

    void draw();
};