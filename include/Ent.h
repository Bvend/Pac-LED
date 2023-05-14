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
    Ent(int posy = 0, int posx = 0, int id = -1): posx(posx), posy(posy), id(id) {}
    virtual ~Ent() {}

    int getPositionX() { return posx; }
    int getPositionY() { return posy; }
    void setPosition(int posx, int posy) { this->posx = posx; this->posy = posy; }
    int getId() { return id; }

    virtual void handleCollision(int idCol) = 0;
    virtual void update() = 0;
};