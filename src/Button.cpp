#include "Button.h"

Button::Button(int p):
pin(p),
start(false),
buttonIsPressed(false)
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

bool Button::getStart()
{
    return start;
}

void Button::setStart(bool start)
{
    this->start = start;
}

void Button::update()
{   
    int var = digitalRead(pin);
    if(var && !buttonIsPressed) { start = !start; buttonIsPressed = true; }
    else if (!var) buttonIsPressed = false;
}