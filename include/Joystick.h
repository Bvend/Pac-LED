#pragma once

#include <Arduino.h>

class Joystick {
private:
    int vrx;
    int vry;
    unsigned long lastCooldown;
    unsigned long readCooldown;

public:
    Joystick(int vrx, int vry);
    Joystick(){}
    ~Joystick(){}

    char getInput();
};
