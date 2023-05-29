#pragma once
#include <stdio.h>
#include "Scenery.h"
#include "Button.h"
#include "Characters/Player.h"
#include "Characters/Ghost.h"
#include "Managers/Matrices.h"
#include "Managers/Collision.h"
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
    Ghost vinDiesel;
    List<Character> ghostList;
    Matrices matrices;
    Collision collider;
    char level;
    static unsigned long totalGameTime;
    
public:
    Game();
    ~Game();

    void gameLoop();

    void initializeGame();

    void endGame();

    void runGame();

    void updateCha();

    static unsigned long getTotalTime();

    static void updateTotalTime();
};