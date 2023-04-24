#pragma once

#include "Character.h"
#include "Joystick.h"

#define VRX A1
#define VRY A0

class Player : public Character {
private:
    Joystick joystick;

public:
    Player();
    ~Player();

    void move();
    void update();
};