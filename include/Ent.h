#pragma once

#define PLAYER 1
#define GHOST 2
#define CHERRY 3
#define WALL 4

class Ent {
protected:
    int posx, posy;
    int id;

public:
    Ent(int posy = 0, int posx = 0, int id = -1);
    virtual ~Ent();

    int getPositionX();
    int getPositionY();
    void setPosition(int posx, int posy);
    int getId();

    virtual void handleCollision(int idCol) = 0;
    virtual void update() = 0;
};