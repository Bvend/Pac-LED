#pragma once

#include "List.h"
#include "Walls.h"
#include "Characters/Character.h"

class Collision {
private:
    Walls* pWalls;
    List<Ent>* pListEnt;
    List<Character>* pListCha;

    //int board[16][32];

public:
    Collision();
    Collision(Walls* pWalls,List<Ent>* pL, List<Character>* pC);
    ~Collision();

    void emptyBoard();

    void checkCollisions();

    void fillBoard();

};