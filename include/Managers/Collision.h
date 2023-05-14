#pragma once

#include "List.h"
#include "Characters/Character.h"

class Collision {
private:

    List<Ent>* pListEnt;
    List<Character>* pListCha;

    int board[16][32];

public:
    Collision();
    Collision(List<Ent>* pL, List<Character>* pC);
    ~Collision();

    void emptyBoard();

    void checkCollisions();

    void fillBoard();

};