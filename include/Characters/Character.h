#pragma once
#include "Ent.h"

class Character : public Ent {
protected:
    char movementDirection;
    bool collided;
    unsigned long movCooldown, lastCooldown;

public:
    Character ();
    virtual ~Character ();

    char getMovementDirection();
    void setCollided(bool collided);
    bool getCollided();

    virtual void handleCollision(int idCol) = 0;
    virtual void update() = 0; 
};
