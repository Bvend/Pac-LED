#include "managers/Matrices.h"

Matrices::Matrices(int d, int c, int s, int bitOrder) :
data(data), clock(clock), store(store), bitOrder(bitOrder) { 
    reset();
    for (int i = 0; i < 8; i++) { valx[i] = 1 << i; valx[i+8] = 1 << i; }

    pinMode(d,OUTPUT);
    pinMode(s,OUTPUT);
    pinMode(c,OUTPUT);
}

Matrices::~Matrices() { }

void Matrices::reset()
{
    for (int i = 0; i < 8; i++) {
        picGreen[0][i] = 0;
        picGreen[1][i] = 0;
        picRed[0][i] = 0;
        picRed[1][i] = 0;
    }
    draw();
}

void Matrices::retainInfo() {
    // Talvez tenhamos que mudar a função delay no futuro pq ela pausa o programa completamente
    digitalWrite(store, HIGH); delayMicroseconds(10); 
    digitalWrite(store, LOW); delayMicroseconds(10);
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