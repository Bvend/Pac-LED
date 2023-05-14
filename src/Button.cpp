#include "Button.h"


Button::Button(int p) : pin(p), start(false), buttonIsPressed(false)
{
    pinMode(p, INPUT);
}

Button::~Button()
{
}

void Button::setButtonIsPressed(bool pressed)
{
    buttonIsPressed = pressed;
}

void Button::update()
{   
    int var = digitalRead(pin);
    
    if(var && !buttonIsPressed) { start = !start; buttonIsPressed = true; }
    else if (!var) buttonIsPressed = false;

    // Serial.println(var);
}