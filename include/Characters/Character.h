#pragma once
#include "Ent.h"

class Character : public Ent {
protected:
    char movementDirection;
    bool collided;
    unsigned long movCooldown, lastCooldown;

public:
    Character ();
    ~Character ();

    char getMovementDirection() { return movementDirection; }
    void setCollided(bool collided) { this->collided = collided; }
    bool getCollided() { return collided; }

    virtual void handleCollision(int idCol) = 0;
    virtual void update() = 0; 
};
