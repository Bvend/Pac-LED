#include "Characters/Player.h"
#include "Game.h"

Player::Player():
joystick(VRX, VRY),
prevMovementDirection('0'),
alive(true)
{
  id = PLAYER;
  movCooldown = 350;
  posy = 4; posx = 20;
}

Player::~Player()
{
}

void Player::initialize()
{
  moved = false;
  movementDirection = '0';
  prevMovementDirection = '0';
  posy = 4;
  posx = 20;
  alive = true;
}

char Player::getPrevMovementDirection()
{
  return prevMovementDirection;
}

void Player::setPrevMovementDirection(char prevMovementDirection)
{
  this->prevMovementDirection = prevMovementDirection;
}

bool Player::getAlive()
{
  return alive;
}

void Player::setAlive(bool alive)
{
  this->alive = alive;
}

void Player::updateMovementDirection()
{   
  char dir = joystick.getInput();

  /*
  if (dir == 'w') {
    posy = (posy - 2 + 16) % 16;
  } else if (dir == 's') {
    posy = (posy + 2) % 16;
  } else if (dir == 'a') {
    posx = (posx + 2) % 32;
  } else if (dir == 'd') {
    posx = (posx - 2 + 32) % 32;
  }
  */

  if (dir != '0') movementDirection = dir;
}

void Player::update()
{
  updateMovementDirection();
  unsigned long totalTime = Game::getTotalTime();
  if (totalTime - lastCooldown > movCooldown) {
    moved = false;
    lastCooldown = totalTime;
  }
}
