#pragma once

#include <Arduino.h>

class Button {
private:
    int pin;
    bool start;

public:
    Button(int p);
    ~Button();

    bool getStart() { return start; }
    void update();
};