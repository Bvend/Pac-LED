#pragma once

#include <Arduino.h>

class Matrices {
private:
    int data;
    int clock;
    int store;
    int bitOrder;

    int picGreen[2][8], picRed[2][8];

    int valx[16];

public:
    Matrices(){}
    Matrices(int data, int clock, int store, int bitOrder = LSBFIRST);
    ~Matrices();

    void reset();

    void retainInfo();

    void draw();

    // Matrizes tem lista de entidades. Percorre lista e pega pos de tudo para imprimir
};