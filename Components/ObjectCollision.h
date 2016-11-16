#pragma once

#include "Asteroid.h"
#include "PlayerShip.h"
#include "Weapon.h"


void PlayerAsteroidCollision(PlayerShip &player, Asteroid &as);

void AsteroidCollision(Asteroid &as1, Asteroid &as2);

void WeaponAsteroidCollision(Weapon &b, Asteroid &a);
