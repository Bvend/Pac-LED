#pragma once

#include "Character.h"
#include "Joystick.h"

#define VRX A1
#define VRY A0

class Player : public Character {
private:
    Joystick joystick;
    char prevMovementDirection;
    bool alive;

public:
    Player();
    ~Player();

    void initialize();
    char getPrevMovementDirection();
    void setPrevMovementDirection(char prevMovementDirection);
    bool getAlive();
    void setAlive(bool alive);
    void updateMovementDirection();
    void update();
};