#pragma once
#include "Asteroid.h"
#include "PlayerShip.h"
#include "Weapon.h"
#include "Tractor.h"
#include "AsteroidRender.h"


void PlayerAsteroidCollision(PlayerShip &player, Asteroid &as);

void AsteroidCollision(Asteroid &as1, Asteroid &as2);

void WeaponAsteroidCollision(Weapon &b, Asteroid &a);

void TractorAsteroidCollision(Tractor &tractor, Asteroid &asteroid, PlayerShip & player);
