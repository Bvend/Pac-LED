#pragma once

#include <Arduino.h>

class Joystick
{
private:
    int vrx;
    int vry;

public:
    Joystick(int vrx, int vry);
    ~Joystick(){}

    char getInput();
};
