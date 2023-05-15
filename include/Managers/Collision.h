#pragma once

#include "List/List.h"
#include "Walls.h"
#include "Characters/Character.h"

class Collision {
private:
    Walls* pWalls;
    List<Character>* pListCha;

public:
    Collision();
    Collision(Walls* pWalls, List<Character>* pC);
    ~Collision();

    void checkCollisions();

};