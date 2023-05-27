#include "Characters/Player.h"
#include "Game.h"

Player::Player():
joystick(VRX, VRY)
{
  id = PLAYER;
  movCooldown = 250;
  posx = 0; posy = 0;
}

Player::~Player()
{
}

void Player::initialize()
{
  collided = false;
  movementDirection = '0';
  posx = 0; posy = 0;
}

void Player::move()
{   
  char dir = joystick.getInput();

  //if (dir == '0') dir = movementDirection;
  /**/
  if (dir == 'w') {
    posy = (posy - 2 + 16) % 16;
  } else if (dir == 's') {
    posy = (posy + 2) % 16;
  } else if (dir == 'a') {
    posx = (posx + 2) % 32;
  } else if (dir == 'd') {
    posx = (posx - 2 + 32) % 32;
  }

  movementDirection = dir;
}

void Player::update()
{
  unsigned long totalTime = Game::getTotalTime();
  if (totalTime - lastCooldown > movCooldown) {
    collided = false;
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
    movementDirection = '0';
  }
  if (idCol == GHOST) {

  }
  if (idCol == CHERRY) {

  }
}
