#pragma once
#include "Ent.h"

class Character : public Ent {
protected:
    char movementDirection;

public:
    Character ();
    ~Character ();

    char getMovementDirection() { return movementDirection; } 
    virtual void update() = 0; 
};
