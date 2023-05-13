#pragma once
#include "Managers/Matrices.h"
#include "Managers/Collision.h"
#include "Joystick.h"
#include "Button.h"
#include "Characters/Player.h"
#include "List.h"

#define DATA 8
#define CLOCK 10
#define STORE 9
#define BUTTON 6

class Game {
private:
    Matrices matrices;
    Button button;
    Player* pPlayer;
    List<Ent> listEnt;
    List<Character> listCha;
    Collision collider;
    
public:
    Game();
    ~Game();

    void start();

    void initialize();

    void endGame();

    void mainLoop();

    void updateEnt();
};