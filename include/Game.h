#pragma once
#include "managers/Matrices.h"
#include "managers/Colision.h"
#include "Joystick.h"
#include "Button.h"
#include "Player.h"
#include "List.h"

#define DATA 8
#define CLOCK 10
#define STORE 9
#define BUTTON 6

class Game {
private:
    Matrices matrices;
    Button button;
    Player player;
    List<Ent> listEnt;
    Colision colider;
    
public:
    Game();
    ~Game();

    void mainLoop();

    void updateEnt();
};