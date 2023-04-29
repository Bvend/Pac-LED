#pragma once

#include "managers/Matrices.h"

class Ent {
protected:
    int posx, posy;

public:
    Ent();
    ~Ent();

    int getPositionX() { return posx; }
    int getPositionY() { return posy; }
    virtual void update() = 0;
};