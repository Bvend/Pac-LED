#pragma once

#include <Arduino.h>

class Matrices {
private:
    int data;
    int clock;
    int store;
    int bitOrder;

public:
    Matrices(int data, int clock, int store, int bitOrder = LSBFIRST);
    ~Matrices();

    void retainInfo();

    void draw();
};