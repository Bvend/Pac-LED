#pragma once

#include<Ent.h>

class Wall : public Ent {
private:

public:
    Wall();
    ~Wall();

    void update();
    void handleCollision(int idCol);
};