#pragma once
#include <stdio.h>
#include "Managers/Matrices.h"
#include "Managers/Collision.h"
#include "Button.h"
#include "Characters/Player.h"
#include "Characters/Ghost.h"
#include "Walls.h"
#include "List/List.h"

#define DATA 8
#define CLOCK 10
#define STORE 9
#define BUTTON 6

class Game {
private:
    Button button;
    Player player;
    Ghost goodCop;
    Ghost badCop;
    //Ghost coop;
    Matrices matrices;
    Collision collider;
    // ttt[16][32];

    static unsigned long totalGameTime;
    
public:
    Game();
    ~Game();

    void gameLoop();

    void initializeGame();

    void endGame();

    void runGame();

    void updateCha();

    void updateMatrices();

    static unsigned long getTotalTime();
};