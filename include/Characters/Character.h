#pragma once

#define WALL 1
#define GHOST 2
#define CHERRY 3
#define PLAYER 4

class Character {
protected:
    int posx, posy;
    int id;
    char movementDirection;
    bool moved;
    unsigned long movCooldown, lastCooldown;

public:
    Character ();
    virtual ~Character ();

    int getPositionX();
    int getPositionY();
    void setPosition(int posy, int posx);
    int getId();

    char getMovementDirection();
    void setMovementDirection(char movementDirection);
    bool getMoved();
    void setMoved(bool moved);

    virtual void update() = 0; 
};
