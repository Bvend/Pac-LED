#pragma once
class Collision;

class Walls {
private:
    friend class Collision;
    int board[16][32];
public:
    Walls();
    ~Walls();
};