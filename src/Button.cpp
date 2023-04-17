#include "Button.h"


Button::Button(int p) : pin(p), start(false), buttonIsPressed(false) { }

Button::~Button() { }

void Button::update() {   
    int var = digitalRead(pin);
    
    if(var && !buttonIsPressed) { start = !start; buttonIsPressed = true; }
    else if (!var) buttonIsPressed = false;

    // Serial.println(var);
}