#pragma once

#include "Ent.h"

class Wall : public Ent {
private:

public:
    Wall() { id = WALL; }
    Wall(int posy, int posx) { this->posx = posx; this->posy = posy; id = WALL; }
    ~Wall() {}

    void update() {}
    void handleCollision(int idCol) {}
};