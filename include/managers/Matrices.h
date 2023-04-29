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

    // Percorre o ponteiro para a lista e pega as pos x e y para imprimir
    // Ela recebe o ponteiro de uma lista do jogo.
    /* EXEMPLO :
    void draw() { 
        for(int i = 0; i<listEnt->getAmount(); i++){  
            Ent* ent = listEnt->getItem(i);
            int posX = ent->getPositionX();
            int posY = ent->getPositionY();
            //COM AS POSIÇÕES DAS ENTIDADES IMPRIMIR...
        }
    }
    */
};