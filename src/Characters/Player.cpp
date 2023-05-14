#include "Characters/Player.h"
#include "Game.h"

Player::Player() :
joystick(VRX, VRY)
{
  id = PLAYER;
  movCooldown = 250;
  posx = 0; posy = 0;
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
    posy = (posy - 2 + 16) % 16;
    //picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = valx[posx];
    //previous_time = total_time;
  } else if (dir == 's') {
    //picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = 0;
    posy = (posy + 2) % 16;
    //picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = valx[posx];
    //previous_time = total_time;
  } else if (dir == 'a') {
    //picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = 0;
    posx = (posx + 2) % 32;
    //picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = valx[posx];
  } else if (dir == 'd') {
    //picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = 0;
    posx = (posx - 2 + 32) % 32;
    //picGreen[(int)(posx/8)][posy] = picRed[(int)(posx/8)][posy] = valx[posx];
  }

  movementDirection = dir;
}

void Player::update()
{
  collided = false;

  unsigned long totalTime = Game::getTotalTime();
  if (totalTime - lastCooldown > movCooldown) {
    lastCooldown = totalTime;
    move();
  }
  
}

void Player::handleCollision(int idCol)
{
  if (idCol == WALL) {
    collided = true;
    switch(movementDirection) {
      case 'w':
          posy = (posy + 2) % 16;
          break;
      case 's':
          posy = (posy - 2 + 16) % 16;
          break;
      case 'a':
          posx = (posx - 2 + 32) % 32;
          break;
      case 'd':
          posx = (posx + 2) % 32;
          break;
    }
  }
  if (idCol == GHOST) {

  }
  if (idCol == CHERRY) {

  }
}
