#pragma once
#include "Ent.h"

class Character : public Ent {
protected:
    char movementDirection;
    bool moved;
    unsigned long movCooldown, lastCooldown;

public:
    Character ();
    virtual ~Character ();

    char getMovementDirection();
    void setMovementDirection(char movementDirection);
    bool getMoved();
    void setMoved(bool moved);

    virtual void update() = 0; 
};
