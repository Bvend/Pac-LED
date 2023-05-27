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
    void setMovementDirection(char movementDirection);
    bool getCollided();
    void setCollided(bool collided);

    virtual void handleCollision(int idCol) = 0;
    virtual void update() = 0; 
};
