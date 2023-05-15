#pragma once
#include <stdio.h>
#include "Managers/Matrices.h"
#include "Managers/Collision.h"
#include "Button.h"
#include "Characters/Player.h"
#include "Walls.h"
#include "List/List.h"

#define DATA 8
#define CLOCK 10
#define STORE 9
#define BUTTON 6

class Game {
private:
    Matrices matrices;
    Button button;
    Player* pPlayer;
    Walls walls;
    List<Ent> listEnt;
    List<Character> listCha;
    Collision collider;

    static unsigned long totalGameTime;
    
public:
    Game();
    ~Game();

    void runGame();

    void initializeGame();

    void endGame();

    void mainLoop();

    void updateCha();

    static unsigned long getTotalTime();
};