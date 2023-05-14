#pragma once

#include <Arduino.h>

class Button {
private:
    int pin;
    bool start;
    bool buttonIsPressed;

public:
    Button();
    Button(int p);
    ~Button();

    void setButtonIsPressed(bool pressed);
    bool getStart() { return start; }
    void update();
};