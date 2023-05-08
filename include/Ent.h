#pragma once

#include "managers/Matrices.h"

#define PLAYER 1
#define GHOST 2
#define CHERRY 3
#define WALL 4

class Ent {
protected:
    int posx, posy;
    int id;

public:
    Ent();
    ~Ent();

    int getPositionX() { return posx; }
    int getPositionY() { return posy; }
    int getId() { return id; }
    virtual void update() = 0;
};