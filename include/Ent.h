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
    Ent();
    virtual ~Ent();

    int getPositionX() { return posx; }
    int getPositionY() { return posy; }
    void setPosition(int posx, int posy);
    int getId() { return id; }

    virtual void handleCollision(int idCol) = 0;
    virtual void update() = 0;
};