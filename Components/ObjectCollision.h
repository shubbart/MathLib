#pragma once
#include "Asteroid.h"
#include "PlayerShip.h"
#include "Weapon.h"
#include "Tractor.h"
#include "AsteroidRender.h"
#include "AI.h"
#include "AIWeapon.h"


void PlayerAsteroidCollision(PlayerShip &player, Asteroid &as);

void AsteroidCollision(Asteroid &as1, Asteroid &as2);

void WeaponAsteroidCollision(Weapon &b, Asteroid &a);

void TractorAsteroidCollision(Tractor &tractor, Asteroid &asteroid, PlayerShip & player);

void PlayerAICollision(PlayerShip &player, AI &ai);

void AIAsteroidCollision(AI &ai, Asteroid &asteroid);

void WeaponAsteroidCollision(AIWeapon &b, Asteroid &a);
