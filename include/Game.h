#pragma once
#include "managers/Matrices.h"
#include "Joystick.h"
#include "Button.h"
#include "Ent.h"

#define DATA 8
#define CLOCK 10
#define STORE 9
#define BUTTON 6

class Game {
private:
    Matrices matrices;
    Button button;

public:
    Game();
    ~Game();

    void mainLoop();
};