#include "Characters/Character.h"

Character::Character() :
movementDirection('0'),
collided(false),
lastCooldown(0)
{ 
}

Character::~Character()
{
}