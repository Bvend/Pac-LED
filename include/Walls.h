#pragma once
class Collision;

class Walls {
private:
    friend class Collision;
    int wallsMap[16][32];
public:
    Walls();
    ~Walls();
    void clearWallsMap();
    void fillWallsMap();
};