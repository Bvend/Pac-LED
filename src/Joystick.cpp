#include "Joystick.h"
#include "Game.h"

Joystick::Joystick(int vrx, int vry):
vrx(vrx),
vry(vry),
lastCooldown(0),
readCooldown(10)
{
}

char Joystick::getInput()
{
    unsigned long totalTime = Game::getTotalTime();
    if (totalTime - lastCooldown > readCooldown) {
        lastCooldown = totalTime;
        int x = analogRead(vrx);
        int y = analogRead(vry);
        if (y > 769 && x < 768 && x > 256) return 'w';
        if (x < 255 && y < 768 && y > 256) return 'd';
        if (y < 255 && x < 768 && x > 256) return 's';
        if (x > 769 && y < 768 && y > 256) return 'a';
    }
    return '0';
}
