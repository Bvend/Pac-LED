#include "Player.h"


Player::Player()
{

}

Player::~Player()
{

}

void Player::move()
{   
    //A cada interação do loop do jogo resetar a matrix
    char dir = joystick.getInput();

      if (dir == 'w') {
        //picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = 0;
        posy = (posy - 1 + 8) % 8;
        //picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = valx[posx];
        //previous_time = total_time;
      } else if (dir == 's') {
        //picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = 0;
        posy = (posy + 1) % 8;
        //picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = valx[posx];
        //previous_time = total_time;
      } else if (dir == 'a') {
        //picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = 0;
        posx = (posx + 1) % 16;
        //picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = valx[posx];
      } else if (dir == 'd') {
        //picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = 0;
        posx = (posx - 1 + 16) % 16;
        //picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = valx[posx];
      }

      movementDirection = dir;
}

void Player::update()
{
    move();
}