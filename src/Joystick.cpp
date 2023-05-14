#include "Joystick.h"

Joystick::Joystick(int vrx, int vry) : vrx(vrx), vry(vry) { }

char Joystick::getInput()
{
    int x = analogRead(vrx);
    int y = analogRead(vry);

    //Serial.print("Y = ");
    //Serial.println(y);
    //Serial.print("X = ");
    //Serial.println(x);

    if (y > 1000 && x < 768 && x > 256) return 'w';
    if (x < 100 && y < 768 && y > 256) return 'd';
    if (y < 100 && x < 768 && x > 256) return 's';
    if (x > 1000 && y < 768 && y > 256) return 'a';

    //Serial.println("yay");

    return '0';
}
