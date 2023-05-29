#pragma once

#include"Player.h"
#include"Scenery.h"

class Ghost : public Character
{
private:
    static Player* pPlayer;

    unsigned long atackTime, scatterTime, lastModeChange;
    int currentMode;

    int targety, targetx, distFromTarget;

public:
    Ghost(int posy = 0, int posx = 0, unsigned long atackTime = 0, unsigned long scatterTime = 0);
    ~Ghost();

    void initialize(int posy, int posx, unsigned long cooldown,
                    unsigned long atackTime, unsigned long scatterTime);
    void setTimes(unsigned long atackTime, unsigned long scatterTime);

    int calculateDistance(int posy1, int posx1, int posy2, int posx2);

    static void setPlayer(Player* player);
    void updateMode(unsigned int totalTime);
    void move();
    void update();
};