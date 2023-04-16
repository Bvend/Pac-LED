#include "Button.h"


Button::Button(int p) : pin(p), start(false)
{
}

Button::~Button()
{

}

void Button::update()
{   
    int var = digitalRead(pin);
    Serial.println(var);
    if(var){  start = !start; }
}