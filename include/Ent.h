#pragma once

#include "managers/Matrices.h"

class Ent {
protected:
    static Matrices* pMatrices;
    int posx, posy;

public:
    Ent();
    ~Ent();

    static void setMatrices(Matrices* m) { pMatrices = m; }
    int getPositionX() { return posx; }
    int getPositionY() { return posy; }
    virtual void update() = 0;
};